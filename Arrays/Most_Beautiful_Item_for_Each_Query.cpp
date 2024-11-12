// problem : https://leetcode.com/problems/most-beautiful-item-for-each-query
/*
Approach-1:  using sorting
Time Complexity:  O(Q*N)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> result;
        sort(begin(items),end(items));
        for(auto& q : queries){
            int val = INT_MIN;
            for(auto& item: items){
                int price = item[0];
                int beauty = item[1];
                if(price <= q)
                    val = max(val,beauty);
                else
                    break;
            }
            result.push_back(val==INT_MIN ? 0 : val);
        }
        return result;
    }
};

/*
Approach-2:  using sorting + storing queries real index
Time Complexity:  O(QlogQ + NlogN)
Space Complexity: O(Q)
*/

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        int n = queries.size();
        vector<int> result(n);
        vector<pair<int, int>> realQ;
        for (int i = 0; i < n; i++) {
            realQ.push_back({queries[i], i});
        }
        sort(begin(items), end(items));
        sort(begin(realQ), end(realQ));

        int index = 0;
        int val = 0;
        for (auto& qry : realQ) {
            int q = qry.first;
            int realIndex = qry.second;
            for (int i = index; i < items.size(); i++) {
                int price = items[i][0];
                int beauty = items[i][1];
                if (price <= q) {
                    val = max(val, beauty);
                    index = i;
                } else
                    break;
            }
            result[realIndex] = val;
        }
        return result;
    }
};
