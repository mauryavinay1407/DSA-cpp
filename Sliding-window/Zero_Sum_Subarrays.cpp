// problem:  https://www.geeksforgeeks.org/problems/zero-sum-subarrays1825/1

/*
Approach-1:  Brute force
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class Solution{
public:
   long long int findSubarray(vector<long long int> &arr, int n) {
    long long int count = 0;

    for (int i = 0; i < n; i++) {
        long long int sum = 0;

        for (int j = i; j < n; j++) {
            sum += arr[j];

            if (sum == 0) {
                count++;
            }
        }
    }
    return count;
}
};


/*
Approach-2:  Using prefix sum
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        unordered_map<int,int> mp;
        mp[0]=1;
        long long int sum=0,count=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            
            if(mp.count(sum)){
                count+=mp[sum];
                mp[sum]++;
            }
            else
             mp[sum]=1;
        }
        return count;
    }
};
