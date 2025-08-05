// given many type of coins
// target sum given 
//ouput number of ways 

#include<bits/stdc++.h>

using namespace std;

int ans(int arr[],int n,int target){
    int dp[n+1][target + 1];
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=target;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(arr[i-1]<=j)
                dp[i][j]=(dp[i-1][j] + dp[i][j-arr[i-1]]);
            else
                dp[i][j]=dp[i-1][j];
            

        }
    }

    return dp[n][target];
}

int main(){
    int coins[] = {1,2,5,10};
    cout<<ans(coins,4,12)<<endl;
}