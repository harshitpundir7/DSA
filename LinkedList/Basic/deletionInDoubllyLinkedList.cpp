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

void deleteTheHead(Node* &head){
    Node *pre = head;
    head = head->next;
    head->prev = nullptr;
    pre->next = nullptr;
    delete pre;
}
void deleteTheTail(Node* &head){
    Node *curr = head;
    while(curr->next->next!=nullptr){
        curr = curr->next;
    }
    Node * temp = curr->next;
    curr->next = nullptr;
    temp->prev = nullptr;
    delete temp;
}
void deleteKthNode(Node*& head, int k){
    Node* curr = head;
    while(k!=1){
        curr= curr->next;
        k--;
    }
    Node* front = curr->next;
    Node* back = curr->prev;
    back->next = front;
    front->prev = back;
    delete curr;
}
void deleteTheNode(Node* node){
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
}
int main(){
    vector<int>arr ={1,2,3,4,5,6,7,8,9};
    Node * head = convertArrToDoublyLinkedList(arr);
    PrintLinkedList(head);
    cout<<endl;
    deleteTheHead(head);
    PrintLinkedList(head);
    cout<<endl;
    deleteTheTail(head);
    PrintLinkedList(head);
    cout<<endl;
    deleteKthNode(head, 3);
    PrintLinkedList(head);
    cout<<endl;
    deleteTheNode(head->next->next->next);
    PrintLinkedList(head);
    return 0;    
}