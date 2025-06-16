// problem  :  https://www.geeksforgeeks.org/problems/equalize-the-towers2804/1

/*
Approach - Greedy + Binary Search on Answer (Unimodal Optimization)
Time Complexity      : O(N*logR)     where  let the range = R = max - min
Space Complexity     : O(1)
*/
class Solution {
public:
    int findCost(vector<int>& heights,vector<int>& cost,int mid){
        int totalCost = 0;
        
        for(int i=0;i<heights.size();i++){
            totalCost += abs(heights[i] - mid) * cost[i];
        }
        
        return totalCost;
    }
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int start = *min_element(heights.begin(),heights.end());
        int end = *max_element(heights.begin(),heights.end());
        
        while(start < end){
            int mid = start + (end - start)/2;
            
            int cost1 = findCost(heights,cost,mid);
            int cost2 = findCost(heights,cost,mid + 1);
            
            if(cost1 > cost2){
                start = mid + 1;
            }
            else{
                end = mid;
            }
        }
        return findCost(heights,cost,start);
    }
};
