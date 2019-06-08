#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

typedef pair<int, int> ii;
int n, s;


//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> s;
  int f, t;

  vector<int> v(s+1, 0);
  int output = s;
  for (int i = 0; i < n; i++) {
    cin >> f >> t;
    output = max(output, f+t);
  }
  std::cout << output << std::endl;

  return 0;
}

