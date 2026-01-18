
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        //check if k nodes Exists
        while(count<k){
            if(temp == nullptr) return head;
            temp = temp->next;
            count++;
        };
        //recursively call the function again
        ListNode* prevNode = reverseKGroup(temp, k);

        // reverse Current Group;

        temp = head;
        count =0;
        while(count<k){
            ListNode* nex = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = nex;
            count++;
        }
         return prevNode;
    }
};