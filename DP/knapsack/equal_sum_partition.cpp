#include<bits/stdc++.h>
using namespace std;
bool  find(int arr[], int n, int target) {
    bool ne[n+1][target+1];
    for(int i=0;i<=n;i++) {
        ne[i][0] = true; 
    }
    for(int i=1;i<=target;i++) {
        ne[0][i] = false; 
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(arr[i-1]<=j){
                ne[i][j]=ne[i-1][j-arr[i-1]] || ne[i-1][j];


            }
            else{
                ne[i][j]=ne[i-1][j];
            }
        }
    }
    return ne[n][target];
   
}
int sum(int arr[],int n){
    
    int sum=0;
    while(n--){
        sum+=arr[n];

    }
    return sum;
}
int main(){
    int arr[] = {1, 2, 3, 4, 6};
    int arr2[]={6,4,1,12,19};
   int n1=sum(arr,5);
   int n2=sum(arr2,5);
   
    
    cout << boolalpha;
    cout<< find(arr, 5, n1/2) << "\n"; 
    cout<<find(arr2,5,n2/2)<<"\n"; 
}