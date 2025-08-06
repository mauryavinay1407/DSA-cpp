// problem  :  https://leetcode.com/problems/fruits-into-baskets-iii

/*
Approach - 1 : Brute Force(Fruits Into Baskets II)
Time Complexity       :  O(N^2)
Space Complexity      :  O(1)
*/
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            bool placed = false;
            for (int j = 0; j < n; j++) {
                if (fruits[i] <= baskets[j]) {
                    placed = true;
                    baskets[j] = -1;
                    break;
                }
            }
            if (!placed) {
                result++;
            }
        }
        return result;
    }
};
/*
Approach - 2 : using segment tree
Time Complexity       :  O(N*logN)
Space Complexity      :  O(N)
*/
class Solution {
public:
    void build(int i, int l, int r, vector<int>& segmentTree,vector<int>& baskets) {
        if (l == r) {
            segmentTree[i] = baskets[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * i + 1, l, mid, segmentTree, baskets);
        build(2 * i + 2, mid + 1, r, segmentTree, baskets);

        segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
    }

    bool checkIfPossible(int i, int l, int r, vector<int>& segmentTree,int fruit) {
        if (segmentTree[i] < fruit)
            return false;
        if (l == r) {
            segmentTree[i] = -1;
            return true;
        }
        bool placed = false;
        int mid = l + (r - l) / 2;
        if (segmentTree[2 * i + 1] >= fruit) {
            placed = checkIfPossible(2 * i + 1, l, mid, segmentTree, fruit);
        } else {
            placed = checkIfPossible(2 * i + 2, mid + 1, r, segmentTree, fruit);
        }
        segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);

        return placed;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        vector<int> segmentTree(4 * n);
        build(0, 0, n - 1, segmentTree, baskets);

        int result = 0;
        for (auto& fruit : fruits) {
            if (!checkIfPossible(0, 0, n - 1, segmentTree, fruit)) {
                result++;
            }
        }
        return result;
    }
};
