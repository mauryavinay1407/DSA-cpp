// problem : https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1

/*
Approach- Using Greedy method
Time Complexity     : O(N)
Space Complexity    : O(1)
*/

class Solution {
public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int totalFuel = 0, currentFuel = 0, startIndex = 0;
    
        for (int i = 0; i < gas.size(); i++) {
            totalFuel += gas[i] - cost[i];
            currentFuel += gas[i] - cost[i];
    
            if (currentFuel < 0) {
                startIndex = i + 1;
                currentFuel = 0;
            }
        }
    
        return (totalFuel >= 0) ? startIndex : -1;
    }
};
