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
    ListNode* deleteMiddle(ListNode* head) {
        // When there is no node return NULL and when there is only one node delete it and return null
        if(head == NULL || head->next == NULL ){
            return NULL;
        }
        ListNode* temp = head;
        ListNode* prev = NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        // For reaching to middle node and keep a pointer for previous node of middle node (prev)
        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // Changed the address 
        prev->next = slow->next;
        return head;
    }
};