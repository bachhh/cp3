#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int cards[1000];
  for (int i = 0; i < n; ++i) {
    cin >> cards[i];
  }
  int a = 0;
  int b = 0;
  sort(cards, cards+n);

  for (int i = 0; i < n; i+= 2) {
    a += cards[i];
    b += cards[i+1];
  }
  std::cout << abs( a-b ) << std::endl;

  return 0;
}

