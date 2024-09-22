// problem:  https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description/

/*
Approach-1 same as finding Lexicographical numbers
MLE
*/

class Solution {
public:
    void findOrder(int n,int k,vector<int>& res,int num){
        if(num>n)
        return;
        res.push_back(num);
        for(int i=0;i<=9;i++){
            int temp=num*10+i;
            if(temp>n)
            return ;
            findOrder(n,k,res,temp);
        }
    }
    int findKthNumber(int n, int k) {
        vector<int> res;
        for(int i=1;i<=9;i++){
            findOrder(n,k,res,i);
        }
        return res[k-1];
    }
};

/*
Approach-2 same as finding Lexicographical numbers but without storing all the numbers
TLE
*/

class Solution {
public:
    void findOrder(int n,int& k,long long num,long long& flag){
        if(num>n)
        return;
        k--;
        if(k==0){
            flag=num;
            return;
        }
        for(int i=0;i<=9;i++){
            long long temp=num*10+i;
            if(temp>n)
            return ;
            findOrder(n,k,temp,flag);
        }
    }
    int findKthNumber(int n, int k) {
        long long flag=0;
        for(long long i=1;i<=9;i++){
            findOrder(n,k,i,flag);
        }
        return flag;
    }
};

/*
Approach-3 (Optimal) - ACCEPTED
T.C : O((logn)^2)
S.C : O(log(n)) system resursion stack
*/

class Solution {
public:
    int Count(long curr, long next, int n) {
        int countNum = 0;
        while(curr <= n) {
            countNum += (next - curr);
            curr *= 10;
            next *= 10;
            next = min(next, long(n+1));
        }
        return countNum;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k -= 1;
        while(k > 0) {
            int count = Count(curr, curr+1, n);
            if(count  <= k) {
                curr++;
                k -= count; 
            } else {
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
};
