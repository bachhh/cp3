#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string a;
  cin >> a;
  string b =a;
  reverse(a.begin(), a.end());
  std::cout << b +a<< std::endl;


  return 0;
}

