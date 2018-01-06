#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;

  cin >> n;
  int x1, y1, x2, y2;
  int counter = 0;
  for (int i = 0; i < n; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    counter += (y2-y1+1)*(x2-x1+1);
  }
  std::cout << counter << std::endl;


  return 0;
}

