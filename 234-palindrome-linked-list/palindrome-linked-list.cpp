/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Reach middle node with slow
        while(fast->next != NULL && fast != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //Reverse the other middle half
        ListNode* temp = slow->next;
        ListNode* prev = NULL;
        ListNode* front;
        while(temp != NULL){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        //Check the values if mismatch then return false
        ListNode* p1 = head;
        ListNode* p2 = prev;

        while(p2 != NULL){
            if(p1->val != p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }

        return true;


    }
};