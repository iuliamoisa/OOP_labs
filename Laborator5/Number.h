#pragma once
class Number
{
public:
	Number(const char* value, int base);
	Number(const Number& number);
	Number(Number&& number);
	Number(int value);
	
	//~Number();

	void SwitchBase(int newBase);
	void Print();
	inline int GetDigitsCount() const { return m_size; } 
	inline int GetBase() const { return m_base; } 

	friend Number operator+(Number n1, Number n2);
	friend Number operator++(Number number);
	friend Number operator+=(Number A, Number B);
	friend Number operator-(Number n1, Number n2);
	friend Number operator--(Number number);
	friend Number operator--(Number number, int value);
	friend Number operator-=(Number A, Number B);
	Number operator=(Number&& other);
	Number operator=(int value);
	Number operator=(const char* value);
	char operator[](int index);
	bool operator>(Number other);
	bool operator<(Number other);
	bool operator>=(Number other);
	bool operator<=(Number other);
	bool operator==(Number other);
	bool operator!=(Number other);

public:
	static constexpr size_t MAX_NUMBER_SIZE = 50;
	void convertToBase(int base);
	int convertTo10();

private:
	char m_value[MAX_NUMBER_SIZE];
	size_t m_size;
	int m_base;
};

