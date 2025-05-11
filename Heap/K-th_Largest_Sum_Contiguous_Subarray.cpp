// problem  :  https://www.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1

/*
Approach - 1 : Brute Force using max heap
Time Complexity      :  O(N^2*logN)
Space Complexity     :  O(N^2)
*/
class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> maxHeap(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            int sum = arr[i];
            for(int j=i+1;j<arr.size();j++){
                sum += arr[j];
                maxHeap.push(sum);
            }
        }
        int result;
        while(k--){
            result = maxHeap.top();
            maxHeap.pop();
        }
        return result;
    }
};

/*
Approach - 2 : Optimal using Min-heap
Time Complexity      :  O(N^2*logk)
Space Complexity     :  O(k)
*/

class Solution {
public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int n = arr.size();

        for(int i = 0; i < n; ++i){
            int sum = 0;
            for(int j = i; j < n; ++j){
                sum += arr[j];
                if(minHeap.size() < k){
                    minHeap.push(sum);
                } else if(sum > minHeap.top()){
                    minHeap.pop();
                    minHeap.push(sum);
                }
            }
        }
        return minHeap.top();
    }
};

