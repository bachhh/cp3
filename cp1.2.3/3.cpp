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

    int date, month, year;

    scanf("%d-%d-%d", &date, &month, &year);
    tm t = tm {0, 0, 0, date, month, year};
    switch ( t.tm_wday ) {
        case 0:
            cout<< "Sunday" << endl;
            break;
        case 1:
            cout<< "Monday" << endl;
            break;
        case 2:
            cout<< "Tuesday" << endl;
            break;
        case 3:
            cout<< "Wednesday" << endl;
            break;
        case 4:
            cout<< "Thursday" << endl;
            break;
        case 5:
            cout<< "Friday" << endl;
            break;
        case 6:
            cout<< "Saturday" << endl;
            break;
    }

    return 0;
}
