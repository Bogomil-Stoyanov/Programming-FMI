#include <iostream>

struct SingleNode{
    int data;
    SingleNode* next;
};

void addToFrontSingleNode(SingleNode* &head, int newValue) {
   
    SingleNode* newNode = new SingleNode;
    newNode->data = newValue;
    newNode->next = head;
    head = newNode;
}

void addToBackSingleNode(SingleNode* &head, int newValue) {
    std::cout<<"adding to back " << newValue<< std::endl;
    if(head==nullptr){
        addToFrontSingleNode(head, newValue);
        return;
    }
    SingleNode* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    SingleNode* newNode = new SingleNode;
    newNode->data = newValue;
    temp->next = newNode;
}

void printSingle(SingleNode* head){
    SingleNode* temp = head;

    while(temp!=nullptr){
        std::cout<< temp->data<<" ";
        temp = temp->next;
    }

    std::cout<<std::endl;
}

SingleNode* mergeTwoSortedSinleLLs(SingleNode* &l1, SingleNode* l2){
    SingleNode* temp1 = l1;
    SingleNode* temp2 = l2;

    SingleNode* result = nullptr;

    while(temp1!=nullptr && temp2!=nullptr){
        if(temp1->data < temp2->data){
            addToBackSingleNode(result,temp2->data);
            temp2 = temp2->next;
        }else{
            addToBackSingleNode(result,temp1->data);
            temp1 = temp1->next;
        }
    }

    while(temp1!=nullptr){
         addToBackSingleNode(result,temp1->data);
         temp1 = temp1->next;
    }

     while(temp2!=nullptr){
        addToBackSingleNode(result,temp2->data);
        temp2 = temp2->next;
    }

    return result;
}

// =================================

struct DoubleNode {
    int data;
    DoubleNode* prev;
    DoubleNode* next;
};

void reverseDoublyLinkedList(DoubleNode* &head) {
    DoubleNode* current = head;
    DoubleNode* temp = nullptr;

    while (current != nullptr) {
        // Swap the 'prev' and 'next' pointers of the current node
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node
        current = current->prev; // Since we swapped 'prev' and 'next'
    }

    // Update the head to the last node (original head)
    if (temp != nullptr) {
        head = temp->prev;
    }
}

void printDoublyLinkedList(DoubleNode* head) {
    DoubleNode* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    DoubleNode* head = nullptr;
    
    // Create a sample doubly linked list
    for (int i = 1; i <= 5; i++) {
        DoubleNode* newNode = new DoubleNode;
        newNode->data = i;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }

    std::cout << "Original Doubly Linked List: ";
    printDoublyLinkedList(head);

    reverseDoublyLinkedList(head);

    std::cout << "Reversed Doubly Linked List: ";
    printDoublyLinkedList(head);

    // Clean up: Free memory
    while (head != nullptr) {
        DoubleNode* temp = head;
        head = head->next;
        delete temp;
    }

    std::cout<<"=========================" << std::endl;
    
    SingleNode *node1 = nullptr;
    addToBackSingleNode(node1,1);
    addToBackSingleNode(node1,3);
    addToBackSingleNode(node1,5);
    addToBackSingleNode(node1,7);
    addToBackSingleNode(node1,9);
    addToBackSingleNode(node1,11);
    printSingle(node1);
    SingleNode *node2 = nullptr;
    addToBackSingleNode(node2,2);
    addToBackSingleNode(node2,4);
    addToBackSingleNode(node2,6);
    addToBackSingleNode(node2,8);
    printSingle(node2);
    printSingle(mergeTwoSortedSinleLLs(node1, node2));

    return 0;
}
