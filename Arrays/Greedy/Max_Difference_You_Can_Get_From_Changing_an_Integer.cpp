//  problem : https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer

/*
Approach-1 : replacing with 9 for maximum and carefully minimizing the number using greedy
Time Complexity       :  O(log10(num))
Space Complexity      :  O(log10(num))
*/
class Solution {
public:
    int maxDiff(int num) {
        string str = to_string(num);
        int n = str.length();
        if (n == 1)
            return 8;

        char xMax;
        for (auto& s : str) {
            if (s != '9') {
                xMax = s;
                break;
            }
        }
        string maxStr = "";
        for (auto& s : str) {
            if (s == xMax) {
                maxStr += '9';
            } else {
                maxStr += s;
            }
        }
        char xMin;

        int i = 0;
        while (str[i] == '1' || str[i] == '0') {
            i++;
        }
        if (i < str.length()) {
            xMin = str[i];
        }
        bool flag = false;
        if (i > 0) {
            flag = true;
        }
        string minStr = "";
        for (auto& s : str) {
            if (s == xMin) {
                minStr += flag ? '0' : '1';
            } else {
                minStr += s;
            }
        }
        return stoi(maxStr) - stoi(minStr);
    }
};

/*
Approach-2 : replacing with 9 for maximum and carefully minimizing the number using greedy(using STL)
Time Complexity       :  O(log10(num))
Space Complexity      :  O(log10(num))
*/
class Solution {
public:
    int maxDiff(int num) {
        string str1 = to_string(num);
        string str2 = str1;

        int idx = str1.find_first_not_of('9');
        if(idx != string::npos) {
            char ch = str1[idx];
            replace(begin(str1), end(str1), ch, '9');
        }

        //We can't directly choose 0th index character and make it 0
        //because qn says we can't have leading zeros
        for(int i = 0; i < str2.length(); i++) {
            char ch = str2[i];
            if(i == 0) {
                if(ch != '1') {
                    replace(begin(str2), end(str2), ch, '1');
                    break;
                }
            } else if(ch != '0' && ch != str2[0]) {
                //example : 111, even if we skip 1 at str2[0], we see again at str2[1]
                //But we can't change 1 to 0 because it will replace 1 of str2[0] as well
                replace(begin(str2), end(str2), ch, '0');
                break;
            }
        }
        return stoi(str1) - stoi(str2);
    }
};
