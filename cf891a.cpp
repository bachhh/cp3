#include <bits/stdc++.h>

using namespace std;

#define LIMIT 2000

int n;
int v[LIMIT];

int gcd(int l, int r){
  int g = v[l];
  for (int i = l; i < r; i++) {
    g = gcd(g, v[i+1]);
  }
  return g;
}
//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  return 0;
}

