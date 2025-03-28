// problem : https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1

/*
Approach- Using Greedy 
Time Complexity     :   O(N*logN)
Space Complexity    :   O(N)
*/

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        vector<vector<int>> interval;
        for(int i=0;i<start.size();i++){
            interval.push_back({finish[i],start[i]});
        }
        sort(interval.begin(),interval.end());
        
        int end =-1;
        int result = 0;
        for(int i=0;i<interval.size();i++){
            if(interval[i][1] > end){
                result++;
                end = interval[i][0];
            }
        }
        return result;
    }
};
