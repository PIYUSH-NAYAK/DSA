#include<bits/stdc++.h>
using namespace std;

void f(int n,int sum){
    if(n<1) {cout<<sum<<endl;return;}
    f(n-1,sum+n); 


}
int main(){
    int n=10;
    f(n,0);
} 