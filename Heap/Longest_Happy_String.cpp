// problem:  https://leetcode.com/problems/longest-happy-string/description/

/*
Approach: Greedy using max heap
Time Complexity: O(a+b+c)
Space Complexity: O(1)
*/

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0)
            pq.push({a, 'a'});
        if (b > 0)
            pq.push({b, 'b'});
        if (c > 0)
            pq.push({c, 'c'});
        string result = "";
        while (!pq.empty()) {
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();

            if (result.length() >= 2 && result[result.length() - 1] == ch &&
                result[result.length() - 2] == ch) {
                if (pq.empty())
                    break;
                int nextFreq = pq.top().first;
                int nextChar = pq.top().second;
                pq.pop();

                result.push_back(nextChar);
                nextFreq--;
                if (nextFreq > 0)
                    pq.push({nextFreq, nextChar});
            } else {
                freq--;
                result.push_back(ch);
            }
            if (freq > 0)
                pq.push({freq, ch});
        }
        return result;
    }
};
