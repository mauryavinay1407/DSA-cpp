// problem : https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

/*
Approach : sorting and greedy
Time Complexity   :  O(n*logn)
Space Complexity  :  O(n)
*/
class Solution {
public:
    bool static comparator(pair<int,int> a,pair<int,int> b){
        return a.second < b.second;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<pair<int,int>> interval(n);
        for(int i=0;i<n;i++){
            interval[i] = {start[i],end[i]};
        }
        sort(interval.begin(),interval.end(),comparator);
        int result = 1;
        int last = interval[0].second;
        for(int i=1;i<n;i++){
            if(last < interval[i].first){
                result++;
                last = interval[i].second;
            }
        }
        return result;
    }
};
