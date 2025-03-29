// problem : https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

/*
Approach-1 Using sorting
Time Complexity    :  O(N^2)
Space Complexity   :  O(d)
*/


class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        vector<pair<int,int>> jobs;
        for(int i=0;i<deadline.size();i++){
            jobs.push_back({profit[i],deadline[i]});
        }
        sort(jobs.rbegin(),jobs.rend());
        
        int maxi = *max_element(deadline.begin(),deadline.end());
        vector<int> done(maxi+1,-1);
        int sum = 0,count=0;
        for(auto& job : jobs){
            int x = job.second;
            int prof = job.first;
            while(x){
                if(done[x] == -1){
                    done[x] = prof;
                    count++;
                    sum += prof;
                    break;
                }
                x--;
            }
        }
        return {count,sum};
    }
};
/*
Approach-1 Using sorting
Time Complexity    :  O(N*logd)
Space Complexity   :  O(d)
*/

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        vector<pair<int,int>> jobs;
        for (int i = 0; i < deadline.size(); i++) {
        jobs.push_back({deadline[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());
    
        priority_queue<int, vector<int>, greater<int>> pq;
    
        for (const auto &job : jobs) {
            
            if (job.first > pq.size())
                pq.push(job.second);
            
            else if (!pq.empty() && pq.top() < job.second) {
                pq.pop();
                pq.push(job.second);
            }
        }
        int count = pq.size();
        int sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    
        return {count,sum};
    }
};
