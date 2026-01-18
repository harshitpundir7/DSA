#include <bits/stdc++.h>
using namespace std;

// Node class represents a node in a linked list
class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the list

    // Constructor with both data and next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to check if the linked list is a palindrome
bool isPalindrome(Node* head) {
    // Create an empty stack to store values
    stack<int> st;

    // Initialize a temporary pointer to the head of the linked list
    Node* temp = head;

    // Traverse the linked list and push values onto the stack
    while (temp != NULL) {
        st.push(temp->data); // Push the data from the current node onto the stack
        temp = temp->next;   // Move to the next node
    }

    // Reset the temporary pointer back to the head of the linked list
    temp = head;

    // Compare values by popping from the stack and checking against linked list nodes
    while (temp != NULL) {
        if (temp->data != st.top()) {
            // If values don't match, it's not a palindrome
            return false;
        }
        st.pop();           // Pop the value from the stack
        temp = temp->next;  // Move to the next node in the linked list
    }

    // If all values match, it's a palindrome
    return true;
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " "; // Print the current node's data
        temp = temp->next;         // Move to the next node
    }
    cout << endl;
}

// Driver function
int main() {
    // Create a linked list with values 1, 5, 2, 5, and 1 (15251, a palindrome)
    Node* head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Check if the linked list is a palindrome
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
