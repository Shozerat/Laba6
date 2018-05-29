#pragma once
#include <iostream>

using namespace std;

class Deque {
	int *arr;
	int count;
	int end = 0, size = 0;
public:
	Deque(int count); //инициализация
	Deque(const Deque &other); //копирование
	Deque(Deque &&other); //перемещение
	Deque &operator=(const Deque &other); //присвоение
	Deque &operator=(Deque &other); //присвоние с перемещением
	~Deque(); //деструктор
	int GetSize() const;
	void PushFront(int element); //добавление в начало
	void PushBack(int element); //добавление в конец
	int PopFront(); //удаление первого элемента
	int PopBack(); //удаление последнего элемента
	int PeekFront(); //просмотор первого элемента
	int PeekBack(); //просмотор последнего элемента
	bool CheckNotEmpty(); //проверка на наличие элементов
	friend ostream & operator<< (ostream & stream, const Deque &a); //вывод
};