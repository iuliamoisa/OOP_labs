#include "Number.h"
#include <cstring>
#include <iostream>

char convertToChar(int num)
{
	if (num >= 0 and num <= 9)
		return '0' + num;
	return 'A' + num - 10;
}

int convertToInt(char c) {
	if (isdigit(c))
		return c - '0';
	return c - 'A' + 10;
}

Number::Number(const char* value, int base) {
	m_base = base;
	strcpy_s(m_value, value);
	m_size = strlen(m_value);
}

Number::Number(const Number& number) {
	strcpy_s(m_value, number.m_value);
	m_size = number.m_size;
	m_base = number.m_base;
}

Number::Number(Number&& number) {
	strcpy_s(m_value, number.m_value);
	m_size = number.m_size;
	m_base = number.m_base;
}

Number::Number(int value) {
	m_base = 10;
	m_size = 0;
	while (value > 0) {
		m_value[m_size++] = value % 10 + '0';
		value /= 10;
	}
	m_value[m_size] = '\0';
	_strrev(m_value);
}

void Number::SwitchBase(int base) {
	convertTo10();
	convertToBase(base);
}

void Number::Print() {
	std::cout << "base " << m_base << ": ";
	for (size_t i = 0; i < m_size; ++i) {
		std::cout << m_value[i];
	}
	std::cout << "\n";
}

Number operator+(Number n1, Number n2) {
	int base = n1.GetBase();
	if (n1.GetBase() < n2.GetBase()) {
		base = n2.GetBase();
	}

	int A = n1.convertTo10();
	int B = n2.convertTo10();
	int sum = A + B;
	char toString[Number::MAX_NUMBER_SIZE];
	int index = 0;
	while (sum > 0) {
		toString[index++] = sum % 10 + '0';
		sum /= 10;
	}
	toString[index] = '\0';
	return Number(toString, 10);
}

Number operator++(Number number) {
	return number + Number("1", number.GetBase());
}

Number operator+=(Number n1, Number n2) {
	return n1+n2;
}

Number operator-(Number n1, Number n2) {
	int base = n1.GetBase();
	if (n1.GetBase() < n2.GetBase()) {
		base = n2.GetBase();
	}

	int A = n1.convertTo10();
	int B = n2.convertTo10();
	int diff = A - B;
	char toString[Number::MAX_NUMBER_SIZE];
	int index = 0;
	while (diff > 0) {
		toString[index++] = diff % 10 + '0';
		diff /= 10;
	}
	toString[index] = '\0';
	Number(toString, 10);
	return Number(toString, 10);
}

Number operator--(Number number) {
	return number - Number("1", number.GetBase());
}

Number operator--(Number number, int value) {
	return number - Number("1", number.GetBase());
}

Number operator-=(Number n1, Number n2) {
	return n1 - n2;
}

Number Number::operator=(Number&& other) {
	strcpy_s(m_value, other.m_value);
	m_size = other.m_size;
	m_base = other.m_base;
}

Number Number::operator=(int value) {
	m_size = 0;
	m_base = 10;
	while (value > 0) {
		m_value[m_size++] = value % 10 + '0';
	}
	m_value[m_size] = '\0';
	_strrev(m_value);
	return *this;
}

Number Number::operator=(const char* value) {
	return *this = Number(value, 10);
}

char Number::operator[](int index) {
	if (index >= m_size) {
		return 0;
	}
	return m_value[index];
}

bool Number::operator>(Number other) {
	other.SwitchBase(m_base);
	other.SwitchBase(m_base);
	if (m_size > other.m_size) {
		return true;
	}
	if (m_size < other.m_size) {
		return false;
	}

	for (size_t i = 0; i < m_size; ++i) {
		if (isdigit(m_value[i]) + isdigit(other.m_value[i]) % 2 == 0) {
			if (m_value[i] > other.m_value[i]) {
				return true;
			}
			if (m_value[i] < other.m_value[i]) {
				return false;
			}
		}
		else {
			return !isdigit(m_value[i]);
		}
	}
	return false;
}

bool Number::operator>=(Number other) {
	other.SwitchBase(m_base);
	if (*this > other or *this == other) {
		return true;
	}
	return false;
}

bool Number::operator<(Number other) {
	other.SwitchBase(m_base);
	if (!(*this >= other)) {
		return true;
	}
	return false;
}

bool Number::operator<=(Number other) {
	other.SwitchBase(m_base);
	if (!(*this > other)) {
		return true;
	}
	return false;
}

bool Number::operator==(Number other) {
	other.SwitchBase(m_base);
	for (size_t i = 0; i < m_size; ++i) {
		if (m_value[i] != other.m_value[i]) {
			return false;
		}
	}
	return true;
}

bool Number::operator!=(Number other) {
	return !(*this == other);
}

void Number::convertToBase(int base) {
	if (m_base == base) {
		return;
	}

	char tmp[MAX_NUMBER_SIZE];
	strcpy_s(tmp, m_value);
	m_base = base;

	int val = 0;
	for (int i = 0; i < m_size; ++i) {
		val = val * 10 + tmp[i] - '0';
	}

	m_size = 0;
	while (val > 0) {
		m_value[m_size++] = convertToChar(val % base);
		val /= m_base;
	}
	m_value[m_size] = '\0';
	_strrev(m_value);
}

int Number::convertTo10() {
	if (m_base == 10) {
		return -1;
	}

	int res = 0;
	int power = 1;
	for (int i = m_size - 1; i >= 0; --i) {
		if (convertToInt(m_value[i]) >= m_base) {
			throw "Invalid number (Base is too small)";
		}
		res += convertToInt(m_value[i]) * power;
		power *= m_base;
	}

	int ans = res;
	m_base = 10;
	m_size = 0;
	while (res > 0) {
		m_value[m_size++] = (res % 10) + '0';
		res /= 10;
	}
	m_value[m_size] = '\0';
	_strrev(m_value);
	return ans;
}