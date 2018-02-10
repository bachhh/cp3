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

  if (n <= 2){
    std::cout << -1 << std::endl;
    return 0;
  }

  int v[10000];

  bool asc = true;
  bool desc = true;
  bool unsort = true;

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    if(i > 0 ){
      if(v[i] > v[i-1] ){
        asc = false;
      }
      if (v[i] < v[i-1]){
        desc = false;
      }
    }
  }
  if (asc || desc) unsort = false;
  std::cout << asc << std::endl;
  std::cout << desc << std::endl;
  std::cout << unsort << std::endl;
  std::cout << std::endl;

  if (asc){
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; j++) {
        if(v[i] > v[j]){
          printf("%d %d\n", i+1, j+1);
          return 0;
        }
      }
    }
    std::cout << -1 << std::endl;
  }
  else if(desc){
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; j++) {
        if(v[i] < v[j]){
          printf("%d %d\n", i+1, j+1);
          return 0;
        }
      }
    }
    std::cout << -1 << std::endl;
  }
  else if(unsort){
    int larger = 0;
    int smaller = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; j++) {
        if(v[i] < v[j]){
          if (smaller >= 1){
            printf("%d %d\n", i+1, j+1);
            return 0;
          }
          smaller++;
        }
        if (v[i] > v[j]){
          if (larger >= 1){
            printf("%d %d\n", i+1, j+1);
            return 0;
          }
          larger++;
        }
      }
    }
    std::cout << -1 << std::endl;
  }
  else {
    cerr << "erroR!" << endl;
  }

  return 0;
}

