#pragma once
#include <iostream>

template <typename T>
struct Node
{
    T key;
    Node *next;
    Node *prev;
    Node() { next = prev = nullptr; }
};

template <typename T>
class List
{
private:
    Node<T> *head;
    Node<T> *tail;
    Node<T> *curr;
    Node<T> *Find_Node();
    Node<T> *Find_Node_pos(const int pos);

    bool Is_Empty() { return head == nullptr; }

public:
    List() { head = tail = curr = nullptr; }
    List(const T &knot) { Add_Head(const T &knot); }
    ~List();

    void Add_Head(const T &knot);
    void Add_Tail(const T &knot);
    void Add_Node(const T &knot, const int pos);

    void Remove_Head(const T &knot);
    void Remove_Tail(const T &knot);
    void Remove_Node(const T &knot, const int pos);

    void Show_on_Head() const;
    void Show_on_Tail() const;
    void Show_Node() const;

    void Clear();

    List &opeartor = (const T key);
};
