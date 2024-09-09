/*
Time: O(logN)
Space: O(1)
Approach: To find the `n`th number, consider that skipping the digit `9` resembles a base system operation:

-   If you think about numbers in base 10, they include digits `0-9`.
-   If you remove the digit `9`, you're left with `0-8`, resembling a base-9 number system.
-   When you convert a number to base-9, it won't include the digit `9` because base-9 only uses digits `0-8`.
-   This means you can directly map the `n`th number in the sequence to its base-9 equivalent.
*/
  class Solution {
  public:
    long long findNth(long long n) {
    long long ans=0;
    long long base=1;
    
    while(n>0){
    ans+=(n%9)*base;
    n/=9;
    base*=10;
    }
    return ans;
    }
};
