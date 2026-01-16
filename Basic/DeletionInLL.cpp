#include<bits/stdc++.h>
using namespace std;

class Node{
    public :

    int data;
    Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
Node* ConvertArrToLL(vector<int>arr){
    Node * head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++){
        Node * temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void PrintLL(Node * head){
    while(head){
        cout<<head->data<<", ";
        head = head->next;
    }
}

void deletionOfHead(Node* &head){
    Node* temp = head;
    head = head->next;
    delete temp;
}
void deleteAtPosition(Node* &head, int pos){
    if(head==nullptr) return;
    if(pos==1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* curr = head;
    for(int i=1; i<pos-1 && curr->next!=nullptr; i++){
        curr = curr->next;
    }

    Node *temp = curr->next;
    curr->next = temp->next;
    delete temp;
}
void deleteTheValue(Node* &head, int val){
    Node * curr = head;
    while(curr->next->data == val){
        curr = curr->next;
    }
    Node*temp = curr->next;
    curr->next = temp->next;
    delete temp;
}
void deleteLast(Node * &head){
    Node* curr = head;
    while(curr->next->next!=nullptr){
        curr = curr->next;
    }
    Node *temp = curr->next;
    curr->next = nullptr;
    delete temp;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    Node * head = ConvertArrToLL(arr);
    PrintLL(head);
    cout<<endl;
    deletionOfHead(head);
    PrintLL(head);
    cout<<endl;
    deleteAtPosition(head, 3);
    PrintLL(head);
    cout<<endl;
    deleteTheValue(head, 6); 
    PrintLL(head);
    cout<<endl;
    deleteLast(head);
    PrintLL(head);
    return 0;
}