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
        if (!head || !head->next || !head->next->next) return {-1, -1};

        int pos = 1;  // current node position (1-based)
        int first = -1, last = -1;  // first and last critical point positions
        int minDist = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr->next) {
            pos++;
            int nxtVal = curr->next->val;

            // Check if current node is a critical point
            if ((curr->val > prev->val && curr->val > nxtVal) ||
                (curr->val < prev->val && curr->val < nxtVal)) {
                
                if (first == -1) {
                    first = pos;
                } else {
                    minDist = min(minDist, pos - last);
                }
                last = pos;
            }

            prev = curr;
            curr = curr->next;
        }

        if (first == -1 || first == last) return {-1, -1};
        return {minDist, last - first};
    }
};
