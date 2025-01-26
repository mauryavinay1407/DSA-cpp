// problem : https://leetcode.com/problems/top-k-frequent-words

/*
Approach-1: Brute Force
Time Complexity   :  O(N^2)
Space Complexity  :  O(N)
*/
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<pair<int, string>> freqVec;
        vector<bool> counted(words.size(), false);

        // Count frequency of each word manually
        for (int i = 0; i < words.size(); i++) {
            if (counted[i]) continue;
            int count = 1; // Count the current word
            for (int j = i + 1; j < words.size(); j++) {
                if (words[i] == words[j]) {
                    count++;
                    counted[j] = true; // Mark as counted
                }
            }
            freqVec.push_back({count, words[i]});
        }

        // Sort based on frequency (descending) and lexicographical order (ascending)
        sort(freqVec.begin(), freqVec.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first == b.first)
                return a.second < b.second; // Lexicographical order
            return a.first > b.first;      // Descending frequency
        });

        // Extract the top k words
        vector<string> result;
        for (int i = 0; i < k; i++) {
            result.push_back(freqVec[i].second);
        }

        return result;
    }
};

/*
Approach-2: Optimal solution using min heap
Time Complexity   :  O(N*logK)
Space Complexity  :  O(N)
*/
class Solution {
public:
    using P = pair<int, string>;
    struct CustomComparator {
        bool operator()(const P& a, const P& b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        priority_queue<P, vector<P>, CustomComparator> minHeap;
        for (auto& word : words)
            mp[word]++;
        for (auto& m : mp) {
            minHeap.push({m.second, m.first});
            if (minHeap.size() > k)
                minHeap.pop();
        }
        vector<string> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
