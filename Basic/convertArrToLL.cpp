#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
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

Node* convertIntoLinkedList(vector<int> arr){
    Node *head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++){
        Node * temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int lengthOfTheLL(Node* head){
    int count = 0;
    while(head){
        count++;
        head = head->next;
    }
    return count;
}

int main(){
    vector<int>arr = {2,3,4,5,6,7,8};
    Node* head = convertIntoLinkedList(arr);
    Node * temp = head;
    while(temp){
        cout<<temp->data<<", ";
        temp = temp->next;
    }
    cout<<endl;
    int length = lengthOfTheLL(head);
    cout<<"Length of the linked List is :"<<length;

    return 0;
}