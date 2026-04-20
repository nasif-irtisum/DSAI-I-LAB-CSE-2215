#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

Node *head = NULL;

void printList ()
{
    if (head==NULL) {
        cout << "EMPTY" << endl;
        return;
    }
    Node *traversal = head;

    while (traversal!=NULL){
        if (traversal->next==NULL) cout << traversal->value << endl;
        else cout << traversal->value << " -> ";

        traversal=traversal->next;
    }
}

void insertFirst(int value)
{
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = NULL;

    if (head==NULL) head = newNode;

    else {
        newNode->next = head;
        head = newNode;
    }

}

void insertTail(int value)
{
    Node *newNode = new Node;

    newNode->value = value;
    newNode->next = NULL;


    if (head == NULL) {
        head = newNode;
        return;
    }

    Node * traveler  = head;

    while (traveler ->next!=NULL)
    {
        traveler=traveler->next;
    }
    traveler->next = newNode;

}

void inserAfterAValue (int value, int newValue)
{
    if (head == NULL) {
        cout << "Empty" << endl;
        return;
    }
    Node *traveler = head;

    while (traveler!=NULL) {
        if (traveler->value == value) {
            Node *newNode = new Node;
            newNode->value = newValue;

            newNode ->next = traveler->next;
            traveler->next = newNode;
        }
        traveler=traveler->next;
    }
}

void deleteHead ()
{
    if (head == NULL) {
        cout << "Nothing to Delete" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;

    delete temp;
}

void deleteTail ()
{
    if (head==NULL) {
        cout << "Nothing to Delete" << endl;
        return;
    }

    Node *traveler = head;

    while (traveler->next != NULL) {
        traveler=traveler->next;
    }

    Node *follower = head;
    while (follower->next != traveler){
        follower = follower->next;
    }
    follower->next = NULL;

    delete traveler;
}

int main ()
{
    insertTail (8);
    insertFirst(6);
    insertFirst(4);
    insertTail(10);

    inserAfterAValue(6,7);

    insertFirst(1);

    printList();

    deleteHead();

    printList();

    deleteTail();
    printList();
}
