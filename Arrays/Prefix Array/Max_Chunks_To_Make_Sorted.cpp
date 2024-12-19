// problem : https://leetcode.com/problems/max-chunks-to-make-sorted

/*
Approach-1: Using cumulative sum
Time Complexity   :  O(N)
Space Complexity  :  O(N)
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int cumSum    = 0;
        int normalSum = 0;

        int chunksCount = 0;
        for(int i = 0; i < n; i++) {
            cumSum += arr[i];
            normalSum += i;

            if(cumSum == normalSum) {
                chunksCount++;
            }
        }

        return chunksCount;
    }
};

/*
Approach-2: Using prefixMax and SuffixMin
Time Complexity   :  O(N)
Space Complexity  :  O(N)
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixMax(begin(arr), end(arr));
        vector<int> suffixMin(begin(arr), end(arr));

        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], prefixMax[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], suffixMin[i]);
        }

        int chunksCount = 0;
        for (int i = 0; i < n; i++) {
            int preMax = i > 0 ? prefixMax[i - 1] : -1;
            int afterMin  = suffixMin[i];
            
            if(preMax < afterMin) {
                chunksCount++;
            }
        }

        return chunksCount;
    }
};
/*
Approach-3: Using monotonic stacks
Time Complexity   :  O(N)
Space Complexity  :  O(N)
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st;
        int result=0;
        for(int i=0;i<arr.size();i++){
            st.push(arr[i]);
            while(!st.empty() && st.top() <= i)
                st.pop();
            if(st.empty())
                result++;
        }
        return result;
    }
};
