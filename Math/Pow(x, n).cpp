// problem: https://leetcode.com/problems/powx-n/description/

/*
Approach-1: Brute Force 
*/
class Solution {
public:
double myPow(double x, int n) {
      double ans=1.0;
      long long exponent=n;
      if(exponent<0){
          exponent = -exponent;
           double temp=1.0;
          for(long long i=0;i<exponent;i++)
          temp*=x;
          ans/=temp;
      }
      else{
          for(long long i=0;i<exponent;i++)
          ans*=x;
      }
      return ans;
    }
};

/*
Approach-2: Optimal solution
*/
class Solution {
public:
    double findPow(double x,long n){
        if(n==0)
        return 1;
        if(n<0)
        return findPow(1/x,-n);
        if(n%2==0)
          return findPow(x*x,n/2);
        else
          return x*findPow(x*x,(n-1)/2);
    }
double myPow(double x, int n) {
     return findPow(x,(long)n);
    }
};
