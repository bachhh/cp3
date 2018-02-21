#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
#define OFFSET 1000
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);

  cin.tie(NULL);
  int n;

  cin >> n;
  int x, y;

  int d1[4000];
  int d2[4000];

  memset(d1, 0, sizeof(int)*4000);
  memset(d2, 0, sizeof(int)*4000);

  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    int d1y = y-x;
    int d2x = x+y;
    //printf("%d %d\n", d1y, d2x);
    d1[d1y+OFFSET]++;
    d2[d2x+OFFSET]++;
  }

  int64_t output = 0;
  for (int i = 0; i < 4000; ++i) {
    if(d1[i]> 1) {
      output += d1[i]*(d1[i]-1)/2;
    }
    if(d2[i]> 1){
      output += d2[i]*(d2[i]-1)/2;
    }
  }
  std::cout << output << std::endl;

  return 0;
}

