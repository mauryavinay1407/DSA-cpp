// problem  :  https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars

/*
Approach - Using Min Heap
Time Complexity         :  O(N*logN)
Space Complexity        :  O(N)
*/
class Solution {
public:
    using P = pair<int, int>;
    struct customComparator {
        bool operator()(const P& a, const P& b) const {
            if (a.first != b.first)
                return a.first > b.first;
            return a.second < b.second;
        }
    };
    string clearStars(string s) {
        priority_queue<P, vector<P>, customComparator> minHeap;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '*') {
                int temp = minHeap.top().second;
                minHeap.pop();
                s[i] = '1';
                s[temp] = '1';
            } else {
                minHeap.push({s[i], i});
            }
        }

        string result = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '1') {
                result += s[i];
            }
        }
        return result;
    }
};
