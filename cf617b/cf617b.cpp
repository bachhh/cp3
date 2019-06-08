#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;

  int v[101];

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  int64_t counter = 1;
  int i = 0;
  int prev;
  while(i < n && v[i] == 0)i++;

  if(i>= n){
    std::cout << 0 << std::endl;
    return 0;
  }

  prev = i;
  i++;

  while(i < n){
    while(i < n && v[i] != 1)i++;
    if(i < n && v[i] == 1){
      counter *= i - prev;
      prev = i;
    }
    i++;
  }
  std::cout << counter << std::endl;



  return 0;
}

