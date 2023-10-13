#pragma once

template <typename T>
class LL
{
public:
    LL();
    LL(const LL &);
    LL(const LL &&);
    ~LL();

    void pushFront(const T &);
    void pushBack(const T &);
    void insertAfter(unsigned int index, const T &);

    unsigned int getSize() const;

    void popFront();
    void popBack();
    void removeAt(unsigned int index);

    void clear();
    void print() const;

    void reverse();

    void reverseIterative();
    void reverseRecursive();

private:
    struct Node
    {
        T data;
        Node *next;
    };

    unsigned int size;
    Node *head;

public:
    class Iterator
    {
    public:
        Iterator(Node *ptr);

        T operator*() const;
        Iterator &operator++();
        bool operator!=(const Iterator &);

    private:
        Node *current;
    };

    Iterator begin();
    Iterator end();
};