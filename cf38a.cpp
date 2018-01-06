#include <bits/stdc++.h>

using namespace std;

#define LIMIT 101

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  int d[LIMIT];
  for (int i = 0; i < n-1; i++) {
    cin >> d[i];
  }
  int a, b;
  cin >> a >> b;
  int output = 0;

  for (int i = a; i < b; i++) {
    output += d[i-1];
  }
  std::cout << output << std::endl;



  return 0;
}

