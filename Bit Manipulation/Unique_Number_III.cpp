// problem   :  https://www.geeksforgeeks.org/problems/find-element-occuring-once-when-all-other-are-present-thrice/1

/*
Approach - By counting the set bits
Time Complexity       :  O(N)
Space Complexity      :  O(1)
*/

class Solution {
  public:
    int getSingle(vector<int> &arr) {
        int result = 0;
        for(int i=0;i<32;i++){
            int count = 0;
            for(auto& num : arr){
                if((num >> i) & 1){
                    count++;
                }
            }
            if(count%3 != 0){
                result += (1 << i);
            }
        }
        return result;
    }
};
