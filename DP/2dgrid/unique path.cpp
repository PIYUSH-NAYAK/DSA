#include <vector>
using namespace std;

class Solution {
public:
    // Recursive helper function with memoization
    int ans(int m, int n, vector<vector<int>> &dp) {
        if (m == 0 && n == 0) return 1;         // Base case: start point
        if (m < 0 || n < 0) return 0;           // Out of bounds
        if (dp[m][n] != -1) return dp[m][n];   // Return cached result

        // Number of ways = ways from top + ways from left
        return dp[m][n] = ans(m - 1, n, dp) + ans(m, n - 1, dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return ans(m - 1, n - 1, dp);
    }
};
