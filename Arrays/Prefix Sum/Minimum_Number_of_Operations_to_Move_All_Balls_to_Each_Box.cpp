// problem : https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box

/*
Approach-1 : Brute Force
Time Complexity    : O(n^2)
Space Complexity   : O(n)
*/
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        unordered_set<int> st;
      // storing the indices of all the 1's
        for(int i = 0; i < n; i++) {
            if(boxes[i] == '1') {
                st.insert(i);
            }
        }

        vector<int> result(n, 0);
     //  calculating the distance
        for(int i = 0; i < n; i++) {
            for(auto &idx : st) {
                result[i] += abs(i - idx);
            }
        }
        return result;
    }
};
/*
Approach-2 : Better than Brute Force
Time Complexity    : O(n^2)
Space Complexity   : O(1)
*/
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();

        vector<int> result(n, 0);

        for(int i = 0; i < n; i++) {

            if(boxes[i] == '1') {
                for(int j = 0; j < n; j++) {
                    result[j] += abs(j-i);
                }
            }
        }

        return result;
    }
};

/*
Approach-3 :  Better
Time Complexity    : O(n)
Space Complexity   : O(n)
*/
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int preSum = 0, sufSum = 0;

        // calculating prefix sum from left
        vector<int> pre(n, 0);
        pre[0] = boxes[0] - '0';
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + (boxes[i] - '0');

        // calculating prefix sum from right
        vector<int> suf(n, 0);
        suf[n - 1] = boxes[n - 1] - '0';
        for (int i = n - 2; i >= 0; i--)
            suf[i] = suf[i + 1] + (boxes[i] - '0');

        // calculating the pre sum of moves from left
        vector<int> ltr(n);
        ltr[0] = 0;
        for (int i = 1; i < n; i++)
            ltr[i] = ltr[i - 1] + pre[i - 1];

        // calculating the pre sum of moves from right
        vector<int> rtl(n);
        rtl[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--)
            rtl[i] = rtl[i + 1] + suf[i + 1];

        vector<int> result(n);
        for (int i = 0; i < n; i++)
            result[i] = ltr[i] + rtl[i];

        return result;
    }
};
/*
Approach-4 :  Optimal (beginner friendly) using Prefix Sum
Time Complexity    : O(n)
Space Complexity   : O(1)
*/
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();

        vector<int> answer(n, 0);

        int cumValue    = 0;
        int cumValueSum = 0;

        //Find moves for all left balls to index i
        //O(n)
        for(int i = 0; i < n; i++) {
            answer[i] = cumValueSum;
            
            cumValue += boxes[i] == '0' ? 0 : 1;
            
            cumValueSum += cumValue;
        }

        cumValue    = 0;
        cumValueSum = 0;
        //Find moves for all right balls to index i
        //O(n)
        for(int i = n-1; i >= 0; i--) {
            answer[i] += cumValueSum;
            
            cumValue += boxes[i] == '0' ? 0 : 1;
            
            cumValueSum += cumValue;
        }

        //O(n+n) ~ O(n)
        return answer;

    }
};

/*
Approach-5 :  Optimal (ultra) using Prefix Sum
Time Complexity    : O(n)
Space Complexity   : O(1)
*/
class Solution {
public:
    vector<int> minOperations(string boxes) {
    vector<int> res(boxes.length()); 
    for (int i = 0, ops = 0, cnt = 0; i < boxes.length(); ++i) {
       res[i] += ops;
       cnt += boxes[i] == '1' ? 1 : 0;
       ops += cnt;
    }
    for (int i = boxes.length() - 1, ops = 0, cnt = 0; i >= 0; --i) {
        res[i] += ops;
        cnt += boxes[i] == '1' ? 1 : 0;
        ops += cnt;
    }
    return res;
}
};
