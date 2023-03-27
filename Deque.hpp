#pragma once
#include "List.hpp"

template <typename T>
class Deque : private List<T>
{

public:

	bool is_empty();
	void push_front(T knot);
	void push_back(T knot);
	void pop_back();
	void pop_front();
	void show_all();
};



template <typename T>
bool Deque<T>::is_empty()
{
	return List<T>::Is_Empty();
}

template <typename T>
void Deque<T>::push_front(T knot)
{
	List<T>::Add_Head(knot);
}

template <typename T>
void Deque<T>::push_back(T knot)
{
	List<T>::Add_Tail(knot);
}

template <typename T>
void Deque<T>::pop_back()
{
	if (is_empty())
		return;
	List<T>::Remove_Tail();
}

template <typename T>
void Deque<T>::pop_front()
{
	if (is_empty())
		return;
	List<T>::Remove_Head();
}

template <typename T>
void Deque<T>::show_all()
{
	List<T>::Show_on_Head();
}
