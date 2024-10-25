// problem:  https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/description/

/*
Approach: Using sorting
Time Complexity:    O(N*log(N))
Space Complexity:   O(1)
*/

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> result;
        sort(folder.begin(), folder.end());
        result.push_back(folder[0]);
        for (int i = 1; i < folder.size(); i++) {
            int left = 0, right = 0;
            string temp = result.back();
            while (left < temp.size() && right < folder[i].size() &&
                   temp[left] == folder[i][right]) {
                left++;
                right++;
            }
            if (left < temp.size() && right < folder[i].size())
                result.push_back(folder[i]);
            else if (left >= temp.size() && folder[i][right] != '/')
                result.push_back(folder[i]);
        }
        return result;
    }
};
