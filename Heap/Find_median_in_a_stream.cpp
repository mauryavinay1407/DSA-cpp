// problem :  https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1

/*
Approach-1 : Brute Force
Time Complexity    :   O(N^2)
Spacd Complexity   :   O(N)
*/
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        vector<double> result;
        multiset<int> st;
        for(int i=0;i<arr.size();i++){
            st.insert(arr[i]);
            if(i % 2 != 0){
                int x = i / 2;
                int a = *(next(st.begin(),x));
                int b = *(next(st.begin(),x+1));
                result.push_back((a+b)/2.0);
            }
            else{
                int a = *(next(st.begin(),i/2));
                result.push_back(a*1.0);
            }
        }
        return result;
    }
};

/*
Approach-2 : Optimal using Multiset
Time Complexity    :   O(N*logN)
Spacd Complexity   :   O(1)
*/
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        vector<double> result;
        multiset<int> st;
        auto median = st.begin(); // Iterator to track the median

        for (int i = 0; i < arr.size(); i++) {
            st.insert(arr[i]);

            if (st.size() == 1) {
                median = st.begin();
            } 
            else if (arr[i] < *median) { 
                // Inserted in left half
                if (st.size() % 2 == 0) median--;  // Move left when size is even
            } 
            else {
                // Inserted in right half
                if (st.size() % 2 != 0) median++;  // Move right when size is odd
            }

            // Compute median
            if (st.size() % 2 != 0) { // Odd size
                result.push_back(*median);
            } 
            else { // Even size
                result.push_back((*median + *next(median)) / 2.0);
            }
        }
        return result;
    }
};


/*
Approach-3 : Optimal using Heap
Time Complexity    :   O(N*logN)
Spacd Complexity   :   O(1)
*/
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
       vector<double> result;
        priority_queue<int> maxHeap; // Left part (lower half)
        priority_queue<int, vector<int>, greater<int>> minHeap; // Right part (higher half)

        for (int num : arr) {
            if (maxHeap.empty() || num <= maxHeap.top()) {
                maxHeap.push(num);
            } else {
                minHeap.push(num);
            }

            // Balance the heaps
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            // Get median
            if (maxHeap.size() == minHeap.size()) {
                result.push_back((maxHeap.top() + minHeap.top()) / 2.0);
            } else {
                result.push_back(maxHeap.top());
            }
        }
        return result;
    }
};
