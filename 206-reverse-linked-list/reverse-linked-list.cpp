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
    ListNode* reverseList(ListNode* head) {

        //Using stack - brute force approach

        // if(head == NULL){
        //     return NULL;
        // }
        // ListNode* temp = head;
        // stack<int> st;

        // while(temp != NULL){
        //     st.push(temp->val);
        //     temp = temp->next;
        // }

        // ListNode* temp1 = head;
        // while(temp1 != NULL){
        //     temp1->val = st.top();
        //     st.pop();
        //     temp1 = temp1->next;
        // }

        // return head;

       // Optimize approach - Iterative
        // ListNode* temp = head ;
        // ListNode* prev = NULL;
        // ListNode* front;

        // while(temp != NULL){
        //     front = temp->next;
        //     temp->next = prev;
        //     prev = temp;
        //     temp = front;
        // }
        // return prev;

        //Recursive approach 
        if(head == NULL|| head->next == NULL){
            return head;
        }

        ListNode* newHead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;

       
        
    }
};