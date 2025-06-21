// problem  :  https://www.geeksforgeeks.org/problems/police-and-thieves--141631/1

/*
Approach - Using Queue + Greedy
Time Complexity       :   O(N)
Space Complexity      :   O(N)
*/
class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int n = arr.size();
        queue<int> police, thieves;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 'P') {
                police.push(i);
            }
            else if (arr[i] == 'T') {
                thieves.push(i);
            }

            while (!police.empty() && !thieves.empty()) {
                int p = police.front();
                int t = thieves.front();
                if (abs(p - t) <= k) {
                    count++;
                    police.pop();
                    thieves.pop();
                } else {
                    if (p < t)
                        police.pop();
                    else
                        thieves.pop();
                }
            }
        }
        return count;
    }
};
