// problem : https://www.geeksforgeeks.org/problems/next-element-with-greater-frequency--170637/1

/*
Approach - Using hashmap + stack
Time Complexity        : O(N)
Space Complexity       : O(N)
*/
class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
          // code here
        unordered_map<int, int> freq;
        for(auto i : arr){
            freq[i]++;
        }
        int size = arr.size();
        stack<int> st;
        vector<int> result(size, -1);
        for(int i = size - 1; i >= 0; i--){
            while(!st.empty() && freq[st.top()] <= freq[arr[i]]){
                st.pop();
            }
            
            if(!st.empty()){
                result[i] = st.top();
            }
            
            st.push(arr[i]);
        }
        return result;
    }
};
//////////////////////////////////////////// OR ////////////////////////////////////////////////////////////
// my simple template(with same time and space) :
class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_map<int,int> mp;
        for(auto& num : arr){
            mp[num]++;
        }
        vector<int> result(n, -1);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && mp[arr[i]] > mp[arr[st.top()]]){
                result[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};
