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
