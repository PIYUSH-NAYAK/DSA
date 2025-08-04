/*
           ||----------------------------------------------------------||
           ||                      Piyush Nayak                        ||
           ||                 Competitive Programmer                   ||
           ||           Problem Solving | Algorithms | C++             ||
           ||----------------------------------------------------------||
*/

//---------------------- Useful Headers ----------------------//
#include <bits/stdc++.h>
using namespace std;

//-------------------- Macros & Typedefs ---------------------//
#define int long long int
#define vi vector<int>
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sorta(arr,n) sort(arr, arr + n)
#define sortd(arr,n) sort(arr, arr + n, greater<int>())
#define sortva(ans) sort(ans.begin(), ans.end())
#define sortvd(ans) sort(ans.begin(), ans.end(), greater<int>())
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
static auto isPrime = [](int n) {
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
    if (n <= 1) return 0;
    int maxDiv = 1;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            maxDiv = max(maxDiv, i);
            if (i != n / i && n / i < n) {
                maxDiv = max(maxDiv, n / i);
            }
        }
    }
    return maxDiv;
}

//-------------------- Problem Functions --------------------//

// Count all subarrays in `seg` with sum equal to target
int countAll(const vi &seg, int target) {
    unordered_map<int, int> freq;
    freq.reserve(seg.size()*2);
    freq[0] = 1;
    int sum = 0, cnt = 0;
    for (int v : seg) {
        sum += v;
        if (freq.count(sum - target)) cnt += freq[sum - target];
        freq[sum]++;
    }
    return cnt;
}

// Count subarrays with sum == target within seg[L..R]
int countRange(const vi &seg, int L, int R, int target) {
    if (L > R) return 0;
    unordered_map<int,int> freq;
    freq.reserve((R-L+2)*2);
    freq[0] = 1;
    int sum = 0, cnt = 0;
    for (int i = L; i <= R; ++i) {
        sum += seg[i];
        if (freq.count(sum - target)) cnt += freq[sum - target];
        freq[sum]++;
    }
    return cnt;
}

// Process a segment [l..r] where all elements <= x
int solveSegment(int l, int r, const vi &a, int s, int x) {
    int len = r - l + 1;
    vi seg;
    seg.reserve(len);
    for (int i = l; i <= r; ++i) seg.pb(a[i]);

    int total_all = countAll(seg, s);
    vi xpos;
    rep(i,0,len) if (seg[i] == x) xpos.pb(i);

    int total_no_x = 0;
    if (xpos.empty()) {
        total_no_x = total_all;
    } else {
        total_no_x += countRange(seg, 0, xpos.front()-1, s);
        rep(k,0,(int)xpos.size()-1) {
            total_no_x += countRange(seg, xpos[k]+1, xpos[k+1]-1, s);
        }
        total_no_x += countRange(seg, xpos.back()+1, len-1, s);
    }
    return total_all - total_no_x;
}

//-------------------- Solve Function ------------------------//
void solve() {
    fastio;
    int T;
    cin >> T;
    while (T--) {
        int n, s, x;
        cin >> n >> s >> x;
        vi a(n);
        rep(i,0,n) cin >> a[i];

        int answer = 0;
        int i = 0;
        while (i < n) {
            if (a[i] > x) {
                i++;
                continue;
            }
            int start = i;
            while (i < n && a[i] <= x) i++;
            int end = i - 1;
            answer += solveSegment(start, end, a, s, x);
        }

        cout << answer << '\n';
    }
}

//----------------------- Main Function ----------------------//
signed main() {
    solve();
    return 0;
}
