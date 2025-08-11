#include <vector>
using namespace std;

class Solution {
public:
    // Recursive helper with memoization and obstacle checking
    int ans(int m, int n, vector<vector<int>> &dp, vector<vector<int>> &gr) {
        if (m >= 0 && n >= 0 && gr[m][n] == 1) return 0;  // Obstacle found, no path
        if (m == 0 && n == 0) return 1;                    // Start point reached
        if (m < 0 || n < 0) return 0;                      // Out of bounds
        if (dp[m][n] != -1) return dp[m][n];              // Return cached result

        // Sum paths from top and left cells
        return dp[m][n] = ans(m - 1, n, dp, gr) + ans(m, n - 1, dp, gr);
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return ans(m - 1, n - 1, dp, obstacleGrid);
    }

    // Optional: classic uniquePaths function without obstacles
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m, vector<int>(n, -1));
    //     return ans(m - 1, n - 1, dp);
    // }
};
