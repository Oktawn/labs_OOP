#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
#include <vector>

template <typename T>
struct Node
{
	T key;
	Node *next;
	Node *prev;
	Node() { next = prev = nullptr; }
	Node(T _key)
	{
		this->key = _key;
		next = prev = nullptr;
	}
};

template <typename T>
class List
{
private:
	int size;
	Node<T> *head;
	Node<T> *tail;
	Node<T> *curr;

	Node<T> *Find_Node_pos(const int &pos);

	void Copy(const List<T> &obj);

	bool correct_pos(const int &pos)
	{
		return (pos >= 0) && (pos < size);
	}
	bool Is_Empty() { return head == nullptr; }

public:
	List()
	{
		head = tail = curr = nullptr;
		size = 0;
	}
	List(T obj) { Add_Head(obj); };
	~List() { Clear(); }
	// List(List& obj) { Copy(obj); }
	// List(T* arr, int& len)
	//{
	//	for (int i(0); i < len; i++)
	//		Add_Tail(*(arr + i));
	// }

	void Add_Head(T knot);
	void Add_Tail(T knot);
	void Add_Node(T knot, const int &pos);

	void Remove_Head();
	void Remove_Tail();
	void Remove_Node(const int &pos);

	void Show_on_Head();
	void Show_on_Tail();
	void Show_Node(const int &pos);

	void Clear();

	Node<T> *Find_Node(const T &_key);
	List<T> &operator=(const List<T> &obj);
	// List<T>& operator+(List<T>& obj);
	T operator[](const int &pos);

	T Next() { return curr->next->key; }
	T Pred() { return curr->pred->key; }
	T Curr() { return curr->key; }
};

template <typename T>
Node<T> *List<T>::Find_Node(const T &_key)
{
	curr = head;
	while (curr)
	{
		if (curr->key == _key)
			return curr;
		Next();
	}
	return nullptr;
}

template <typename T>
Node<T> *List<T>::Find_Node_pos(const int &pos)
{
	curr = head;
	for (int i = 0; i < pos; i++)
		curr = curr->next;
	return curr;
}

template <typename T>
void List<T>::Copy(const List<T> &obj)
{
	Clear();
	Node<T> *temp = obj.head;
	while (temp != nullptr)
	{
		Add_Tail(temp->key);
		temp = temp->next;
	}
}

template <typename T>
void List<T>::Add_Head(T knot)
{
	try
	{
		Node<T> *temp = new Node<T>(knot);
		if (head == nullptr)
		{
			head = temp;
			tail = temp;
			tail->next = nullptr;
		}
		else
		{
			head->prev = temp;
			temp->next = head;
			head = temp;
			head->prev = nullptr;
		}
		size++;
		curr = head;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

template <typename T>
void List<T>::Add_Tail(T knot)
{
	try
	{
		if (Is_Empty())
		{
			Add_Head(knot);
			return;
		}
		else
		{
			Node<T> *temp = new Node<T>(knot);
			tail->next = temp;
		}
		curr = tail;
		size++;
	}
	catch (std::bad_alloc &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

template <typename T>
void List<T>::Add_Node(T knot, const int &pos)
{
	if (!correct_pos(pos))
		return;
	if (pos == size - 1)
	{
		Add_Tail(knot);
		return;
	}
	if (Is_Empty())
	{
		Add_Head(knot);
		return;
	}
	Node<T> *temp = new Node<T>(knot);
	temp->prev = Find_Node_pos(pos - 1);
	temp->next = Find_Node_pos(pos);
	Find_Node_pos(pos - 1)->next = temp;
	Find_Node_pos(pos)->prev = temp;
	size++;
}

template <typename T>
void List<T>::Remove_Head()
{
	Node<T> *temp = head;
	head = head->next;
	delete temp;
	size--;
}

template <typename T>
void List<T>::Remove_Tail()
{

	Node<T> *temp = tail;
	tail = temp->prev;
	tail->next = nullptr;
	delete temp;
	size--;
}

template <typename T>
void List<T>::Remove_Node(const int &pos)
{
	if (Is_Empty() || !correct_pos(pos))
		return;
	if (pos == 0)
	{
		Remove_Head();
		return;
	}
	if (pos == size - 1)
	{
		Remove_Tail();
		return;
	}
	Node<T> *temp = Find_Node_pos(pos);
	temp->next->prev = temp->next;
	temp->prev->next = temp->prev;
	delete temp;
}

template <typename T>
void List<T>::Show_on_Head()
{
	Node<T> *temp = head;
	while (temp)
	{
		std::cout << temp->key << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

template <typename T>
void List<T>::Show_on_Tail()
{
	Node<T> *temp = tail;
	while (temp)
	{
		std::cout << temp->key << " ";
		temp = temp->prev;
	}
	std::cout << std::endl;
}

template <typename T>
void List<T>::Show_Node(const int &pos)
{
	std::cout << Find_Node_pos(pos)->key << std::endl;
}

template <typename T>
void List<T>::Clear()
{
	while (!Is_Empty())
		Remove_Head();
}

template <typename T>
List<T> &List<T>::operator=(const List<T> &obj)
{
	Copy(obj);
	return *this;
}

// template <typename T>
// List<T>& List<T>::operator+(List<T>& obj)
//{
//	Node<T>* temp = obj;
//	while (temp)
//	{
//		Add_Tail(temp);
//		temp = temp->next;
//	}
//	return *this;
// }

template <typename T>
T List<T>::operator[](const int &pos)
{
	if (correct_pos(pos))
		return Find_Node_pos(pos)->key;
}
#endif