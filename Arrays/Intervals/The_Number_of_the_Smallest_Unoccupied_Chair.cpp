// problem:  https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/description/

/*
Approach-1: Brute force 
Time Complexity: O(N^2)
Space Complexity: O(N)
*/

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int friendArrival = times[targetFriend][0];
        sort(begin(times), end(times));
        int result = -1;
        vector<int> deps(times.size(), 0);
        for (int i = 0; i < times.size(); i++) {
            int arrival = times[i][0];
            int depart = times[i][1];
            for (int j = 0; j < deps.size(); j++) {
                if (arrival >= deps[j]) {
                    deps[j] = depart;
                    if (arrival == friendArrival)
                        result = j;
                    break;
                }
            }
        }
        return result;
    }
};

/*
Approach-2: using min-heap 
Time Complexity: O(N*logN)
Space Complexity: O(N)
*/

class Solution {
public:
    using P = pair<int, int>;
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int friendArrivalTime = times[targetFriend][0];
        sort(begin(times), end(times));
        priority_queue<P, vector<P>, greater<P>> occupiedChairs;
        priority_queue<int, vector<int>, greater<int>> freeChairs;
        int chair = 0;

        for (int i = 0; i < times.size(); i++) {
            int arrival = times[i][0];
            int depart = times[i][1];
            while (!occupiedChairs.empty() &&
                   occupiedChairs.top().first <= arrival) {
                freeChairs.push(occupiedChairs.top().second);
                occupiedChairs.pop();
            }

            if (freeChairs.empty()) {
                occupiedChairs.push({depart, chair});
                if (arrival == friendArrivalTime)
                    return chair;
                chair++;
            } else {
                int chairAvailable = freeChairs.top();
                freeChairs.pop();
                if (arrival == friendArrivalTime)
                    return chairAvailable;
                occupiedChairs.push({depart, chairAvailable});
            }
        }

        return -1;
    }
};
