#pragma once
#include <iostream>

using namespace std;
template<typename T>

Class DequeTemplate{
	T *arr;
int count;
int end = 0, size = 0;
public:
	DequeTemplate(int count); //инициализация
	DequeTemplate(const DequeTemplate &other); //копирование
	DequeTemplate(DequeTemplate &&other); //перемещение
	DequeTemplate &operator=(const DequeTemplate &other); //присвоение
	DequeTemplate &operator=(DequeTemplate &other); //присвоние с перемещением
	~DequeTemplate(); //деструктор
	int GetSize() const;
	void PushFront(T element); //добавление в начало
	void PushBack(int element); //добавление в конец
	T PopFront(); //удаление первого элемента
	T PopBack(); //удаление второго элемента
	T PeekFront(); //просмотор первого элемента
	T PeekBack(); //просмотор второго элемента
	bool CheckNotEmpty(); //проверка на наличие элементов
	friend ostream & operator<< (ostream & stream, const Deque &a); //вывод
};

template<typename <T>
	DequeTemplate<T>::DequeTemplate(int count)
		: count(count)
	{
		arr = new T[count];
	}

	template<typename T>
	DequeTemplate<T>::~DequeTemplate() {
		delete[] arr;
	}

	template<typename T>
	DequeTemplate<T>::DequeTemplate(const DequeTemplate &other) {
		arr = new T[other.count];
		count = other.count;
		end = other.end;
		size = other.size;
		for (int i = 0; i < count; ++i)
		{
			arr[i] = other.arr[i];
		}
	}


	template<typename T>
	DequeTemplate<T> &DequeTemplate<T>::operator=(const DequeTemplate &other) {
		if (this == &other) {
			return *this;
		}
		delete[] arr;
		arr = new T[other.count];
		count = other.count;
		for (int i = 0; i < count; ++i) {
			arr[i] = other.arr[i];
		}
	}


	template<typename T>
	DequeTemplate<T> &DequeTemplate<T>::operator=(DequeTemplate &&other)
	{
		if (this == &other)
		{
			return *this;
		}
		delete[] arr;
		arr = other.arr;
		count = other.count;
		other.arr = nullptr;
	}

	template<typename T>
	DequeTemplate<T>::DequeTemplate(DequeTemplate &&other) {
		arr = other.arr;
		count = other.count;
		other.arr = nullptr;
	}

	template<typename T>
	int DequeTemplate<T>::GetSize()
	{
		return this->size;
	}

	template<typename T>
	void DequeTemplate<T>::PushFront(T element) {
		for (int i = end; i > 0; i--) {
			arr[i] = arr[i - 1];
			arr[0] = element;
			end++;
			size++;
		}
	}

	template<typename T>
	void DequeTemplate<T>::PushBack(T element) {
		arr[end++] = element;
		end++;
		size++;
	}

	template<typename T>
	T DequeTemplate<T>::PopFront() {
		if (size > 0) {
			for (int i = 0; i < size; ++i) {
				arr[i] = arr[i + 1];
			}
			size--;
		}
	}

	template<typename T>
	T DequeTemplate::PopBack() {
		if (size > 0) {
			arr[end] = 0;
			size--;
		}
	}

	template<typename T>
	T DequeTemplate::PeekFront() {
		return arr[0];
	}

	template<typename T>
	T DequeTemplate::PeekBack() {
		return arr[end];
	}

	template<typename T>
	bool DequeTemplate<T>::CheckNotEmpty()
	{
		return (size > 0);
	}

	template<typename T>
	ostream & operator<< (ostream & stream, const DequeTemplate<T> &a) {
		DequeTemplate<T> b = a;
		for (int i = 0; i < b.count; i++) {
			stream << b.arr[i] << " ";
		}
		return stream;
	}
