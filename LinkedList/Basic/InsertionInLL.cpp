#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data1, Node*next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
Node* convertArrToLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node * curr = head;
    for(int i =1; i<arr.size(); i++){
        Node *temp = new Node(arr[i]);
        curr->next = temp;
        curr = temp;
    }
    return head;
}
void printLL(Node * head){
    while(head){
        cout<<head->data<<", ";
        head = head->next;
    }
}
void insertAthead(Node* & head, int value){
    Node * temp = new Node(value);
    temp->next = head;
    head = temp;
}
void insertAtPos(Node* &head, int val, int pos){
    Node* curr = head;
    for(int i=2; i<pos; i++){
        curr = curr->next;
    }
    Node* temp = new Node(val);
    temp->next = curr->next;
    curr->next = temp;
}

void insertVal(Node* head, int preVal, int Val){
    Node *curr = head;
    while(curr->data!=preVal){
        curr = curr->next;
    }
    curr->data = Val;
}
void insertAtLast(Node*head, int val){
    Node *curr = head;
    while(curr->next!=nullptr){
        curr= curr->next;
    }
    curr->next = new Node(val);
}

int main(){
    vector<int>arr = {1,2,3,4,5,6,7,8,9};
    Node *head = convertArrToLL(arr);
    printLL(head);
    cout<<endl;
    insertAthead(head,7);
    printLL(head);
    cout<<endl;
    insertAtPos(head, 0, 3);
    printLL(head);
    cout<<endl;
    insertVal(head, 6, 7);
    printLL(head);
    cout<<endl;
    insertAtLast(head, 10);
    printLL(head);
    return 0;
}