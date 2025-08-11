#include <bits/stdc++.h>
using namespace std;

int ans(vector<vector<int>> &fin,int last,int n,vector<vector<int>> &dp){

    if(n==0){
        int ans=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                ans=max(fin[0][i],ans) ;
            }
        }
        return dp[n][last]=ans;
    }
    if(dp[n][last]!=-1) return dp[n][last];
    int res=0;
    for(int i=0;i<3;i++){
        if(i!=last){
            int pt= fin[n][i] + ans(fin,i,n-1,dp);
            res=max(res,pt);
        }
    }
    return dp[n][last]= res;
}

int main() {

    int n=4;
    vector<vector<int>> points = {
        {2, 1, 3},  // Day 1
        {3, 4, 6},  // Day 2
        {10, 1, 6}, // Day 3
        {8, 3, 7}   // Day 4
    };

    vector<vector<int>> dp(n,vector<int>(n,-1));

    cout<<ans(points,3,n-1,dp)<<endl;

    // You can now run your DP function on 'points'
}
