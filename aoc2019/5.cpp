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

typedef struct segment {
    long x1, y1;
    long x2, y2;
} Segment;

//  ***** MAIN *****
int main(){
    //ios::sync_with_stdio(false);
    cin.tie(NULL);

    auto compare = [](ii a, ii b){
        return (get<0>(a) + get<1>(a) ) < (get<0>(b) + get<1>(b));
    };

    priority_queue<ii, vector<ii>, decltype(compare)> q(compare);
    string wire1, wire2;

    cin >> wire1;
    stringstream ss(wire1);

    string command;
    int map[1000][1000];
    for (int i; ss >> command;) {
        if (ss.peek() == ',') ss.ignore();
        q.push(make_pair(0, 0));
    }


    return 0;
}
