#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *prev;
    int value;
    Node *next;
};
Node *head = NULL, *tail = NULL;

void printList()
{
    Node *traveler = head;

    while (traveler!=NULL) {
        cout << traveler->value << " ";
        traveler=traveler->next;
    }
}

void insertHead (int value)
{
    Node *newNode = new Node;

    newNode->prev = NULL;
    newNode->value = value;
    newNode->next = NULL;

    if (head==NULL) {
        head = newNode;
        tail= newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head=newNode;
}

void insertLast (int value)
{
    Node *newNode = new Node;

    newNode->prev = NULL;
    newNode->value = value;
    newNode->next = NULL;

    if (tail == NULL) {
        tail = head = newNode;
        return;

    }
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}
int main ()
{
    insertLast(1);
    insertHead(5);
    insertHead(2);
    insertLast(7);
    printList();
}
