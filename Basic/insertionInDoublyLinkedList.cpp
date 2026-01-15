#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1, Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    };
    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};
void PrintLinkedList(Node* head){
    while(head){
        cout<<head->data<<", ";
        head = head->next;
    }
}

Node* convertArrToDoublyLinkedList(vector<int>arr){
    Node * head = new Node(arr[0]);
    Node * pre = head;
    for(int i=1; i<arr.size(); i++){
        Node *temp = new Node(arr[i], nullptr, pre);
        pre->next = temp;
        pre = temp;
    }
    return head;
}
void insertAtHead(Node* &head, int val){
    Node* New = new Node(val);
    New->next = head;
    head->prev = New;
    head = New;
}
void insertAtTail(Node* &head, int val){
    Node *New = new Node(val);
    Node*curr = head;
    while(curr->next!=nullptr){
        curr = curr->next;
    }
    curr->next = New;
    New->prev = curr;
}
void insertAtkthNode(Node* &head, int val ,int k){
    Node* New = new Node(val);
    Node * curr = head;
    while(k!=1){
        curr= curr->next;
        k--;
    }
    New->next = curr->next;
    curr->next->prev = New;
    curr->next = New;
    New->prev = New;
}

int main(){
    vector<int>arr = {1,2,3,4,5,6,7,8,9};
    Node* head = convertArrToDoublyLinkedList(arr);
    PrintLinkedList(head);
    cout<<endl;
    insertAtHead(head, 7);
    PrintLinkedList(head);
    cout<<endl;
    insertAtTail(head, 7);
    PrintLinkedList(head);
    cout<<endl;
    insertAtkthNode(head, 7,3);
    PrintLinkedList(head);
    cout<<endl;
    return 0;
}