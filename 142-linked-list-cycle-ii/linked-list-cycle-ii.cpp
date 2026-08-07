/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        //brute force

        // map<ListNode* , int> cycle;

        // ListNode* temp = head;

        // while(temp != NULL){
        //     if(cycle.find(temp) != cycle.end()){
        //         return temp;
        //     }
        //     cycle[temp] = 1;
        //     temp = temp->next;
        // }
        // return NULL;

        //optimize approach

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                ListNode* slow1 = head;

                while(slow1 != fast){
                    slow1 = slow1->next;
                    fast = fast->next;
                }
                return slow1;
            }
           
        }
        return NULL;
    }
};