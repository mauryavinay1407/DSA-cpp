//  problem  :  https://www.geeksforgeeks.org/problems/k-closest-elements3619/1

/*
Approach - Using max heap
Time Complexity      : O(N*logk + klogk)
Space Complexity     : O(1)
*/
class Solution {
public:
    using P = pair<int,int>;
    
    struct comparator{
        bool operator()(const P& a,const P& b){
            if(a.first == b.first){
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        priority_queue<P,vector<P>,comparator> maxHeap;
        
        for(int i=0;i<arr.size();i++){
            int diff = abs(x - arr[i]);
            
            if(diff){
                maxHeap.push({diff,arr[i]});
            }
            
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        
        vector<int> result(k);
        int i = k - 1;
        while(!maxHeap.empty()){
            result[i--] = maxHeap.top().second;
            maxHeap.pop();
        }
        
        return result;
    }
};
