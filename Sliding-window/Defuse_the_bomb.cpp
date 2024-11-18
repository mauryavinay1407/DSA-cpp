//  problem:  https://leetcode.com/problems/defuse-the-bomb

/*
Approach-1:  By calculating sum for each position
Time Complexity:    O(N*k)
Space Complexity:   O(1)
*/
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);
        if (k == 0)
            return result;
        for (int i = 0; i < n; i++) {
            long long sum = 0;
            if (k < 0) {
                for (int j = i - abs(k); j < i; j++)
                    sum += code[(j + n) % n];
            } else {
                for (int j = i + 1; j <= i + k; j++)
                    sum += code[j % n];
            }
            result[i] = sum;
        }
        return result;
    }
};
/*
Approach-2:  By pre calculate the sum for first position then sliding window
Time Complexity:    O(N)
Space Complexity:   O(1)
*/
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);
        if (k == 0)
            return result;
        int i, j;
        if (k > 0) {
            i = 1;
            j = k;
        } else {
            i = n - abs(k);
            j = n - 1;
        }
        int sum = 0;
        for (int p = i; p <= j; p++)
            sum += code[p];
        for (int l = 0; l < n; l++) {
            result[l] = sum;

            sum -= code[i % n];
            sum += code[((j + 1) % n)];
            i++;
            j++;
        }
        return result;
    }
};
