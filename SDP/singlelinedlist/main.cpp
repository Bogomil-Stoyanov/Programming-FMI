#include "ll.cpp"

int main(){
    LL<int> ll;

    ll.pushFront(3);
    ll.pushFront(1);
    ll.pushBack(4);
    ll.insertAfter(0,2);
    ll.insertAfter(3,5);
    ll.print();

    ll.popFront();
    ll.popBack();
    ll.removeAt(1);
    ll.print();

    LL<int>::Iterator current = ll.begin();
    while (current != ll.end())
    {
        std::cout << *current << " ";
        ++current;
    }
    std::cout << std::endl;

    ll.reverse();
    ll.print();

}