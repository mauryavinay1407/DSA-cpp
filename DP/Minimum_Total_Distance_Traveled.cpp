// problem:  https://leetcode.com/problems/minimum-total-distance-traveled

/*
Approach-1: using sorting and 3D Dp
Time Complexity:   O(N*M*K)
Space Complexity:  O(N*M*K)
*/

class Solution {
public:
    vector<vector<vector<long long>>> dp;

    long long findMinimumDistance(vector<int>& robot,vector<vector<int>>& factory, int i, int j,int k) {
        if (i >= robot.size())
            return 0;
        if (j >= factory.size())
            return LLONG_MAX;

        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        long long moves = LLONG_MAX;

        if (j + 1 < factory.size()) {
            moves = findMinimumDistance(robot, factory, i, j + 1, factory[j + 1][1]);
        }

        if (k > 0) {
            long long dist = abs(factory[j][0] - robot[i]);
            long long next_moves = findMinimumDistance(robot, factory, i + 1, j, k - 1);
            if (next_moves != LLONG_MAX)
                moves = min(moves, dist + next_moves);
        }

        return dp[i][j][k] = moves;
    }

    long long minimumTotalDistance(vector<int>& robot,vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int maxCapacity = 0;
        for (const auto& f : factory)
            maxCapacity = max(maxCapacity, f[1]);

        dp.assign(robot.size(),vector<vector<long long>>(factory.size(), vector<long long>(maxCapacity + 1, -1)));

        return findMinimumDistance(robot, factory, 0, 0, factory[0][1]);
    }
};

/*
Approach-2:  By converting the factory and frequency into a single array i.e. factory = [[2,2],[6,2],[5,3]  into factories= [2,2,5,5,5,6,6]
Time Complexity:    O(M*N)
Space Complexity:   O(M*N)
*/

class Solution {
public:
    using ll = long long;
    int m, n;
    ll findMinimumDistance(vector<int>& robot, vector<int>& factories, int currRobot, int currFactory, vector<vector<ll>>& dp) {
        if (currRobot >= m)
            return 0;
        if (currFactory >= n)
            return 1e16;
        if (dp[currRobot][currFactory] != -1)
            return dp[currRobot][currFactory];
        long long taken = abs(factories[currFactory] - robot[currRobot]) +findMinimumDistance(robot, factories, currRobot + 1,
                                              currFactory + 1, dp);
        long long skip = findMinimumDistance(robot, factories, currRobot,
                                             currFactory + 1, dp);

        return dp[currRobot][currFactory] = min(taken, skip);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        vector<int> factories;
        for (auto& f : factory) {
            int t = f[1];
            while (t--)
                factories.push_back(f[0]);
        }
        sort(robot.begin(), robot.end());
        sort(factories.begin(), factories.end());

        m = robot.size();
        n = factories.size();
        vector<vector<ll>> dp(m, vector<ll>(n, -1));

        return findMinimumDistance(robot, factories, 0, 0, dp);
    }
};
