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

	T get_front();
	T get_back();

	void show_all();

	void clear();
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

template<typename T>
T Deque<T>::get_front()
{
	return T(List<T>::Get_head());
}

template<typename T>
T Deque<T>::get_back()
{
	return T(List<T>::Get_tail());
}

template <typename T>
void Deque<T>::show_all()
{
	List<T>::Show_on_Head();
}

template<typename T>
void Deque<T>::clear()
{
	List<T>::Clear();
}
