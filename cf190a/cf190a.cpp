#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  if (n == 0 && m != 0){
    std::cout << "Impossible" << std::endl;
  }
  else {
    printf("%d %d\n", (n+ max(0, m-n)), (n + max(0, m-1)));
  }

  return 0;
}

