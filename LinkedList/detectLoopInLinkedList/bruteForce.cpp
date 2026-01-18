#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

class Solution {
public:
    bool detectLoop(Node* head) {
       Node* temp = head;
       unordered_map<Node*, int> nodeMpp;
       while(temp!=nullptr){
        if(nodeMpp.find(temp)!=nodeMpp.end()){
            return true;
        }
        nodeMpp[temp] = 1;
        temp = temp->next;
       }
       return false;
    }
};

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    fifth->next = third;

    Solution obj;

    if (obj.detectLoop(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    return 0;
}
