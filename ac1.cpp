#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, c;
  string s;

  cin >> a >> b >> c;
  getchar();
  getline(cin, s);

  std::cout << a+b+c << " " << s << endl;

  return 0;
}

