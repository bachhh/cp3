#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

typedef long int int32; typedef long long int int64;
typedef unsigned long int uint32; typedef unsigned long long int uint64;
typedef pair<int, int> ii; typedef vector<ii> vii; typedef vector<int> vi;
typedef vector<vi> vvi;

#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define VISITED 1
#define UNVISITED -1

#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define LOOP(i, n) for (int i = 0; i < n; ++i)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )
#define DEBUG(x) cerr << #x << " is " << x << endl;

//  ***** MAIN *****
int main(){

  //ios::sync_with_stdio(false);
  //cin.tie(NULL);

  uint64 tc, n, a, b, temp;

  cin >> n >> a >> b;

  for (int i = 0; i < n; i++) {
    cin >> temp;
    uint64 money = (temp*a)/b;
    uint64 token = money*b/a;
    if (money*b%a) token++;
    std::cout << temp - token << " \n"[i==n-1];
  }

  return 0;
}

