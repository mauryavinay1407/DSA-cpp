// problem  :  https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1

/*
Approach - By counting the digits at each position
Time Complexity        :  O(N) 
Space Complexity       :  O(1)
*/
class Solution {
public:
    int sumSubstrings(string &s) {
        /*
        H       T       0
                        1
                        2
                        3
                1       2
                2       3
        1       2       3
        
        since we multiplying i + 1 because we need to count how many numbers finish at that pos
        */
        long long int result = 0; 
        long long int mf = 1;
        for (int i=s.size()-1; i>=0; i--){
            result += (s[i]-'0')*(i+1)*mf;
            mf = mf*10 + 1;
        }

        return result;
    }
};
