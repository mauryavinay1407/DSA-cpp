// problem  :  https://leetcode.com/problems/maximum-difference-by-remapping-a-digit

/*
Approach - Using Greedy Digit Replacement 
Time Complexity       :   O(log₁₀ num)     where base is 10 and it is representing the number of digits in num (as we all know no. of digits in num = log₁₀ num)
Space Complexity      :   O(log₁₀ num)
*/
class Solution {
public:
    int minMaxDifference(int num) {
        string actualNum = to_string(num);

        char forMax;
        char forMin = actualNum[0];
        for (auto& s : actualNum) {
            if (s != '9') {
                forMax = s;
                break;
            }
        }
        string maxi = "";
        string mini = "";
        for (auto& s : actualNum) {
            if (s == forMax) {
                maxi += '9';
            } else {
                maxi += s;
            }
            if (s == forMin) {
                mini += '0';
            } else {
                mini += s;
            }
        }
        return stoi(maxi) - stoi(mini);
    }
};
