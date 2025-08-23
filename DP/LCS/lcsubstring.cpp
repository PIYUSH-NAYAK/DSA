#include <bits/stdc++.h>
using namespace std;

void solve(){
    string a="abnghiko";
    string b="ajfibcfghi";

    int n=a.size();
    int m=b.size();

    vector<vector<int>> dp(n+1,vector<int> (m+1));
    int ans=INT_MIN;
    for(int i=0;i<n;i++)dp[i][0]=0;
    for(int i=1;i<m;i++)dp[0][i] =0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){dp[i][j]=1+dp[i-1][j-1];
            ans=max(ans,dp[i][j]);
            }
            else dp[i][j]=0;
        }
    }
    cout<< ans<<endl;
    
}

int main(){
    solve();
    return 0;
}