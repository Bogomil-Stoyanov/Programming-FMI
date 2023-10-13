#include <iostream>
#include "dll.cpp"


int main(){
 DLL<int> l;

    l.push_back(0);
    l.push_back(1);
    l.push_back(2);

    // DLL<int>::Iterator current = l.begin();
    // while (current != l.end())
    // {
    //     std::cout << *current << " ";
    //     ++current;
    // }
    // std::cout << std::endl;

    // current = l.end();

    // if (current != l.begin())
    // {
    //     do
    //     {
    //         --current;
    //         std::cout << *current << " ";
    //     }while(current != l.begin());
    // }

    l.reverse();
    DLL<int>::Iterator current = l.begin();
    while (current != l.end())
    {
        std::cout << *current << " ";
        ++current;
    }
    std::cout << std::endl;

}