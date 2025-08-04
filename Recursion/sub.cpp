#include<bits/stdc++.h>
using namespace std;
void printvec(vector<int> &p){
    cout<<'{' <<" ";
    for(int i=0;i<p.size();i++){
        cout<<p[i]<<" ";
    }

    cout<<'}'<<endl;
}
void f(int n,vector<int> &p,int i,vector<int> &k){
    if(i>=n) {
        printvec(k);
        return;
    }
    k.push_back(p[i]);
    f(n,p,i+1,k);
    k.pop_back();
    f(n,p,i+1,k);


    


}
int main(){
    vector<int> v= {1, 2, 3, 4, 5};
    vector<int> k;
    f(v.size(),v,0,k);
    // f(v,5);
}