#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

int memo[LIMIT] = {-1};

int lis(int *v, int pos){
  if (pos == 0){
    memo[pos] = 1;
    return 1;
  }
  int maxlen = 0;
  for (int i = 0; i < pos; i++) {
    if (v[i] < v[pos]){
      if (memo[i] != -1){
        maxlen = max(maxlen, memo[i]);
      }
      else {
        maxlen = max(maxlen, lis(v, pos));
      }
    }
  }
  memo[pos] = maxlen+1;
  return maxlen+1;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}

