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


  int n;
  // Double is good for holding big integer ~ 10 e 101
  double p;

  while(cin >> n >> p){
    std::cout << exp(log(p)/n) << std::endl;
  }

  return 0;
}
