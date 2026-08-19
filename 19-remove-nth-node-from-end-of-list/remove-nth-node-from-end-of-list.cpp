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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        //Approach 1 - Brute force
        // ListNode* temp = head;

        // //Length of LL
        // int count  = 0;
        // while(temp != NULL){
        //     count++;
        //     temp = temp->next;
        // }
        
        // int resultant_Node = count - n;
        // //Delete the head count== n it means
        // if(count == n){
        //     ListNode* newhead = head->next;
        //     delete(head);
        //     return newhead;
        // }

        // temp = head;
        // // To reach to the previous node that should be deleted
        // while(temp != NULL){
        //     resultant_Node--;

        //     if(resultant_Node == 0){
        //         break;
        //     }
        //     temp = temp->next;
        // }
        // //Require delete Node
        // ListNode* deleteNode = temp->next;
        // temp->next = temp->next->next;  // Change of address
        // delete(deleteNode);

        // return head;

        //Approach 2 - Optimal- Slow and fast pointers
        ListNode* fast = head;
        
        //Move forward n steps
        for(int i = 0 ; i < n ; i++){
            fast = fast->next;
        }

        if(fast == NULL){
            return head->next;
        }

        ListNode* slow = head;
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete(delNode);

        return head;
    }
};