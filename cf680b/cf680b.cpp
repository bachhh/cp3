#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, a; cin >> n >> a;
  int t[10000];

  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }

  int output = t[a];

  for (int d = 1; d <= max(a-0, n-a ); ++d) {

    if(a-d > 0 && a+d <= n && t[a+d] && t[a-d]){
      output+= 2;
    }
    else if( a-d <= 0 && t[a+d]){
      output++;
    }
    else if(a+d > n && t[a-d] == 1){
      output++;
    }
  }

  std::cout << output << std::endl;



  return 0;
}

