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

#define LIMIT 100

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int m = MAX(3*a/10, a-a/250*c);
  int v = MAX(3*b/10, b-b/250*d);
  if (m>v) std::cout << "Misha" << std::endl;
  else if (m<v) std::cout << "Vasya" << std::endl;
  else std::cout << "Tie" << std::endl;

  return 0;
}
