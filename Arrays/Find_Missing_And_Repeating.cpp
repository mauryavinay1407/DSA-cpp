// problem:  https://www.naukri.com/code360/problems/missing-and-repeating-numbers_6828164

/* 
Approach-1: Using Sorting(Brute force)
Time Complexity: O(nlogn) 
Space Complexity: O(1)
*/

vector<int> findMissingRepeatingNumbers(vector<int> &a) {
    vector<int> ans(2);
    sort(a.begin(), a.end());
    for (int i = 1; i < a.size(); i++) {
        if (a[i] == a[i - 1]) {
            ans[0] = a[i];  // Repeating number
        } else if (a[i] - a[i - 1] > 1) {
            ans[1] = a[i - 1] + 1;  // Missing number
        }
    }
    if (a[0] != 1) ans[1] = 1;            // If missing number is 1
    if (a[a.size() - 1] != a.size()) ans[1] = a.size();  // If missing number is n

    return ans;
}


/* Approach 2
Time Complexity: O(n)
Space Complexity:O(n)
*/

vector<int> findMissingRepeatingNumbers(vector < int > a) {

    vector<int> nums(a.size(),0);
    vector<int> ans;

    for(int i=0;i<a.size();i++){
        nums[a[i]-1]++;
    }

    for(int i=0;i<nums.size();i++){
     if(nums[i]==2)
     ans.push_back(i+1);
    }
    for(int i=0;i<nums.size();i++){
     if(nums[i]==0)
     ans.push_back(i+1);
    }
    return ans;
}          


/*
Approach-3:  To find only missing number(visited method)
Time: O(n)
Space:O(n)
*/
vector<int> findMissing(vector<int> nums,int n){
  vector<int> missings;
   for(int i=0;i<n;i++){
     int index=abs(nums[i]);
     if(nums[index-1]>0)
       nums[index-1]*= -1;
   }

  for(int i=0;i<n;i++){
    if(nums[i]>0)
      missings.push_back(i+1);
  }
  return missings;
}



