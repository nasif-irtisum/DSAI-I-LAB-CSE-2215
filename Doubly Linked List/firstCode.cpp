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
void printLinkedList ()
{
    Node *traveler = head;
    while (traveler!=NULL) {
        cout << traveler->value<< endl;
        traveler= traveler->next;
    }


}
int main ()
{
    insertTail (5);
    insertTail(6);
    insertTail (7);
    insertHead (4);
    printLinkedList();


}
