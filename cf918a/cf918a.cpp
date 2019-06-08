#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;

  vector<char> v(n, 'o');

  v[0] = 'O';
  v[1] = 'O';

  int a = 1, b = 1;
  while( b <= n){
    b = a+b;
    a = b-a;
    v[b-1] = 'O';
  }

  for (int i = 0; i < n; i++) { std::cout << v[i]; }
  std::cout << std::endl;


  return 0;
}

