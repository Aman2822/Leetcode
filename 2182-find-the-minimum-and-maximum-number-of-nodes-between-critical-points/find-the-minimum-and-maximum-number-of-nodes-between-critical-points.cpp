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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};

        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return ans;
        }

        vector<int> allnodes;
        // ListNode* prev = head;
        // ListNode* curr = head->next;
        // ListNode* front = head->next->next;

        ListNode* temp = head;

        while (temp != NULL) {
            allnodes.push_back(temp->val);
            temp = temp->next;
        }

        vector<int> critical;

        for (int i = 1; i < allnodes.size() - 1; i++) {
            if (allnodes[i] > allnodes[i - 1] &&
                allnodes[i] > allnodes[i + 1]) {
                critical.push_back(i);
            }
            if (allnodes[i] < allnodes[i - 1] &&
                allnodes[i] < allnodes[i + 1]) {
                critical.push_back(i);
            }
        }

        sort(critical.begin(), critical.end());
        int n = critical.size();

        if(n <= 1) return {-1,-1};

        int max_diff = critical[n-1] - critical[0];
        // cout << max_diff << endl;

        int min_diff = INT_MAX;
        for (int i = 1; i < critical.size(); ++i) {
            min_diff = min(min_diff, critical[i] - critical[i - 1]);
        }
        // cout << min_diff << endl;

        ans[0] = min_diff;
        ans[1] = max_diff;

        return ans;
    }
};