#include<bits/stdc++.h>
using namespace std;
int ans(int arr[],int n,int sm){
    int k[n+1][sm/2  + 1];
    for(int i=0;i<=n;i++) k[i][0]=true;
    for(int i=1;i<=sm/2;i++) k[0][i]=false;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sm/2;j++){
            if(arr[i-1]<=j) {
                k[i][j]=k[i-1][j] || k[i-1][j-arr[i-1]];

            }
            else {
                k[i][j]=k[i-1][j];
            }
        }
    }
    int an=INT_MAX;
    for(int i=sm/2;i>=0;i--){
        if(k[n][i]){
            an=min(an,(sm-2*i));
            break;


        }
    }
    
    return an;



}

int main(){
    int arr[] = { 4,6,1,7,9,2,4};
    cout<<ans(arr,7,33)<<endl;
}