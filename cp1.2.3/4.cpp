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

int compare(const void *a, const void * b ) {
    return (*(int*)a - *(int*)b);
}

//  ***** MAIN *****
int main(){
    //ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    scanf("%d", &n);
    vector<int> arr(n);

    for (auto i = 0; i < n; i++ ) {
        scanf("%d", &arr[i]);
    }

    sort(arr.begin(), arr.end(), [](int a, int b){
            return a > b;
    });

    for (auto i = 0; i < arr.size(); i++){
        cout << arr[i] << endl;
    }

    return 0;
}
