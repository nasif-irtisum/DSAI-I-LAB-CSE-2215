#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *prev;
    int value;
    Node *next;
};
Node *head  = NULL;

void insertHead (int value)
{
    Node *newNode = new Node;
    newNode->prev = NULL;
    newNode->value = value;
    newNode->next = NULL;

    if (head==NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}
void insertTail (int value)
{
    Node *newNode = new Node;
    newNode->prev = NULL;
    newNode->value = value;
    newNode->next = NULL;

    if (head==NULL){
        head = newNode;
        return;
    }
    Node *traversal = head;

    while (traversal->next !=NULL) traversal= traversal->next;

    newNode->prev = traversal;
    traversal->next = newNode;

}
void slowFast (int value)
{
    Node *newNode = new Node;
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    if (head->next == NULL) {
        head->next = newNode;
        head->next->prev = head;
    }
    Node *fast = head, *slow = head;

    while (true) {
        if (fast == NULL) break;
        if (fast->next == NULL) break;

        fast = fast->next->next;
        slow = slow->next;

    }
    newNode->next = slow;
    newNode->prev = slow->prev;
    slow->prev = newNode;
    newNode->prev->next = newNode;
}
void printLinkedList ()
{
    Node *traveler = head;
    while (traveler!=NULL) {
        cout << traveler->value<< endl;
        traveler= traveler->next;
    }


}


Node * listSerach (int value)
{
    Node *tr = head;
    while (tr != NULL) {
        if (tr->value == value) return tr;

        tr = tr->next;
    }
    return NULL;
}
void deleteAllValue (int value)
{
    Node *tmp;
    while (tmp = listSerach(value)) {
        if (tmp==head) {
            head = head->next;
            head->prev = NULL;
        }
        tmp->prev->next=tmp->next;
        tmp->next->prev = tmp->prev;
        delete tmp;
    }
}

void delFastSlow ()
{
    Node *fast = head, *slow = head;
    while (true)
    {
        if (fast==NULL) break;
        if (fast->next == NULL) break;

        fast=fast->next->next;
        slow=slow->next;
    }
    slow->next->prev =slow->prev;
    slow->prev->next = slow->next;

    delete slow;
}
int main ()
{
    insertTail (5);
    insertTail(6);
    insertTail (7);
    insertHead (4);
    insertTail(500);
    slowFast(100);
    printLinkedList();
    delFastSlow();
    printLinkedList();


}
