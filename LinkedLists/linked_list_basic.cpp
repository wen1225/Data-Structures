#include <iostream>
using namespace std;
class LinkedList {
    private:
        struct Node {
            int val;
            Node* next;
        };
        Node* head;
    public:
        LinkedList() {head = nullptr;}
        void printNode() const;                                     
        void insertNode(int);
        void deleteNode(int);
};

void LinkedList::printNode() const {
    if (head == nullptr)
     return;
    Node* iter = head;
    while (iter->next != nullptr) {
        cout << iter->val << " -> ";
        iter = iter->next;
    }
    cout << iter->val;
    cout << endl;
}

void LinkedList::insertNode(int val) {
    /**
     * Case 1: if head is empty, let head point to new node.
     * Case 2: if head is not empty, iterate till the last node and use last node's next to point to new node.
     */
    Node* nodePtr = new Node;
    nodePtr->val = val;
    nodePtr->next = nullptr;
    if (head == nullptr) {
        head = nodePtr;
    }
    else {
        Node* iter = head;
        while (iter->next != nullptr) {
            iter = iter->next;
        }
        iter->next = nodePtr;
    }
}

void LinkedList::deleteNode(int val) {
    /**
     * Case 1: if head is null/empty, return.
     * Case 2: if head is target, use dummy pointer to save remaining list, then delete head and reassign head w/ remaining list stored in dummy pointer.
     * Case 3: if target in middle, iterate the list with two ptr, one behind the other. The prev ptr will link the list after deletion.
     */
    if (!head) 
        return;
    else if (head->val == val) {
        Node* iter = head->next;
        delete head;
        head = iter;
    }
    else {
        Node* iter = head;
        Node* prevNode = head;
        while (iter != nullptr) {
            if (iter->val == val) {
                prevNode->next = iter->next;
                delete iter;
                return;
            }
            prevNode = iter;
            iter = iter->next;
        }
    }
}

int main() {
    string x;
    LinkedList list;

    list.insertNode(1);
    list.printNode();

    list.insertNode(4);
    list.printNode();

    list.insertNode(6);
    list.printNode();

    list.insertNode(7);
    list.printNode();

    list.deleteNode(1);
    list.printNode();

    list.deleteNode(6);
    list.printNode();

    list.deleteNode(7);
    list.printNode();

    list.deleteNode(4);
    list.printNode();

    return 0;
}