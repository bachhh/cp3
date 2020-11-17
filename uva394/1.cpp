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


struct Array {
    int dimen;
    vector<int> constants;

    string refFormatString(string name, vector<int> a) {

        string output = name+ "[";
        if (a.size() == 1) {
            return output + to_string(a[0]) + "]";
        }

        for (auto i = 0 ; i < a.size(); i++){
            if ( i < a.size() - 1 ){
                output += to_string(a[i]) + ", ";
            } else {
                output += to_string(a[i]) + "]";
            }
        }
        return output;
    };

};

//  ***** MAIN *****
int main(){
    //ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r;
    cin >> n >> r;

    map<string, Array> refTable;

    for (auto i = 0; i < n; i++) {
        string name;
        int base, size, dimen;
        cin >> name >> base >> size >> dimen;
        vector<int> lowers(dimen+1), uppers(dimen+1);

        for (auto j = 1; j <= dimen; j++) {
            cin >>  lowers[j] >> uppers[j];
        }

        struct Array a = {
            dimen: dimen,
            constants : vector<int>(dimen+1)
        };

        int accu = 0;
        for (auto j = dimen; j > 0; j--) {
            if (j == dimen) {
                a.constants[j] = size;
                accu += a.constants[j]*lowers[j];
            }
            else if ( j > 0 ) {
                a.constants[j] = a.constants[j+1]*(uppers[j+1] - lowers[j+1] +1);
                accu += a.constants[j]*lowers[j];
            }
        }
        a.constants[0] = base - accu;
        a.dimen = dimen;

        refTable[name] = a;
    }

    for (auto i = 0; i < r; i++) {
        string name;
        cin >> name;
        auto a = refTable[name];
        int addr = a.constants[0];

        vector<int> indexQuery(a.dimen);
        for (auto j = 0; j < a.dimen; j++) {
            cin >> indexQuery[j];
            addr += a.constants[j+1]*indexQuery[j];
        }
        printf("%s = %d\n", a.refFormatString(name, indexQuery).c_str(), addr);
    }


    return 0;
}
