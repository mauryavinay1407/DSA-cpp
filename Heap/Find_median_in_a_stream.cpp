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
