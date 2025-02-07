//  problem :  https://leetcode.com/problems/permutation-sequence

/*
Approach-1 :  Brute force by generating all the permutation
Time Complexity     :    O(n! * log(n!))
Space Complexity    :    O(n! * n)
*/
class Solution {
public:
    void findPermutation(string& str, int i, vector<string>& perm) {
        if (i == str.size()) {
            perm.push_back(str);
            return;
        }
        for (int idx = i; idx < str.length(); idx++) {
            swap(str[i], str[idx]);
            findPermutation(str, i + 1, perm);
            swap(str[i], str[idx]);
        }
    }
    string getPermutation(int n, int k) {
        string str;
        for (int i = 1; i <= n; i++) {
            str += i + '0';
        }
        vector<string> perm;
        findPermutation(str, 0, perm);
        sort(perm.begin(), perm.end());
        return perm[k - 1];
    }
};
/*
Approach-2 :  By using next permutation approach
Time Complexity     :    O(n * k)
Space Complexity    :    O(1)
*/
class Solution {
public:
    bool next_permutation(string::iterator begin, string::iterator end) {
        if (begin == end) return false;
        
        string::iterator i = end - 1;
        while (i > begin) {
            if (*(i - 1) < *i) break;
            --i;
        }
        
        if (i == begin) return false;
        
        string::iterator j = end - 1;
        while (*j <= *(i - 1)) --j;
        
        swap(*(i - 1), *j);
        reverse(i, end);
        return true;
    }
    
    string getPermutation(int n, int k) {
        string ans;
        for (int i = 0; i < n; ++i) ans += ('1' + i);
        while (--k) next_permutation(begin(ans), end(ans));
        return ans;
    }
};
/*
Approach-3 :  using factorial + extra space for storing sequence
Time Complexity     :    O(n^2)
Space Complexity    :    O(n)
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        string result = "";
        vector<int> nums;
        int fact = 1;
        for (int i = 1; i <= n; i++) {
            fact *= i;
            nums.push_back(i);
        }
        k--;
        for (int i = 0; i < n; i++) {
            fact /= nums.size();
            int index = k / fact;
            result.push_back(nums[index] + '0');
            nums.erase(nums.begin() + index);
            k %= fact;
        }
        return result;
    }
};
