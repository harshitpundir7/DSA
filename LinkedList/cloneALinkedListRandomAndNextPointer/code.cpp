#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        unordered_map<Node*, Node*> map;

        Node* newHead = new Node(head->val);
        Node* oldTemp = head;
        map[head] = newHead;

        Node* newTemp = newHead;
        oldTemp = oldTemp->next;

        while(oldTemp != NULL){
            Node* copyNode = new Node(oldTemp->val);
            map[oldTemp] = copyNode;
            newTemp->next = copyNode;
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        oldTemp = head;
        newTemp = newHead;
        while(oldTemp != NULL){
            newTemp->random = oldTemp->random ? map[oldTemp->random] : NULL;
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
        return newHead;
    }
};

void printList(Node* head) {
    while(head) {
        cout << "Val: " << head->val;
        if(head->random)
            cout << ", Random: " << head->random->val;
        else
            cout << ", Random: NULL";
        cout << endl;
        head = head->next;
    }
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next;

    cout << "Original List:" << endl;
    printList(head);

    Solution obj;
    Node* copiedList = obj.copyRandomList(head);

    cout << "\nCopied List:" << endl;
    printList(copiedList);

    return 0;
}
