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
    ListNode* oddEvenList(ListNode* head) {

        //Space Complexity - O(N) and Time Complexity - O(2N)

        // if (head == NULL || head->next == NULL) {
        //     return head;
        // }

        // vector<int> data;

        // // Traverse through odd data;
        // ListNode* temp = head;
        // while (temp != NULL && temp->next != NULL) {
        //     data.push_back(temp->val);
        //     temp = temp->next->next;
        // }
        // if(temp) data.push_back(temp->val);

        // //Traverse through even nodes
        // temp = head->next;
        // while (temp != NULL && temp->next != NULL) {
        //     data.push_back(temp->val);
        //     temp = temp->next->next;
        // }
        // if(temp) data.push_back(temp->val);


        // temp = head;
        // for(int i = 0 ; i < data.size() ; i++){
        //    temp->val = data[i];
        //    temp = temp->next;
        // }

        // return head;

        //Optimized approach - Time Complexity - O(N/2)

        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenhead = head->next;


        //we have to only take care of even node because evben node will take care of odd node
        while(even != NULL && even->next != NULL){
            odd->next = odd->next->next;  //Change of adress
            even->next = even->next->next;

            odd = odd->next;  //Updation pehle hi kar liya
            even = even->next;
        }

        odd->next = evenhead;

        return head;


    }
};