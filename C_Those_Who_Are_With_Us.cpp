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

//------------------ Utility Functions (existing) ------------------//
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
    if (n <= 0) return -1;
    int power = log2(n);
    return power;
}

int highestDivisor(int n) {
    if (n <= 1) return 0;
    int maxDivisor = 1;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            maxDivisor = std::max(maxDivisor, i);
            if (i != n / i && n / i < n) {
                maxDivisor = std::max(maxDivisor, n / i);
            }
        }
    }
    return maxDivisor;
}

//------------------ New Modular Functions ------------------//

vector<vector<int>> readMatrix(int n, int m) {
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, 0, n) rep(j, 0, m) cin >> a[i][j];
    return a;
}

pii findTopTwo(const vector<vector<int>>& a) {
    int G = 0, H = 0;
    for (const auto& row : a) {
        for (int val : row) {
            if (val > G) {
                H = G;
                G = val;
            } else if (val > H && val < G) {
                H = val;
            }
        }
    }
    return {G, H};
}

tuple<vector<int>, vector<int>, int> countMaxOccurrences(const vector<vector<int>>& a, int G) {
    int n = a.size(), m = a[0].size(), totG = 0;
    vector<int> row_cnt(n, 0), col_cnt(m, 0);

    rep(i, 0, n) {
        rep(j, 0, m) {
            if (a[i][j] == G) {
                row_cnt[i]++;
                col_cnt[j]++;
                totG++;
            }
        }
    }
    return {row_cnt, col_cnt, totG};
}

bool canCoverAllMax(const vector<vector<int>>& a, const vector<int>& row_cnt, const vector<int>& col_cnt, int G, int totG) {
    int n = a.size(), m = a[0].size();

    rep(r, 0, n) {
        if (row_cnt[r] == 0) continue;
        if (row_cnt[r] == totG) return true;

        int c_count = 0;
        rep(c, 0, m) {
            int rem_in_c = col_cnt[c] - (a[r][c] == G ? 1 : 0);
            if (rem_in_c > 0) {
                c_count++;
                if (c_count > 1) break;
            }
        }
        if (c_count <= 1) return true;
    }
    return false;
}

void processTestcase() {
    int n, m;
    cin >> n >> m;
    auto a = readMatrix(n, m);
    auto [G, H] = findTopTwo(a);
    auto [row_cnt, col_cnt, totG] = countMaxOccurrences(a, G);
    bool cover = canCoverAllMax(a, row_cnt, col_cnt, G, totG);
    int answer = cover ? max(G - 1, H) : G;
    cout << answer << "\n";
}

//-------------------- Solve Function ------------------------//
void solve() {
    int T;
    cin >> T;
    while (T--) {
        processTestcase();
    }
}

//----------------------- Main Function ----------------------//
signed main() {
    fastio;
    solve();
    return 0;
}
