#include <bits/stdc++.h>
using namespace std;

void solve(){
    string a="abcfrg";
    string b="babcfg";

    int n=a.size();
    int m=b.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1) );

    for(int i=0;i<n+1;i++)dp[i][0]=0;
    for(int i=1;i<=m;i++)dp[0][i]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1])dp[i][j]=1 + dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j] , dp[i][j-1]);
        }
    }
    int i=n,j=m;
    string s="";
    while(i>0 && j > 0){
        if(a[i-1]==b[j-1]) s.push_back(a[i-1]), i--,j--;
        else{
            if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
    }
    reverse(s.begin(),s.end());
    cout<<s<<endl;

}

int main(){
    solve();
    return 0;
}