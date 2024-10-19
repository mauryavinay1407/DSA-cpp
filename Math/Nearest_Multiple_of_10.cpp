// problem:  https://www.geeksforgeeks.org/problems/nearest-multiple-of-102437/1

/*
Approach-1 : Brute Force
Time Complexity: O(N)
Space Complexity: O(N)
*/
class Solution {
  public:
    string roundToNearest(string str) {
        int num=stoi(str);
        int rem=num%10;
        int temp=10-rem;
        if(temp>5)
            return to_string(num-temp);
        else
            return to_string(num+temp);
    }
};

/*
Approach-2 : Optimal solution
Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
  public:
    string roundToNearest(string str) {
        int n = str.length();
        char last = str[n - 1];
    
        if(last<='5'){
            str[n-1]='0';
            return str;
        }
        else{
            str[n-1]='0';
            int i=n-2;
            for(;i>=0;--i){
                if(str[i]=='9')
                    str[i]='0';
                else{
                    str[i]++;
                    break;
                }
            }
            if(i<0)
                str='1'+str;
        }
        return str;
    }
};
