#pragma once
#include <iostream>

template <typename T>
struct Node
{
    T key;
    Node *next;
    Node *prev;
    Node() { next = prev = nullptr; }
    Node(const T &_key)
    {
        key = _key;
        next = prev = nullptr;
    }
};

template <typename T>
class List
{
private:
    Node<T> *head;
    Node<T> *tail;
    Node<T> *curr;
    Node<T> *Find_Node(const T &_key);
    Node<T> *Find_Node_pos(const int &pos);

    int count;

    bool Is_Empty() { return head == tail; }
    bool correct_pos(short pos) { return pos >= 0 && pos <= count; }

public:
    List()
    {
        head = tail = nullptr;
        count = 0;
    }
    List(const T &knot) { Add_Head(knot); }
    ~List() { Clear(); }

    void Add_Head(const T &knot);
    void Add_Tail(const T &knot);
    void Add_Node(const T &knot, const int &pos);

    void Remove_Head();
    void Remove_Tail();
    void Remove_Node(const T &knot, const int pos);

    void Show_on_Head() const;
    void Show_on_Tail() const;
    void Show_Node() const;

    void Clear();

    List &operator=(const List &obj);
    List &operator+(const List &obj);
};

template <typename T>
Node<T> *List<T>::Find_Node(const T &_key)
{
    curr = head;
    for (int i(0); i < count; i++)
    {
        if (curr->key == _key)
            return curr;
    }
    return nullptr;
}

template <typename T>
Node<T> *List<T>::Find_Node_pos(const int &pos)
{
    if (!correct_pos(pos))
        return nullptr;
    curr = head;
    for (int i = 0; i < inx; i++)
        curr = curr->next;
    return curr;
}

template <typename T>
void List<T>::Add_Head(const T &knot)
{
    Node<T> *temp = new Node<T>(knot);
    temp->next = head;
    if (!Is_Empty())
    {
        head->prev = temp;
        head = temp;
    }
    else
        head = tail = temp;
    count++;
    delete temp;
}

template <typename T>
void List<T>::Add_Tail(const T &knot)
{
    Node<T> *temp = new Node<T>(knot);
    temp->prev = tail;
    if (tail != nullptr)
        tail->next = temp;
    if (Is_Empty())
        head = tail = temp;
    else
        tail = temp;

    count++;
    delete temp;
}

template <typename T>
void List<T>::Add_Node(const T &knot, const int &pos)
{
    if (!correct_pos(pos))
        return;
    if (pos == count)
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
    count++;
    delete temp;
}

template <typename T>
void List<T>::Remove_Head()
{
    if (Is_Empty())
        return;
    Node<T> *temp = head;
    head = head->next;
    delete temp;
    count--;
}

template <typename T>
void List<T>::Remove_Tail()
{
}

template <typename T>
void List<T>::Remove_Node(const T &knot, const int pos)
{
    if (Is_Empty() || !correct_pos(pos))
        return;
    if (pos == 0)
    {
        Remove_Head();
        return;
    }
    if (pos == count - 1)
    {
        Remove_Tail();
        return;
    }
}