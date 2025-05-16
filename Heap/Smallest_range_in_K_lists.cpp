//  problem   :  https://www.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1

/*
Approach - Using Min heap
Time Complexity      :  O(N*M*logN) 
Space Complexity     :  O(N)
*/

class Solution {
  public:
    using Node = pair<int, pair<int, int>>; // {value, {rowIndex, colIndex}}
    vector<int> findSmallestRange(vector<vector<int>>& matrix) {
    priority_queue<Node, vector<Node>, greater<Node>> minHeap;
    unordered_map<int, int> freqMap;
    queue<pair<int, int>> consumerQueue; // {value, rowIndex}

    int totalRows = matrix.size();
    int totalCols = matrix[0].size();

    int minRange = INT_MAX;
    vector<int> resultRange = {-1, -1};

    // Push the first element of each row into the minHeap
    for (int row = 0; row < totalRows; ++row) {
        minHeap.push({matrix[row][0], {row, 0}});
    }

    while (!minHeap.empty()) {
        int currentVal = minHeap.top().first;
        int rowIndex = minHeap.top().second.first;
        int colIndex = minHeap.top().second.second;
        minHeap.pop();

        consumerQueue.push({currentVal, rowIndex});
        freqMap[rowIndex]++;

        // Push next element from the same row into the minHeap
        if (colIndex + 1 < totalCols) {
            minHeap.push({matrix[rowIndex][colIndex + 1], {rowIndex, colIndex + 1}});
        }

        // Try shrinking the window if all rows are represented
        while (freqMap.size() == totalRows) {
            int startVal = consumerQueue.front().first;
            int endVal = consumerQueue.back().first;

            if (endVal - startVal < minRange) {
                minRange = endVal - startVal;
                resultRange = {startVal, endVal};
            }

            int frontRow = consumerQueue.front().second;
            consumerQueue.pop();
            freqMap[frontRow]--;

            if (freqMap[frontRow] == 0) {
                freqMap.erase(frontRow);
            }
        }
    }

    return resultRange;
}

};
