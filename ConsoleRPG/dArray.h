#pragma once

template<typename T>
class dArray
{
private:
	unsigned cap;
	unsigned initialCap;
	unsigned numberOfElements;
	T* *array;

	void expand();
	void initialize(unsigned from);
public:
	dArray(unsigned size = 5);
	dArray(const dArray& object);
	~dArray();

	T& operator[] (const unsigned index);
	void operator = (const dArray& object);

	unsigned maxCap();
	unsigned size();

	void push(const T element);
	void remove(const unsigned index, bool ordered = false);
};

template<typename T>
dArray<T>::dArray(unsigned size)
{
	this->initialCap = size;
	this->cap = size;
	this->numberOfElements = 0;

	this->array = new T * [this->cap];

	this->initialize(0);
}

template<typename T>
dArray<T>::dArray(const dArray& object)
{
	this->initialCap = object.initialCap;
	this->cap = object.cap;
	this->numberOfElements = object.numberOfElements;

	this->array = new T * [this->cap];

	for (size_t i = 0; i < this->numberOfElements; i++)
	{
		this->array[i] = new T(*object.array[i]);
	}

	this->initialize(0);
}


template<typename T>
dArray<T>::~dArray()
{
	for (size_t i = 0; i < this->numberOfElements; i++)
	{
		delete this->array[i];
	}
	delete[] array;
}

template<typename T>
T& dArray<T>::operator[] (const unsigned index)
{
	if (index < 0 || index >= this->numberOfElements)
		throw "Out of bounds indexing operator.";

	return *this->array[index];
}

template<typename T>
void dArray<T>::operator= (const dArray& object)
{
	for (size_t i = 0; i < this->numberOfElements; i++)
	{
		delete this->array[i];
	}
	delete[] array;

	this->initialCap = object.initialCap;
	this->cap = object.cap;
	this->numberOfElements = object.numberOfElements;

	this->array = new T * [this->cap];

	for (size_t i = 0; i < this->numberOfElements; i++)
	{
		this->array[i] = new T(*object.array[i]);
	}

	this->initialize(0);
}

template<typename T>
void dArray<T>::expand()
{
	this->cap *= 2;

	T** tempArray = new T * [this->cap];

	for (size_t i = 0; i < this->numberOfElements; i++)
	{
		tempArray[i] = this->array[i];
	}

	delete[]array;

	this->array = tempArray;

	this->initialize(this->numberOfElements);
}

template<typename T>
void dArray<T>::initialize(unsigned from)
{
	for (size_t i = from; i < this->cap; i++)
	{
		this->array[i] = nullptr;
	}
}

template<typename T>
unsigned dArray<T>::maxCap()
{
	return this->cap;
}

template<typename T>
unsigned dArray<T>::size()
{
	return this->numberOfElements;
}

template<typename T>
void dArray<T>::push(const T element)
{
	if (this->numberOfElements >= this->cap)
	{
		this->expand();
	}
	
	this->array[this->numberOfElements++] = new T(element);
	
}

template<typename T>
void dArray<T>::remove(const unsigned index, bool ordered)
{
	if (index < 0 || index >= this->numberOfElements)
	{
		throw"Out of bounds remove.";
	}
	if (ordered)
	{
		delete this->array[index];

		for(size_t i = 0; i < this->numberOfElements; i++)
		{
			this->array[i] = this->array[i + 1];
		}

		this->array[--this->numberOfElements] = nullptr;
	}
	else
	{
		delete this->array[index];

		this->array[index] = this->array[this->numberOfElements - 1];

		this->array[--this->numberOfElements] = nullptr;
	}
}