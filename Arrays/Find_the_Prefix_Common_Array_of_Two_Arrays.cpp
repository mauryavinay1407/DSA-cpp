// problem : https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays

/*
Approach-1 : Brute Force
Time Complexity   :  O(N^3)
Space Complexity  :  O(1)
*/
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j <= i; j++) { // A
                // Find if we have A[x] in B or not till index i
                for (int k = 0; k <= i; k++) { // B
                    if (B[k] == A[j]) {
                        count++;
                        break;
                    }
                }
            }
            result[i] = count;
        }
        return result;
    }
};

/*
Approach-2 : Better Approach
Time Complexity   :  O(N^2)
Space Complexity  :  O(N)
*/
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> result(n);
        vector<bool> isPresentA(
            n + 1, false); // isPresent[i] = true, means i is present in A
        vector<bool> isPresentB(n + 1, false); 
        for (int i = 0; i < n; i++) {
            isPresentA[A[i]] = true;
            isPresentB[B[i]] = true;
            int count = 0;
            for (int num = 1; num <= n; num++) {
                if (isPresentA[num] == true && isPresentB[num] == true) {
                    count++;
                }
            }
            result[i] = count;
        }
        return result;
    }
};
/*
Approach-3 : Optimal using unordered set
Time Complexity   :  O(N)
Space Complexity  :  O(N)
*/
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_set<int> visited;
        unordered_set<int> seen;
        vector<int> result(n, 0);
        for (int i = 0; i < n; i++) {
            if (seen.count(A[i]))
                visited.insert(A[i]);
            else
                seen.insert(A[i]);
            if (seen.count(B[i]))
                visited.insert(B[i]);
            else
                seen.insert(B[i]);
            result[i] = visited.size();
        }
        return result;
    }
};
/*
Approach-4 : Optimal using hashmap
Time Complexity   :  O(N)
Space Complexity  :  O(N)
*/
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> result(n);
        unordered_map<int, int> mp;
        int count = 0;
        for (int i = 0; i < n; i++) {
            mp[A[i]]++;
            if (mp[A[i]] == 2) {
                count++;
            }
            mp[B[i]]++;
            if (mp[B[i]] == 2) {
                count++;
            }
            result[i] = count;
        }
        return result;
    }
};
/*
Approach-5 : Optimal using Bit-Masking
Time Complexity   :  O(N)
Space Complexity  :  O(51)~O(1)
*/
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<bool> seen(51, false);
        vector<int> result;
        int common = 0;

        for (int i = 0; i < n; ++i) {
            if (seen[A[i]]) {
                ++common;
            } else {
                seen[A[i]] = true;
            }
            if (seen[B[i]]) {
                ++common;
            } else {
                seen[B[i]] = true;
            }
            result.push_back(common);
        }
        return result;
    }
};
