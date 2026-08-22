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
        if (head == NULL || head->next == NULL) {
            return head;
        }

        vector<int> data;

        // Traverse through odd data;
        ListNode* temp = head;
        while (temp != NULL && temp->next != NULL) {
            data.push_back(temp->val);
            temp = temp->next->next;
        }
        if(temp) data.push_back(temp->val);

        //Traverse through even nodes
        temp = head->next;
        while (temp != NULL && temp->next != NULL) {
            data.push_back(temp->val);
            temp = temp->next->next;
        }
        if(temp) data.push_back(temp->val);


        temp = head;
        for(int i = 0 ; i < data.size() ; i++){
           temp->val = data[i];
           temp = temp->next;
        }

        return head;
    }
};