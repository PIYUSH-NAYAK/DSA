#include<bits/stdc++.h>
using namespace std;
void f(int n){
    if(n<1) return;
    cout<<n<<" ";
    n--;
    f(n); 
}

int main(){
    int n=10;
    f(n);
}

