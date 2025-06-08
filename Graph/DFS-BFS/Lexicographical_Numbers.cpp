// problem:  https://leetcode.com/problems/lexicographical-numbers/description/

class Solution {
public:
    vector<int> ans;
    void findOrder(int n, int i) {
        if (i > n)
            return;
        ans.push_back(i);
        for (int j = 0; j <= 9; j++) {
            int num = i * 10 + j;
            if (num > n)
                return;
            findOrder(n, num);
        }
    }
    vector<int> lexicalOrder(int n) {
        for (int i = 1; i <= 9; i++)
            findOrder(n, i);
        return ans;
    }
};

/*
Approach-2 : Using Simple loop
Time Complexity       : O(N)
Space Complexity      : O(1)
*/
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result(n);

        int curr = 1;

        for(int i = 0; i < n; i++){
            result[i] = curr;

            if(curr * 10 <= n){
                curr *= 10;
            }
            else{
                if(curr == n){
                    curr /= 10;
                }
                curr++;
                while(curr % 10 == 0){
                    curr /= 10;
                }
            }
        }
        return result;
    }
};
