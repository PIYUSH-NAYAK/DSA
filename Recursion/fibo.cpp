#include<bits/stdc++.h>
using namespace std;
int fibo(int n){
    if(n<2) return n;
    return fibo(n-1)+fibo(n-2);
}
int main(){
    cout<<"Enter a index: ";
    int n;
    cin>>n;
    int x=fibo(n);
    cout<<"Fibonacci number at index "<<n<<" is: "<<x<<endl;
}