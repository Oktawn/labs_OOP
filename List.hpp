#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>

template <typename T>
struct Node
{
    T key;
    Node<T> *next;
    Node<T> *prev;
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
    int count;
    Node<T> *head;
    Node<T> *tail;
    Node<T> *curr;

    Node<T> *Find_Node_pos(const int &pos);

    void Copy(const List<T> &obj);

    bool correct_pos(const int &pos)
    {
        return pos >= 0 && pos <= count;
    }

public:
    List()
    {
        head = tail = curr = nullptr;
        count = 0;
    }
    List(const List &obj) { Copy(obj); }
    List(const T &obj) { Add_Head(obj); }
    List(const T *arr, const int &len)
    {
        for (int i(0); i < len; i++)
            Add_Tail(*(arr + i));
    }
    ~List() { Clear(); }

    bool Is_Empty() { return head == nullptr; }

    void Add_Head(const T &knot);
    void Add_Tail(const T &knot);
    void Add_Node(const T &knot, const int &pos);

    void Remove_Head();
    void Remove_Tail();
    void Remove_Node(const int &pos);

    void Show_on_Head() const;
    void Show_on_Tail() const;
    void Show_Node(const int &pos) const;

    void Clear();
    Node<T> *Find_Node(const T &_key);
    List<T> &operator=(const List<T> &obj);
    List<T> &operator+(const List<T> &obj);
    T &operator[](const int &pos);

    T Next()
    {
        if (curr->next)
            curr = curr->next;
        return curr;
    }

    T Pred()
    {
        if (curr->prev)
            curr = curr->prev;
        return curr;
    }
    T Curr()
    {
        return curr->key;
    }
};

template <typename T>
Node<T> *List<T>::Find_Node(const T &_key)
{
    curr = head;
    while (curr)
    {
        if (Curr() == _key)
            return curr;
        Next();
    }
    return nullptr;
}

template <typename T>
Node<T> *List<T>::Find_Node_pos(const int &pos)
{
    if (!correct_pos(pos))
        return nullptr;
    curr = head;
    for (int i = 0; i < pos; i++)
        Next();
    return curr;
}

template <typename T>
void List<T>::Copy(const List<T> &obj)
{
    Clear();
    Node<T> *temp = obj.head;
    while (temp)
    {
        Add_Tail(temp->key);
        temp = temp->next;
    }
}

template <typename T>
void List<T>::Add_Head(const T &knot)
{
    Node<T> *temp = new Node<T>(knot);

    if (!Is_Empty())
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    else
        head = tail = temp;

    count++;
}

template <typename T>
void List<T>::Add_Tail(const T &knot)
{
    if (Is_Empty())
    {
        Add_Head(knot);
        return;
    }
    else
    {
        Node<T> *temp = new Node<T>(knot);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }

    count++;
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
    if (Is_Empty())
        return;
    Node<T> *temp = tail;
    tail = tail->prev;
    delete temp;
    count--;
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
    if (pos == count - 1)
    {
        Remove_Tail();
        return;
    }
    Node<T> *temp_prev = Find_Node_pos(pos);
    Node<T> *temp_next = temp_prev->next->next;
    delete temp_prev->next;
    temp_next->prev = temp_prev;
    temp_prev->next = temp_next;
}

template <typename T>
void List<T>::Show_on_Head() const
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
void List<T>::Show_on_Tail() const
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
void List<T>::Show_Node(const int &pos) const
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

template <typename T>
List<T> &List<T>::operator+(const List<T> &obj)
{
    Node<T> *temp = obj;
    while (temp)
    {
        Add_Tail(temp);
        temp = temp->next;
    }
    return *this;
}

template <typename T>
T &List<T>::operator[](const int &pos)
{
    if (correct_pos(pos))
        return Find_Node_pos(pos)->key;
    return errno;
}

#endif