// problem  :  https://www.geeksforgeeks.org/problems/sort-the-given-array-after-applying-the-given-equation0304/1

/*
Approach - Using simple simulation
Time Complexity        :  O(N*logN)
Space Complexity       :  O(1)
*/
class Solution {
public:
    int evaluate(int x,int A,int B,int C){
        return A*(x*x) + B*x + C;
    }
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        vector<int> result;
        for(int i=0;i<arr.size();i++){
            result.push_back(evaluate(arr[i],A,B,C));
        }
        sort(result.begin(),result.end());
      
        return result;
    }
};
