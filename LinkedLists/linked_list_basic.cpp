#include <iostream>
#include <vector>
using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int val;
        Node *next;
    };
    Node *head;

public:
    LinkedList() { head = nullptr; }
    void printNode() const;
    void insertNodeBegin(int);
    void insertNodeMiddle(int);
    void insertNodeEnd(int);
    void deleteNode(int);
    void append(LinkedList);
};

void LinkedList::printNode() const
{
    if (head == nullptr)
        return;
    Node *iter = head;
    while (iter->next != nullptr)
    {
        cout << iter->val << " -> ";
        iter = iter->next;
    }
    cout << iter->val;
    cout << endl;
}

void LinkedList::insertNodeBegin(int val)
{
    Node *nodePtr = new Node;
    nodePtr->val = val;
    nodePtr->next = nullptr;
    if (head == nullptr)
    {
        head = nodePtr;
    }
    else
    {
        nodePtr->next = head;
        head = nodePtr;
    }
}

void LinkedList::insertNodeMiddle(int val)
{
    // 1. Find the length of the linked list
    // 2. Divide the length by two, save it to var
    // 3. Re-iterate the list again until we hit the nth node that is one less than var
    // 4. Insert the new node next to the nth node one less than var

    // Edge cases:
    //  How does it handle a list w/ a single node? just add it to the end
    Node *iter = head;
    int listLength = 0;
    while (iter != nullptr)
    {
        listLength++;
        iter = iter->next;
    }
    listLength = listLength / 2;
    iter = head;
    while (listLength > 1)
    {
        iter = iter->next;
        listLength--;
    }
    Node *nodePtr = new Node;
    nodePtr->val = val;
    nodePtr->next = iter->next;
    iter->next = nodePtr;
}

void LinkedList::insertNodeEnd(int val)
{
    /**
     * Case 1: if head is empty, let head point to new node.
     * Case 2: if head is not empty, iterate till the last node and use last node's next to point to new node.
     */
    Node *nodePtr = new Node;
    nodePtr->val = val;
    nodePtr->next = nullptr;
    if (head == nullptr)
    {
        head = nodePtr;
    }
    else
    {
        Node *iter = head;
        while (iter->next != nullptr)
        {
            iter = iter->next;
        }
        iter->next = nodePtr;
    }
}

void LinkedList::deleteNode(int val)
{
    /**
     * Case 1: if head is null/empty, return.
     * Case 2: if head is target, use dummy pointer to save remaining list, then delete head and reassign head w/ remaining list stored in dummy pointer.
     * Case 3: if target in middle, iterate the list with two ptr, one behind the other. The prev ptr will link the list after deletion.
     * Case 4: if target is not found, then return a print statement saying target not found
     */
    if (!head)
        return;
    else if (head->val == val)
    {
        Node *iter = head->next;
        delete head;
        head = iter;
    }
    else
    {
        Node *iter = head;
        Node *prevNode = head;
        while (iter != nullptr)
        {
            if (iter->val == val)
            {
                prevNode->next = iter->next;
                delete iter;
                return;
            }
            prevNode = iter;
            iter = iter->next;
        }
        cout << "Node not found!\n";
    }
}

void LinkedList::append(LinkedList l2)
{
    Node *iter = this->head;
    while (iter->next != nullptr)
    {
        iter = iter->next;
    }
    iter->next = l2.head;
}

/*
    LinkedList sort(LinkedList list) {
    LinkedList::Node *ptr1 = list.getHead();
    LinkedList::Node *ptr2 = list.getHead();
    LinkedList::Node *divider = list.getHead();
    //how to sort a linked list? (medium question)
    //1. iterative approach
    //2. recursive approach

}
*/

int main()
{

    return 0;
}