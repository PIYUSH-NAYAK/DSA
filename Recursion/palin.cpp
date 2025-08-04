#include<bits/stdc++.h>
using namespace std;
bool func(string s,int l,int r){
    if(l>=r) return true;
    if(s[l]!=s[r])return false;
    return func(s,l+1,r-1);

}
int main(){
    cout<<"Enter a string: ";
    string s;
    cin >> s;
    bool check= func(s,0,s.size()-1);
    if(check) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }



}