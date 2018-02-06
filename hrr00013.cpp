#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int s;
  int most = 0, least = 0;
  cin >> s;
  int mi = s, ma = s;
  for (int i = 1; i < n; ++i) {
    cin >> s;
    if (s < mi){
      mi = s;
      least++;
    }
    if (s>ma){
      ma = s;
      most++;
    }

  }

  printf("%d %d\n", most, least);

  return 0;
}

