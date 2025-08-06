#include<bits/stdc++.h>
using namespace std;
int count(int arr[],int n,int t){
    int k[n+1][t+1];
    for(int i=0;i<=n;i++){
        k[i][0]=1;
    }
    for(int i=1;i<=t;i++){
        k[0][i]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=t;j++){
            if(arr[i-1]<=j){
                k[i][j]=k[i-1][j] + k[i-1][j-arr[i-1]];

            }
            else 
            k[i][j]=k[i-1][j];



        }
    }

    return k[n][t];

}

int main(){
    int arr[] = {2, 3, 5, 6, 8,10};
    cout<<count(arr,6,10)<<endl;

}