#include<bits/stdc++.h>
using namespace std;
void calcSum(vector<int> m ,int sum){
    int tot=0;
    for(int i=0;i<m.size();i++){
        tot+=m[i];
    }
    if(tot==sum){
        cout<<'{';
        for(int i=0;i<m.size();i++){
            cout<<m[i]<<" ";
        }
        cout<<'}'<<endl;
    }

}
void f(int n,vector<int> &v,vector<int> &k,int indx,int sum){
    if(indx==n){
        calcSum(k,sum);
        return;
    }
    k.push_back(v[indx]);
    f(n,v,k,indx+1,sum);
    k.pop_back();
    f(n,v,k,indx+1,sum);

}


int main(){
    vector<int>v = {1, 2, 3, 4, 5};
    vector<int>k;
    int sum=6;

    f(v.size(),v,k,0,sum);


}