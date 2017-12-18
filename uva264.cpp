#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

typedef long int int32; typedef long long int int64;
typedef unsigned long int uint32; typedef unsigned long long int uint64;
typedef pair<int, int> ii; typedef vector<ii> vii; typedef vector<int> vi;
typedef tuple<int, int, int> iii; typedef tuple<int, int, int, int> iiii;
typedef vector<vi> vvi;

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )
#define LIMIT 11
#define INF INT_MAX


//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);

  int n,d, di;

  while(cin >> n){

    // This method of counting rational makes them into a sumation series
    // Our input will lies between sum(1, x-1) and sum(1, x)
    // Sum(a, b) being the sum from a to b
    // and n, is the base column/row of the diagional line numbering

    int term = ceil((sqrt(1.0+8*n)-1.0)/2);

    int large = term*(term+1)/2;
    if (term%2){
      d = large+1 - n;
      di = term+1 - d;
    }
    else {
      di = large+1 -n;
      d = term+1 - di;
    }

    printf("TERM %d IS %d/%d\n", n, d, di);
  }

  return 0;
}
