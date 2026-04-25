#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *nextNode;
};

Node *head = NULL;

void printList (Node *node)
{
    if (node == NULL) return;

    cout << node->value << endl;

    printList (node->nextNode);
}
int main ()
{
    int n; cin >>n;
    while (n--) {
        int value; cin >> value;

        Node *newNode = new Node;
        newNode->value = value;
        newNode->nextNode = NULL;

        if (head==NULL) {
            head=newNode;
        }
        else {
            Node *traversal = head;
            while (traversal->nextNode!=NULL)
                traversal=traversal->nextNode;

            traversal->nextNode=newNode;
        }
    }
    Node *tr = head;
    printList(tr);

    return 0;
}
