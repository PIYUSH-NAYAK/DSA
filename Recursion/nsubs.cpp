#include<bits/stdc++.h>
using namespace std;
int f(int n,vector<int> &v ,int indx,int sum,int req ){
    if(indx==n){
        if(req==sum){
           return 1;
        }
        return 0;
        
    }
    int l=f(n,v,indx+1,sum,req+v[indx]);
    int r=f(n,v,indx+1,sum,req);
    return l+r;
  
}

int main(){
    vector<int> v = {1, 2, 3, 4, 5};

    int k=f(5,v,0,6,0);
    cout << "Number of subsets with sum 6: " << k << endl;
}