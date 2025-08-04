#include<bits/stdc++.h>
using namespace std;

void f(int arr[], int l, int r) {
    if(l>=r){
        cout << "Reversed array: ";
        for(int i = 0; i < 5; i++) {
            cout << arr[i] << " ";
        }
        return;
    }
    swap(arr[l],arr[r]);
    f(arr, l + 1, r - 1);

}
int main(){
    int arr[5]={1,2,3,4,5};
    f(arr,0,4);
}