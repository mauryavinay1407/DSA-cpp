// problem : https://www.geeksforgeeks.org/problems/maximum-sum-combination/1

/*
Approach-1 : Using Sorting + max heap
Time Complexity     :  O(k^2*logk)
Space Complexity    :  O(k)
*/
class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
       
        
        priority_queue<int,vector<int>,greater<int>> minHeap;
        
        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){
                int sum = a[i] + b[j];
                if(minHeap.size()==k && sum < minHeap.top()) break;
                minHeap.push(a[i] + b[j]);
                if(minHeap.size() > k){
                    minHeap.pop();
                }
            }
        }
        vector<int> result;
        while(!minHeap.empty()){
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        
        reverse(result.begin(),result.end());
        return result;
    }
};
/*
Approach-2 :  Using Sorting + max heap + tuple
Time Complexity     :  O(k*logk)
Space Complexity    :  O(k)
*/
class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int m = a.size();
        int n = b.size();
        priority_queue<tuple<int,int,int>> maxHeap;
        maxHeap.push(make_tuple(a[m - 1] + b[n - 1], m - 1, n - 1));
        set<pair<int,int>> visited;
        visited.insert({m - 1, n - 1});
        vector<int> result;
        
        while(k-- && !maxHeap.empty()){
            auto head = maxHeap.top();
            int sum = get<0>(head);
            int i = get<1>(head);
            int j = get<2>(head);
            maxHeap.pop();
            result.push_back(sum);
            
            if(i - 1 >= 0 && !visited.count({i - 1, j})){
                maxHeap.push(make_tuple(a[i - 1] + b[j],i - 1, j));
                visited.insert({i - 1, j});
            }
            
            if(j - 1 >= 0 && !visited.count({i, j - 1})){
                maxHeap.push(make_tuple(a[i] + b[j - 1], i, j - 1));
                visited.insert({i, j - 1});
            }
            
        }
        return result;
    }
};
