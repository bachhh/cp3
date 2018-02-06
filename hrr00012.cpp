#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define LIMIT 100

int lcm(int a, int b){
  return a*b/__gcd(a, b);
}

//  ***** MAIN *****
int main(){

  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  int a, b;
  int l = 1;

  for (int i = 0; i < n; ++i) {
    cin >> a;
    l = lcm(l, a);
  }

  cin >> b;
  int g = b;
  for (int i = 1; i < m; ++i) {
    cin >> b;
    g = __gcd(g, b);
  }

  if(g%l){
    std::cout << 0 << std::endl;
  }
  else {
    int i;
    int counter = 0;
    for (i = 1; l*i <= g; ++i) {
      if (g%(l*i) == 0) counter++;
    }
    std::cout << counter << std::endl;
  }

  return 0;
}
