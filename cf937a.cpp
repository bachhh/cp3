#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int a;
  int counter[601];
  int ma = -1;
  memset(counter, 0, sizeof(int)*601);
  for (int i = 0; i < n; ++i) {
    cin >> a;
    if ( a== 0 ) continue;
    counter[a]++;
  }
  int o = 0;
  for(int i = 600; i > 0; --i){
    if (counter[i] ) o++;
  }
  std::cout << o << std::endl;

  return 0;
}

