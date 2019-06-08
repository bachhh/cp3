#include <bits/stdc++.h>

using namespace std;

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define LIMIT 101

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, c, m = 0;
  cin >> n >> c;
  int xs[LIMIT];
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
  }

  for (int i = 0; i <n-1 ; i++) {
    m = MAX(m, (xs[i]-xs[i+1])-c);
  }
  std::cout << m << std::endl;



  return 0;

}

