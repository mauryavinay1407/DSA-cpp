// problem  :  https://leetcode.com/problems/finding-3-digit-even-numbers

/*
Approach-1: (Trying all possibilities using 3 for loops for 3 digits)
Time Complexity     : O(n^3 + SlogS), S = total 3 digits even numbers
Space Complexity    : O(S)
*/
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int> st;
        int n = digits.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    if(i == j || j == k || i == k) {
                        continue;
                    }

                    int num = digits[i]*100 + digits[j] * 10 + digits[k];

                    if(num >= 100 && num%2 == 0) {
                        st.insert(num);
                    }
                }
            }
        }

        vector<int> result(begin(st), end(st));
        sort(begin(result), end(result));
        return result;
    }
};

/*
Approach-2: Optimal using count of digits
Time Complexity       :  O(N)
Space Complexity      :  O(1)
*/
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int i = 0; i < digits.size(); i++) {
            freq[digits[i]]++;
        }

        vector<int> result;
        for (int i = 1; i <= 9; i++) {
            if (freq[i] == 0)
                continue;
            freq[i]--;
            for (int j = 0; j <= 9; j++) {
                if (freq[j] == 0)
                    continue;
                freq[j]--;
                for (int k = 0; k <= 8; k += 2) {
                    if (freq[k] == 0)
                        continue;
                    freq[k]--;
                    result.push_back(i * 100 + j * 10 + k);
                    freq[k]++;
                }
                freq[j]++;
            }
            freq[i]++;
        }
        return result;
    }
};
