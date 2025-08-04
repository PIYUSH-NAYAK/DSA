#include<bits/stdc++.h>
using namespace std;

void f(int i,int n){
    if(n<i)return;
    f(i+1,n);
    cout<<i<<" ";
}

int main(){
    int n=10;
    f(1,n);
}