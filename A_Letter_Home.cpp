/*
           ||----------------------------------------------------------||
           ||----------------------------------------------------------||
           ||                                                          ||
           ||                      Piyush Nayak                        ||
           ||                 Competitive Programmer                   ||
           ||           Problem Solving | Algorithms | C++             ||
           ||                                                          ||
           ||----------------------------------------------------------||
           ||----------------------------------------------------------||
*/

//---------------------- Useful Headers ----------------------//
#include <bits/stdc++.h>
using namespace std;

//-------------------- Macros & Typedefs ---------------------//
#define int long long int
#define vi  vector<int> 
#define pii  pair<int, int> 
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sorta(arr,n) sort(arr, arr + n)
#define sortd(arr,n) sort(arr, arr + n, greater<int>())
#define sortva(ans) sort(ans.begin(), ans.end());
#define sortvd(ans) sort(ans.begin(), ans.end(), greater<int>());
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

// YES/NO Macros
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl

//----------------------- Constants --------------------------//
const int MOD = 1e9 + 7;

//--------------------- Utility Functions --------------------//
template <typename T>
void inline read(T &x) {
    int f = 1;
    x = 0;
    char s = getchar();
    while (s < '0' || s > '9') {
        if (s == '-') f = -1;
        s = getchar();
    }
    while (s >= '0' && s <= '9') x = x * 10 + (s - '0'), s = getchar();
    x *= f;
}

int findPower(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

bool desc(const pii& a, const pii& b) {
    return max(a.F, a.S) < max(b.F, b.S);
}

void printVec(const vi &ans) {
    for (int i : ans) cout << i << " ";
    cout << endl;
}

// Lambda Function for Prime Check
auto isPrime = [](int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
};

int powerOf2(int n) { 
    if (n <= 0) return -1;  // Return -1 for non-positive numbers
    int power = log2(n);    // log2(n) gives the exponent of the nearest power of 2
    return power;
}

int highestDivisor(int n) {
    if (n <= 1) return 0;  // No divisor for 1 or below
    int maxDivisor = 1;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {  // If i is a divisor
            maxDivisor = std::max(maxDivisor, i);  // Update max divisor found
            if (i != n / i && n / i < n) {  // Check the pair divisor
                maxDivisor = std::max(maxDivisor, n / i);
            }
        }
    }
    return maxDivisor;
}

//-------------------- Solve Function ------------------------//
void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n,s;
        cin>>n>>s;
        vi arr(n);
        int mx=INT_MIN,mn=INT_MAX;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            mx=max(mx,arr[i]);
            mn=min(mn,arr[i]);
        }
        int add=mx-mn;
        int f1=s-mn;
        int f2=mx-s;
        if(f1<0) f1=-f1;
        if(f2<0) f2=-f2;
        int res=min(f1,f2);
       cout<<res+add<<endl;




        // Your code here
    }
}

//----------------------- Main Function ----------------------//
signed main() {
    fastio;
    solve();
    return 0;
}

//------------------ End of Template -------------------------//