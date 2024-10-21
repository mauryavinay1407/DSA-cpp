// problem:  https://www.geeksforgeeks.org/problems/split-the-array0238/1

/*
Approach: if XOR of entire array is 0 then only it possible 
          there will be 2^n subset of an array in which if we see all the two groups:
          i.e 2^3=8
          G1         G2
          {1}        {2,3}
          {2,3}       {1} (duplicate)
          {2}        {1,3}
          {1,3}       {2} (duplicate)
          {3}        {1,2}
          {1,2}       {3} (duplicate)
          {1,2,3}     {}  (not allowed)
          {}          {1,2,3}  (not allowed)

          conclusion:    We will have only (2^(N)-2)/2  groups  which is equals to 2^(N-1)-1

Time Complexity: O(N)          
Space Complexity:  O(1)     
*/

class Solution {
  public:
    int countgroup(vector<int>& arr) {
        int XOR=0;
        int MOD=1e9+7;
        for(int i=0;i<arr.size();i++)
            XOR^=arr[i];
        if(XOR)
            return 0;
        int result=1;
        for(int i=1;i<arr.size();i++)
            result=(result*2)%MOD;
        return result-1;
    }
};
