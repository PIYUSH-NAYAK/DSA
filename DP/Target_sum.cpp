#include<bits/stdc++.h>

using namespace std;

int ans(int arr[],int n,int sum,int target){
    int new_target=(sum+target)/2;
    int dp[n+1][new_target +1];
    
    

    for(int i=0;i<=n;i++) dp[i][0]=1;
    for(int i=1;i<=new_target;i++) dp[0][i]=0;
    
    

    for(int i=1;i<=n;i++){
        for(int j=1;j<=new_target;j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j] + dp[i-1][j-arr[i-1]];

            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][new_target];
}

int main(){
    int arr[] = {5,9,2,3};
    int sum=19;
    int diff=5;

    cout<<ans(arr,4,sum,diff)<<endl;

}