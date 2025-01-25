// problem : Make Lexicographically Smallest Array by Swapping Elements

/*
Approach-1 : Brute force
Time Complexity   :   O(N^3)
Space Complexity  :   O(1)
*/
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            bool swapped = true;
            while (swapped) {
                int idx = -1;
                for (int j = i + 1; j < n; j++) {
                    if (nums[i] > nums[j] && nums[i] - nums[j] <= limit)
                        idx = j;
                }
                if (idx != -1)
                    swap(nums[i], nums[idx]);
                else
                    swapped = false;
            }
        }
        return nums;
    }
};

/*
Approach-2 : Optimal solution using grouping and sorting 
Time Complexity   :   O(N*logN)
Space Complexity  :   O(N)
*/

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> arr = nums;
        sort(arr.begin(),arr.end());
        unordered_map<int,int> Numgroups;
        int countGp = 0;
        Numgroups[arr[0]] = countGp;

        unordered_map<int,list<int>> gpList;
        gpList[countGp].push_back(arr[0]);

        for(int i=1;i<n;i++){
            if(abs(arr[i] - arr[i - 1] > limit))
                countGp++;
            Numgroups[arr[i]] = countGp;
            gpList[countGp].push_back(arr[i]);
        }
        vector<int> result(n);
        for(int i=0;i<n;i++){
            int num = nums[i];
            int grp = Numgroups[num];

            result[i] = *gpList[grp].begin();
            gpList[grp].pop_front();
        }
        return result;
    }
};
