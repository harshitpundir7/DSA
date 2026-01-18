#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int num;
    node* next;
    node(int val) {
        num = val;
        next = NULL;
    }
};

void insertNode(node* &head, int val) {
    node* newNode = new node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

node* intersectionPresent(node* head1, node* head2) {
    node* d1 = head1;
    node* d2 = head2;
    while (d1 != d2) {
        d1 = d1 ? d1->next : head2;
        d2 = d2 ? d2->next : head1;
    }
    return d1;
}
