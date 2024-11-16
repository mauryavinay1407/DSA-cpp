// problem: https://leetcode.com/problems/merge-k-sorted-lists

/*
Approach: By merging two at a time and resultant will be merge with other lists iteratively
Time Complexity:     O(N*logK)
Space Complexity:     O(K)
*/

class Solution {
public:
    ListNode* mergeLists(ListNode* first, ListNode* second) {
        if (!first)
            return second;
        if (!second)
            return first;
        if (first->val <= second->val) {
            first->next = mergeLists(first->next, second);
            return first;
        } else {
            second->next = mergeLists(second->next, first);
            return second;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;
        if (lists.size() == 1)
            return lists[0];
        ListNode* mainHead = mergeLists(lists[0], lists[1]);
        for (int i = 2; i < lists.size(); i++) {
            mainHead = mergeLists(mainHead, lists[i]);
        }
        return mainHead;
    }
};
