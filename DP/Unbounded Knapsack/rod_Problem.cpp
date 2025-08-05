#include<bits/stdc++.h>
using namespace std;

int ans(int arr[],int n){
    int dp[n+1][n+1];
    // int rlen=n;
    int len[]={1,2,3,4,5,6,7,8};
   
    for(int i=0;i<=n;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(len[i-1]<=j){
                dp[i][j]=max(dp[i-1][j],arr[i-1] + dp[i][j-len[i-1]]);
            }
            else dp[i][j]=dp[i-1][j];
            
        }
    }
    return dp[n][n];

}

int main(){
    int price[]= {1,5,8,9,10,17,17,20};
    
    cout<<ans(price,8)<<endl;

    return 0;

}