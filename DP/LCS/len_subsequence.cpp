#include <bits/stdc++.h>
using namespace std;
int ans(string a,string b,int n,int m,vector<vector<int>> &dp){
    if(n==0 || m==0)return 0;
    if(dp[n][m]!=-1)return dp[n][m];

    if(a[n-1]==b[m-1]) return dp[n][m] =1 + ans(a,b,n-1,m-1,dp);
    else{
        return  dp[n][m] =  max(ans(a,b,n-1,m,dp) ,ans(a,b,n,m-1,dp));
    }
    
}

void solve(){
    string a="abceft";
    string b="bdfgt";

    int n=a.size();
    int m=b.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

    ans(a,b,n,m,dp);
    cout<<dp[n][m]<<endl;
    
}

int main(){
    solve();
    return 0;
}