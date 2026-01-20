#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        for (int i = 0; i < k; i++) {
            ListNode* curr = head;
            ListNode* prev = NULL;

            while (curr->next) {
                prev = curr;
                curr = curr->next;
            }

            prev->next = NULL;
            curr->next = head;
            head = curr;
        }
        return head;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;
    int k = 2;
    ListNode* result = obj.rotateRight(head, k);

    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
