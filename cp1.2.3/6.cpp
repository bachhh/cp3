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

//  ***** MAIN *****
int main(){
    //ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v;
    sort(v.begin(), v.end());
    int target;

    int low = 0, high= v.size() -1, mid;
    while (low < high) {
        // defines v[-1] = false, v[n] = true
        // invariants v[low - 1] = false, v[low] = true
        mid = low+(high-low)/2;
        if ( v[mid] == target ) {
            low = mid; // keep our invariant v[low] = true;
        } else {
            low = mid + 1; // keep our invariant v[low-1] = false;
        }
    }

    // low == high, loop end
    // v[low -1] = false, v[low] == v[high] = true
    if ( v[low] != target ) {
        cout << "not found" << endl;
    } else  {
        cout << "found" << endl;
    }


    return 0;
}
