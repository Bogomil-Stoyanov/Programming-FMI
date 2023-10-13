#include "dll.h"

template <typename T>
DLL<T>::DLL() : first(nullptr), last(nullptr), count(0)
{
}

template <typename T>
void DLL<T>::push_front(const T &x)
{
    typename DLL<T>::Node *newNode = new typename DLL<T>::Node{x, first, nullptr};

    if (first != nullptr)
    {
        first->prev = newNode;
    }
    else
    {
        last = newNode;
    }
    first = newNode;
    count++;
}

template <typename T>
void DLL<T>::push_back(const T &x)
{
    typename DLL<T>::Node *newNode = new typename DLL<T>::Node{x, nullptr, last};

    if (last != nullptr)
    {
        last->next = newNode;
    }
    else
    {
        first = newNode;
    }
    last = newNode;
    count++;
}

template <typename T>
unsigned int DLL<T>::size() const
{
    return count;
}

template <typename T>
bool DLL<T>::pop_front()
{
    if (first == nullptr)
    {
        return false;
    }

    typename DLL<T>::Node *save = first;
    if (first->next != nullptr)
    {
        first->next->prev = nullptr;
    }
    first = first->next;

    delete save;
    count--;
    return true;
}

template <typename T>
bool DLL<T>::pop_back()
{
    if (last == nullptr)
    {
        return false;
    }

    typename DLL<T>::Node *save = last;
    if (last->prev != nullptr)
    {
        last->prev->next = nullptr;
    }
    last = last->prev;
    delete save;
    count--;
    return true;
}

template <typename T>
typename DLL<T>::Iterator DLL<T>::begin()
{
    typename DLL<T>::Iterator it(first, &last);
    return it;
}
template <typename T>
typename DLL<T>::Iterator DLL<T>::end()
{
    typename DLL<T>::Iterator it(nullptr, &last);
    return it;
}

template <typename T>
DLL<T>::Iterator::Iterator(typename DLL<T>::Node *crr,
                           typename DLL<T>::Node *const *plast)
{
    current = crr;
    ptr_to_last = plast;
}

template <typename T>
T DLL<T>::Iterator::operator*() const
{
    return current->data;
}
template <typename T>
typename DLL<T>::Iterator &DLL<T>::Iterator::operator++()
{
    current = current->next;
    return *this;
}
template <typename T>
typename DLL<T>::Iterator &DLL<T>::Iterator::operator--()
{
    if (current == nullptr)
    {
        current = *ptr_to_last;
    }
    else
    {
        current = current->prev;
    }
    return *this;
}
template <typename T>
bool DLL<T>::Iterator::operator!=(const typename DLL<T>::Iterator &other)
{
    return current != other.current;
}

template <typename T>
DLL<T>::DLL(const DLL &other)
{
    clear();
    DLL<int>::Iterator current = other.begin();
    while (current != other.end())
    {
        push_back(*current);
        ++current;
    }
}

template <typename T>
DLL<T>::DLL(const DLL &&other)
{
    first = other.first;
    last = other.last;
    count = other.count;

    other.first = nullptr;
    other.last = nullptr;
    other.count = 0;
}

template <typename T>
void DLL<T>::clear()
{
    while (count > 0)
    {
        pop_back();
    }
}

template <typename T>
DLL<T>::~DLL()
{
    clear();
}

template <typename T>
void DLL<T>::remove(const typename DLL<T>::Iterator &it)
{
    if (it == end())
    {
        return;
    }

    Node *nodeToRemove = *it;

    if (nodeToRemove == first)
    {
        first = first->next;
        if (first != nullptr)
        {
            first->prev = nullptr;
        }
        else
        {
            last = nullptr;
        }
    }
    else if (nodeToRemove == last)
    {
        last = last->prev;
        if (last != nullptr)
        {
            last->next = nullptr;
        }
        else
        {
            first = nullptr;
        }
    }
    else
    {
        nodeToRemove->prev->next = nodeToRemove->next;
        nodeToRemove->next->prev = nodeToRemove->prev;
    }

    delete nodeToRemove;
    count--;
}


template <typename T>
void DLL<T>::reverse()
{
   
    if (first == nullptr || first == last) {
        return;
    }

    typename DLL<T>::Node* temp = nullptr;
    typename DLL<T>::Node* current = first;

    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; 
    }

    temp = first;
    first = last;
    last = temp;
}