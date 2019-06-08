#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){

  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  int a;
  cin >> n >> a;
  n %= 500;
  if (n > a){
    std::cout << "No" << std::endl;
  }
  else{
    std::cout << "Yes" << std::endl;
  }

  return 0;
}

