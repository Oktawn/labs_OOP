#pragma once
#include"List.hpp"

template <typename T>
class Stack : protected List<T>
{
public:
	T get_front();

	bool is_empty();

	void push(T knot);
	void pop();

	void show_all();
};

template<typename T>
  T Stack<T>::get_front()
{
	return T(List<T>::Get_head());
}

template<typename T>
  bool Stack<T>::is_empty()
{
	return List<T>::Is_Empty();
}

template<typename T>
  void Stack<T>::push(T knot)
{
	List<T>::Add_Head(knot);
}

template<typename T>
  void Stack<T>::pop()
{
	List<T>::Remove_Head();
}

template<typename T>
  void Stack<T>::show_all()
{
	List<T>::Show_on_Head();
}
