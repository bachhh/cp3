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

int foo(vector<int> v, int noun, int verb) {
    v[1] = noun;
    v[2] = verb;
    for (auto index = 0; index < v.size(); index += 4){
        switch (v[index]) {

            case 1:
                v[v[index + 3]] = v[v[index+1]] + v[v[index+2]];
                break;

            case 2:
                v[v[index + 3]] = v[v[index+1]] * v[v[index+2]];
                break;

            case 99:
                return v[0];

            default:
                cout << "invalid opcode " + to_string(v[index]) + "at position " + to_string(index) << endl;
                return -1;
        }
    }
    return -1;
}

//  ***** MAIN *****
int main(){
    //ios::sync_with_stdio(false);
    cin.tie(NULL);
    int code;
    char sep;
    vector<int> program;

    cin >> code;
    program.push_back(code);

    while( cin >> sep >> code && sep == ',') {
        program.push_back(code);
    }

    if( !cin.eof()) {
        cout <<  "format error input"  << endl;
        return 1;
    }

    for (auto i = 0; i < 100; i++) {
        for(auto j = 0; j < 100; j++) {
            printf("noun %d verb %d output %d\n", i, j, foo(program, i, j));
        }
    }

    return 0;
}
