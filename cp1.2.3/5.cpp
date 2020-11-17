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
    char a[10];
    vector<string> v;

    while (scanf("%s", a) != EOF) {
        v.push_back(string(a));
    }

    for (auto s : v) {
        cout << s << endl;
    }
    cout << "---" << endl;
    sort(v.begin(), v.end(), [](string a, string b) {
            auto m = a.substr(3, 2).compare(b.substr(3, 2));
            if (m != 0) {
               return m < 0;
            }

            auto d = a.substr(0, 2).compare(b.substr(0, 2));
            if (d != 0) {
               return d < 0;
            }

            auto year = a.substr(6, 4).compare(b.substr(6, 4));
            if (d != 0) {
               return year < 0;
            }
    });

    for (auto str : v) {
        cout << str << endl;
    }

    return 0;
}
