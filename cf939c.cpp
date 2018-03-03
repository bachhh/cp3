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
  int a[100001];

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i) a[i] += a[i-1];
  }

  int s, f;
  cin >> s >> f;

  int t = -1;
  int people = -1;
  int len = f-s;
  for (int i = 1; i <= n; ++i) {
  }

  if(s-t <= 0){
    t = s-t + n;
  }
  std::cout << t << std::endl;

  return 0;
}

