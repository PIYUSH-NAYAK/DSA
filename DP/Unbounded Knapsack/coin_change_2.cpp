// Min munber of coins for a given sum

#include<bits/stdc++.h>
using namespace std;
int ans(int coin[],int n,int target){
    int dp[n+1][target +1];
    
    for(int i=0;i<=n;i++ ) dp[i][0]=0;
    for(int i=1;i<=target;i++) dp[0][i]=1e9;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(coin[i-1]<=j) dp[i][j]=min(dp[i-1][j],1 + dp[i][j-coin[i-1]]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][target];


}
int main(){

    int coin[]={1,2,5,10};
    cout<<ans(coin,4,25)<<endl;
    
}