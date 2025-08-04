#include<bits/stdc++.h>
using namespace std;
void f(int i,int n){
    if(i>n)return ;
    cout<<i<<" ";i++;
    f(i,n);
}


int main(){
    int n=15;
    f(1,n);
}