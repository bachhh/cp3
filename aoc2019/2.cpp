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

int recurseFuel(int mass) {
    if (( mass/3-2 ) <= 0) {
        return 0;
    }

    return (mass/3 -2) + recurseFuel(mass/3-2);
}

//  ***** MAIN *****
int main(){
    //ios::sync_with_stdio(false);
    cin.tie(NULL);

    int mass = 0, totalFuel = 0;
    while (cin >> mass) {
        totalFuel += recurseFuel(mass);
    }
    cout << totalFuel << endl;

    return 0;
}
