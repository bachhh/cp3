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

void printArray(vector<int> v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
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

    program[1] = 12;
    program[2] = 2;
    for (auto index = 0; index < program.size(); index += 4){
        switch (program[index]) {

            case 1:
                cout << "addition" << endl;
                program[program[index + 3]] = program[program[index+1]] + program[program[index+2]];
                break;

            case 2:
                cout << "multiply" << endl;
                program[program[index + 3]] = program[program[index+1]] * program[program[index+2]];
                break;

            case 99:
                cout << "halt" << endl;
                goto halt;

            default:
                cout << "invalid opcode " + to_string(program[index]) + "at position " + to_string(index) << endl;
                printArray(program);
                return -1;
        }
    }
halt:
        printArray(program);

    return 0;
}
