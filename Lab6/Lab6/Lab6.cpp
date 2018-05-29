#include "Deque.h"

Deque::Deque(int count)
	: count(count)
{
	arr = new int[count];
}

Deque::Deque(const Deque &other) {
	arr = new int[other.count];
	count = other.count;
	end = other.end;
	for (int i = 0; i < count; ++i) {
		arr[i] = other.arr[i];
	}
}

Deque::Deque(Deque &&other) {
	arr = other.arr;
	count = other.count;
	other.arr = nullptr;
}

Deque::~Deque() {
	delete[] arr;
}

Deque &Deque::operator=(const Deque &other) {
	if (this == &other) {
		return *this;
	}
	delete[] arr;
	arr = new int[other.count];
	count = other.count;
	for (int i = 0; i < count; ++i) {
		arr[i] = other.arr[i];
	}
}

Deque &Deque::operator=(Deque &other) {
	if (this == &other)
	{
		return *this;
	}
	delete[] arr;
	arr = other.arr;
	count = other.count;
	other.arr = nullptr;
}

int Deque::GetSize() const {
	return this->size;
}

void Deque::PushFront(int element) {
	for (int i = end; i > 0; i--) {
		arr[i] = arr[i - 1];
		arr[0] = element;
		end++;
		size++;
	}
}

void Deque::PushBack(int element) {
	arr[end++] = element;
	end++;
	size++;
}

int Deque::PopFront() {
	if (size > 0) {
		for (int i = 0; i < size; ++i) {
			arr[i] = arr[i + 1];
		}
		size--;
	}
}

int Deque::PopBack() {
	if (size > 0) {
		arr[end] = 0;
		size--;
	}
}

int Deque::PeekFront() {
	return arr[0];
}

int Deque::PeekBack() {
	return arr[end];
}

bool Deque::CheckNotEmpty() {
	return (size > 0);
}

ostream & operator<< (ostream & stream, const Deque &a) {
	Deque b = a;
	for (int i = 0; i < b.count; i++) {
		stream << b.arr[i] << " ";
	}
	return stream;
}
