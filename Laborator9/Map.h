#include <iostream>
// prevents double declaration of any identifiers such as types, enums and static variables.
#ifndef MAP_H
#define MAP_H

template <typename K, typename V>
class Map {
	struct Element {
		K key;
		V value;
		int index;
	} *v;
	
	int index; //pozitia curenta; in final, nr total elemente
	int size;//dimens max a mapei
public:
	//?
	void Resize() 
	{
		if (size != 0)
		{
			Element* v = new Element[size * 2];
			memcpy(v, v, sizeof(Element) * size);
			v = v;
			size = size * 2;
			return;
		}
		v = new Element[1];
		size = 1;
		index = 0;
	} 

	Map()
	{
		v = new Element[1];
		size = 1;
		index = 0;
	}

	Element* begin() const { return &v[0]; }

	Element* end() const { return &v[this->index]; }

	//???
	V& operator [] (K key)
	{
		for (int i = 0; i < index; i++)
		{
			if (key == v[i].key)
				return v[i].value;
		}
		v[this->index].index = this->index;
		v[this->index].key = key;
		this->index++;
		if (this->index == size)
			Resize();
		return v[this->index - 1].value;
	}

	void Set(K key, V value) // SET
	{
		for (int i = 0; i < index; i++)
			if (v[i].key == key)
			{
				v[i].value = value;
				size++;
			}
	}

	bool Get(const K& key, V& value) //GET
	{
		for (int i = 0; i < index; i++)
			if (v[i].key == key)
			{
				value = v[i].value;
				return true;
			}
		return false;
	}

	int Count() const // COUNT
	{
		return index;
	}

	void Clear() //CLEAR
	{
		size = 0;
		index = 0;
		delete[] v;
	}

	bool Delete(const K& key) //DELETE
	{
		for (int i = 0; i < index; i++)
		{
			if (v[i].key == key)
			{
				for (int j = i; j < index - 1; j++)
					v[j] = v[j + 1];
				index--;
				return true;
			}
		}
		return false;
	}

	bool Includes(const Map<K, V>& map)	//INCLUDES
		/*
		checks if a map is included in another.
		A map A is included in another map B, if all keys from map A exists in map B
		*/
	{ //verif daca map e inclusa
		if (index < map.index) return false;
		bool ok;
		for (int i = 0; i < map.index; i++)
		{
			ok = false;
			for (int j = 0; j < index; j++)
				if (v[j].key == map.v[i].key)
				{
					ok = true;
					break;
				}
			if (ok == false)
				return false;
		}
		return true;
	}

};
/*
template<class K, class V>
bool Map<K, V>::Includes(const Map<K, V>& m) {
	int nr = 0;
	for (auto [indexA, keyA, valueA] : m) {
		for (auto [indexB, keyB, valueB] : *this) {
			if (keyA == keyB && valueA == valueB) {
				nr++;
			}
		}
	}
	return nr == m.Count();
}
*/

#endif