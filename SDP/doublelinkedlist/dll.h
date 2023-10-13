#pragma once

template <typename T>
class DLL
{
public:
    DLL();
    DLL(const DLL &);
    DLL(const DLL &&);
    ~DLL();

    void push_front(const T &);
    void push_back(const T &);
    unsigned int size() const;

    bool pop_back();
    bool pop_front();

    void reverse();

private:
    struct Node
    {
        T data;
        Node *next, *prev;
    };

    Node *first, *last;
    unsigned count;

public:
    class Iterator
    {
    public:
        Iterator(Node *ptr, Node *const *);

        T operator*() const;
        Iterator &operator++();
        Iterator &operator--();
        bool operator!=(const Iterator &);

    private:
        Node *current;
        Node *const *ptr_to_last;
    };

    Iterator begin();
    Iterator end();

    void remove(const Iterator &);
    void clear();
};