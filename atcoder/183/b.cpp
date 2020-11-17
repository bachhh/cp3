#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
#define PLIMIT 10000010
#define MOD 1000000007ll
#define INF 1e9
typedef long long ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
template<typename T, typename U> static inline void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static inline void amax(T &x, U y) { if (x < y) x = y; }


//  ***** MAIN *****
int main(){
    //ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 0;
    cin >> n;

    int max = 0;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
        amax(max, arr[i]);
    }


    int maxGCD, m = 0;
    for (int i = 2; i <= max; ++i) {
        int count = 0;
        for (auto j : arr) {
            if (gcd(i, j)) {
                count++;
            }
        }
        if (count > maxGCD){
            m = i;
            maxGCD = count;
        }
    }

    cout << m << endl;

    return 0;
}
