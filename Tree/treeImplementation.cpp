#include <bits/stdc++.h>
using namespace std;


struct Node
{
public:
    Node *left;
    int value;
    Node *right;

    Node *parent;
};

Node *head = NULL;
int leafSum=0;

void insertNode (int value)
{
    Node *newNode = new Node;

    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    if (head==NULL){
        head = newNode;
        return;
    }

    Node *traveler = head;
    Node *follower = NULL;

    while (traveler!=NULL) {
        if (newNode->value>traveler->value) {
            follower = traveler;
            traveler = traveler->right;
        }
        else {
            follower = traveler;
            traveler = traveler->left;
        }
    }
    if (newNode->value>follower->value) {
        follower->right=newNode;
        newNode->parent = follower;
    }
    else {
        follower->left=newNode;
        newNode->parent = follower;
    }
}

void inOrder(Node *traveler)
{
    if (traveler==NULL) return;

    inOrder(traveler->left);
    cout << " -> " << traveler->value;
    inOrder(traveler->right);
}

void sumOfLeafValues(Node *traveler)
{
    if (traveler==NULL) return;

    if (traveler->left==NULL and traveler->right==NULL) {
        cout << "Addition: " << traveler->value << endl;
        leafSum+=traveler->value;
    }


    sumOfLeafValues(traveler->left);
    sumOfLeafValues(traveler->right);

}
Node *searchNode (int value)
{
    Node *traveler = head;

    while (traveler!=NULL)
    {
        if (value > traveler->value) {
            traveler=traveler->right;
        }
        else if (value< traveler->value){
            traveler=traveler->left;
        }
        else break;
    }
    return traveler;
}
void getParent (Node *traveler)
{
    if (traveler==NULL) return;
    getParent(traveler->parent);
    cout << " -> " << traveler->value;
}
int main ()
{
    insertNode(50);
    insertNode(40);
    insertNode(60);
    insertNode(45);
    insertNode(30);
    insertNode(70);
    insertNode(55);


    //inOrder(head);

    /*
    sumOfLeafValues(head);
    cout << "Total : ";
    cout << leafSum  << endl;
    */

    Node *addr = searchNode (55);
    getParent(addr);


}
