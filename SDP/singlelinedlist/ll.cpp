#include "ll.h"
#include <iostream>

template <typename T>
LL<T>::LL() : head(nullptr), size(0)
{
}

template <typename T>
LL<T>::~LL() {
    clear();
}

template <typename T>
LL<T>::LL(const LL &&other)
{
    head = other.head;
    size = other.size;

    other.head = nullptr;
    other.size = 0;
}

template <typename T>
LL<T>::LL(const LL &other)
{
    clear();
    LL<int>::Iterator current = other.begin();
    while (current != other.end())
    {
        pushBack(*current);
        ++current;
    }
}

template <typename T>
void LL<T>::pushFront(const T &value)
{
    typename LL<T>::Node *newNode = new typename LL<T>::Node{value, head};
    head = newNode;
    size++;
}

template <typename T>
void LL<T>::pushBack(const T &value)
{
    typename LL<T>::Node *newNode = new typename LL<T>::Node{value, nullptr};
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    typename LL<T>::Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newNode;
    size++;
}

template <typename T>
void LL<T>::insertAfter(unsigned int index, const T &value)
{
    if (index > size)
        return;

    typename LL<T>::Node *current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }

    typename LL<T>::Node *newNode = new typename LL<T>::Node{value, current->next};
    current->next = newNode;
    size++;
}

template <typename T>
unsigned int LL<T>::getSize() const
{
    return size;
}

template <typename T>
void LL<T>::popFront()
{
    typename LL<T>::Node *save = head->next;
    delete head;
    head = save;
    size--;
}

template <typename T>
void LL<T>::popBack()
{
    typename LL<T>::Node *current = head;
    while (current->next->next != nullptr)
    {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
    size--;
}

template <typename T>
void LL<T>::removeAt(unsigned int index){

     if (index > size)
        return;

    typename LL<T>::Node *current = head;
    for(int i = 0;i<index-1;i++){
        current = current->next;
    }

    typename LL<T>::Node *forDeletion = current->next;
    current->next = forDeletion->next;
    delete forDeletion;
    size--;
}

template <typename T>
void LL<T>::clear(){
    while(size>0){
        popFront();
    }
}

template <typename T>
void LL<T>::print() const
{
    typename LL<T>::Node *current = head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}


template <typename T>
typename LL<T>::Iterator LL<T>::begin(){
    typename LL<T>::Iterator it(head);
    return it;
}

template <typename T>
typename LL<T>::Iterator LL<T>::end(){
    return nullptr;
}

template <typename T>
LL<T>::Iterator::Iterator(Node *ptr){
    current = ptr;
}

template <typename T>
T LL<T>::Iterator::operator*() const
{
    return current->data;
}

template <typename T>
typename LL<T>::Iterator &LL<T>::Iterator::operator++()
{
    current = current->next;
    return *this;
}

template <typename T>
bool LL<T>::Iterator::operator!=(const typename LL<T>::Iterator &other)
{
    return current != other.current;
}

template <typename T>
void LL<T>::reverse()
{
    typename LL<T>::Node *prev = nullptr;
    typename LL<T>::Node *curr = head;
    typename LL<T>::Node *next = nullptr;

    while(curr!=nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}