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
    ListNode* sortList(ListNode* head) {
        if(head == NULL) return head;

        //Time Complexity- O(nlogn) + O(2N) && Space complexity = O(N)
        ListNode* temp = head;
        vector<int> el;

        while(temp != NULL){
            el.push_back(temp->val);
            temp = temp->next;
        }

        sort(el.begin() , el.end());

        temp = head;
        for(int i = 0 ; i < el.size() ; i++){
            temp->val = el[i];
            temp = temp->next;
        }

        return head;
    }
};