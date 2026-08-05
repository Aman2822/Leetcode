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
    bool hasCycle(ListNode *head) {
        map<ListNode* , int> cycle;

        ListNode* temp = head;

        while(temp != NULL){
            if(cycle.find(temp) != cycle.end()){
                return true;
            }
            cycle[temp] = 1;
            temp = temp->next;
        }
        return false;
    }
};