#pragma once

#include <iostream>

template <typename T>
struct Node
{
	Node<T>* next;
	T value;
	Node<T>* prev;

	Node(T value = -1, Node* next = nullptr, Node* prev = nullptr) : next(next), prev(prev), value(value) {};
};

template <typename T>
class List
{
private:
	Node<T>* begin;
	Node<T>* end;
	int size;

public:
	List()
	{
		begin = new Node<T>();
		end = begin;
		size = 0;
	}
	/*
	List(const List& other)
	{
		this->begin = new Node<T>();
		this->end = begin;
		this->size = 0;
		for (Node<T>* ptr = other.begin; ptr != other.end; ptr = ptr->next)
			this->PushBack(ptr->value);
	}*/
	/*
	~List()
	{
		if (size != 0)
		{
			for (Node<T>* sup = begin->next; sup != end; sup = sup->next)
				delete sup->prev;
			
		}
		delete end->prev;
		delete end;
	}*/

	void Clear()
	{
		if (size != 0)
		{
			for (Node<T>* sup = begin->next; sup != end; sup = sup->next)
				delete sup->prev;

			delete end->prev;
			begin = end;
			size = 0;
		}

	}

	List<T> Copy()
	{
		List<T> copy;
		for (Node<T>* ptr = begin; ptr != end; ptr = ptr->next)
			copy.PushBack(ptr->value);

		return copy;
	}

	void PushFront(T value)
	{
		Node<T>* sup = new Node<T>(value, begin, nullptr);
		begin->prev = sup;
		begin = sup;
		size++;
	}

	void PushBack(T value)
	{
		if (size != 0)
		{
			Node<T>* sup = new Node<T>(value, end, end->prev);
			end->prev->next = sup;
			end->prev = sup;
			size++;
		}
		else
		{
			PushFront(value);
		}
	}
	
	void PopFront()
	{
		if (size != 0)
		{
			Node<T>* sup = begin;
			begin = begin->next;
			begin->prev = nullptr;
			delete sup;
			size--;
		}
	}

	void PopBack()
	{
		if (size != 0)
		{
			Node<T>* sup = end->prev;
			end->prev = end->prev->prev;
			end->prev->prev->next = end;
			delete sup;
			size--;
		}
	}

	Node<T>* Erase(Node<T>* ptr)
	{
		
		if (size >= 1)
		{
			if (ptr == begin)
			{
				PopFront();
				return begin;
			}
			if (ptr == end)
			{
				PopBack();
				return end;
			}
			else
			{
				ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
				Node<T>* sup = ptr->next;
				delete ptr;

				return sup;
			}
		}
		else
		{
			PopFront();
			return begin;
		}
		size--;
	}

	Node<T>* Begin()
	{
		return begin;
	}
	Node<T>* End()
	{
		return end;
	}

	int Size()
	{
		return size;
	}
};

template<typename T>
std::ostream& operator<<(std::ostream& os, List<T>& list)
{
	for (Node<T>* b = list.Begin(); b != list.End(); b = b->next)
		os << b->value << ' ';
	os << '\n';
	return os;
};


template<typename T>
void PrintReverse(List<T> list)
{
	if (list.Size() != 0)
	{
		Node<T>* ptr = list.End();
		ptr = ptr->prev;
		for (; ptr != list.Begin(); ptr = ptr->prev)
			std::cout << ptr->value << ' ';
		std::cout << list.Begin()->value << '\n';
	}
	else
		std::cout << "{}\n";
}

template<typename T>
void Reverse(List<T>& list)
{
	if (list.Size() <= 1)
		return;

	Node<T>* ptr1 = list.Begin();
	Node<T>* ptr2 = list.End();
	ptr2 = ptr2->prev;
	
	for (int i = 0; i < list.Size() / 2; i++)
	{
		T sup = ptr1->value;
		ptr1->value = ptr2->value;
		ptr2->value = sup;

		ptr1 = ptr1->next;
		ptr2 = ptr2->prev;
	}
}