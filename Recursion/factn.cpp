#include<bits/stdc++.h>
using namespace std;
int f(int n){
    if(n<2)return 1;
    return n*f(n-1);
}
int main(){
    int n=6;
    int fact=f(n);
    cout<<fact<<endl;
    
}