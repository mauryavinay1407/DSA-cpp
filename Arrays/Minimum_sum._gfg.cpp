// problem: https://www.geeksforgeeks.org/problems/minimum-sum4058/1

/*
Approach: sort and add two strings
Time Complexity:   O(N*logN)
Space Complexity:  O(N)
*/

class Solution {
  public:
    string findSum(string x,string y){
        int i = x.length()-1;
        int j = y.length()-1;
        int carry=0;
        string result="";
        while(i >= 0 || j>=0 || carry){
            
            int temp = carry;
            
            if(i >=0)
                temp += x[i--] - '0';
                
            if(j >= 0)
                temp += y[j--] - '0';
           
            carry = temp / 10;
            temp %= 10;
            result.push_back(temp + '0');
        }
        reverse(result.begin(),result.end());
        return result;
    }
    
    string minSum(vector<int> &arr) {
        int n = arr.size();
        if(n == 1)
            return to_string(arr[0]);
        sort(arr.begin(),arr.end());
        int i=0;
        int j=1;
        string first="";
        string second="";
        while(i < n || j < n){
            if(i < n){
                first.push_back(arr[i] + '0');
                i += 2;
            }
            if(j < n){
                second.push_back(arr[j] + '0');
                j += 2;
            }
        }
        string result = findSum(first,second);
        while (result.length() > 1 && result[0] == '0') {
            result.erase(result.begin());
        }
        return result;
    }
};
