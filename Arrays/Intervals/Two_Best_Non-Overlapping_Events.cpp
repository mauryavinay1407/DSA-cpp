// problem:  https://leetcode.com/problems/two-best-non-overlapping-events

/*
Approach-1:  Brute force (TLE)
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
