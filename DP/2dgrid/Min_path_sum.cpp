#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans(int m,int n, vector<vector<int>> &dp,vector<vector<int>> &grid){
        if(m==0 && n==0) return grid[0][0];
        if(m<0 || n<0)return INT_MAX ;

        if(dp[m][n]!=-1) return dp[m][n];
        int top=ans(m-1,n,dp,grid);
        int left=ans(m,n-1,dp,grid);

        if(top==INT_MAX && left==INT_MAX) return INT_MAX;

        return dp[m][n]= grid[m][n] + min(left,top);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return ans(m-1,n-1,dp,grid);
        
    }
};