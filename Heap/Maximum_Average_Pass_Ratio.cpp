// problem : https://leetcode.com/problems/maximum-average-pass-ratio

/*
Approach-1 : Brute force
Time Complexity:    O(N*extraStudents)
Space Complexity:   O(1)
*/
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        double sum = 0;
        for (auto& c : classes) {
            sum += (double)c[0] / c[1];
        }
        int j;
        while (extraStudents--) {
            double maxGain = -1;
            j = -1;
            for (int i = 0; i < n; i++) {
                double currP = ((double)classes[i][0] / classes[i][1]);
                double newP =
                    ((double)(classes[i][0] + 1) / (classes[i][1] + 1));
                double gain = newP - currP;
                if (gain > maxGain) {
                    maxGain = gain;
                    j = i;
                }
            }
            classes[j][0]++;
            classes[j][1]++;
            sum += maxGain;
        }
        return sum / n;
    }
};
/*
Approach-2 : Using Greedy + Max_heap
Time Complexity:    O(N*logN)
Space Complexity:   O(N)
*/
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        auto gain = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };
        priority_queue<pair<double, pair<int, int>>> pq;
        for (auto& c : classes) {
            pq.push({gain(c[0], c[1]), {c[0], c[1]}});
        }
        while (extraStudents--) {
            int maxGain = pq.top().first;
            int pass = pq.top().second.first;
            int total = pq.top().second.second;
            pq.pop();
            pq.push({gain(pass + 1, total + 1), {pass + 1, total + 1}});
        }
        double sum = 0;
        while (!pq.empty()) {
            auto [maxGain, cl] = pq.top();
            auto [pass, total] = cl;
            pq.pop();
            sum += (double)pass / total;
        }
        return sum / n;
    }
};
