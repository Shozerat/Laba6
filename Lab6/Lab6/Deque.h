#pragma once
#include <iostream>

using namespace std;

class Deque {
	int *arr;
	int count;
	int end = 0, size = 0;
public:
	Deque(int count); //�������������
	Deque(const Deque &other); //�����������
	Deque(Deque &&other); //�����������
	Deque &operator=(const Deque &other); //����������
	Deque &operator=(Deque &other); //��������� � ������������
	~Deque(); //����������
	int GetSize() const;
	void PushFront(int element); //���������� � ������
	void PushBack(int element); //���������� � �����
	int PopFront(); //�������� ������� ��������
	int PopBack(); //�������� ���������� ��������
	int PeekFront(); //��������� ������� ��������
	int PeekBack(); //��������� ���������� ��������
	bool CheckNotEmpty(); //�������� �� ������� ���������
	friend ostream & operator<< (ostream & stream, const Deque &a); //�����
};