// problem:  https://leetcode.com/problems/counting-bits/description/

/*
Approach:1
Time complexity: O(n*logn)
Space complexity: O(1) (not assuming space of result vector)
*/

class Solution {
public:
   vector<int> countBits(int n) {
	vector<int> ans{0};
	int i=1;
	while(i<=n) {
		int count=0;
		int num=i;
		while(num) {
			if(num & 1)
				count++;
			num>>=1;
		}
		ans.push_back(count);
		i++;
	}
	return ans;
}
};

/*
Approach:2 (Using __builtin_popcount)
Time complexity: O(n)
Space complexity: O(1) (not assuming space of result vector)
*/
class Solution {
public:
   vector<int> countBits(int n) {
	vector<int> ans(n+1);
	for(int i=0;i<n+1;i++)
    ans[i]=__builtin_popcount(i);
    
	return ans;
}
};

/*
Approach:3 
Time complexity: O(n)
Space complexity: O(1) (not assuming space of result vector)
*/
class Solution {
public:
   vector<int> countBits(int n) {
	vector<int> ans(n+1);
    ans[0]=0;
	for(int i=1;i<n+1;i++)
    ans[i]=ans[i>>1]+(i&1); // i>>1 will give half of the number
  /*
  8 - 1000-no of 1(1)
  4 - 100 -no of 1(1)+ last bit(n & 1 )
  9 - 1001 - no of 1(2)
   9/2=4-no of 1(1) + last bit(1)
  */    
	return ans;
}
};
