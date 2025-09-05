// problem:  https://leetcode.com/problems/two-best-non-overlapping-events

/*
Approach-1:  Brute force (Time Limit Exceed)
Time Complexity    :  O(N^2)
Space Complexity   :  O(1)
*/
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int result=0;
        for(int i=0;i<events.size();i++){
            int value = events[i][2];
            result = max(result,value);
            for(int j=0;j<events.size();j++){
                if(i == j || (events[i][0] <= events[j][1] && events[i][1] >= events[j][0]))
                    continue;
                result = max(result, value + events[j][2]);
            }
        }
        return result;
    }
};

/*
Approach-2:  Using Max-heap
Time Complexity    :  O(N*logN)
Space Complexity   :  O(N)
*/
class Solution {
public:
    using P = pair<int,int>;
    int maxTwoEvents(vector<vector<int>>& events) {
        priority_queue<P,vector<P>,greater<P>> pq;
        sort(events.begin(),events.end());
        int result=0;
        int maxi = 0;
        for(auto& event : events){
            while(!pq.empty() && pq.top().first < event[0]){
                maxi = max(maxi,pq.top().second);
                pq.pop();
            }
            result = max(result, maxi + event[2]);
            pq.push({event[1],event[2]});
        }
        return result;
    }
};
/*
Approach-3:  Using Binary search and Dynamic Programming
Time Complexity    :  O(N*logN)
Space Complexity   :  O(N)
*/
class Solution {
public:
    int dp[100001][3];
    int Binary_search(vector<vector<int>>& events, int end) {
        int l = 0;
        int h = events.size() - 1;
        int result = events.size();
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (events[mid][0] > end) {
                result = mid;
                h = mid - 1;
            } else
                l = mid + 1;
        }
        return result;
    }
    int findMax(vector<vector<int>>& events, int i, int count) {
        if (i >= events.size() || count == 2)
            return 0;
        if (dp[i][count] != -1)
            return dp[i][count];

        int Index = Binary_search(events, events[i][1]);
        int taken = events[i][2] + findMax(events, Index, count + 1);
        int skip = findMax(events, i + 1, count);

        return dp[i][count] = max(taken, skip);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        memset(dp, -1, sizeof(dp));
        return findMax(events, 0, 0);
    }
};
