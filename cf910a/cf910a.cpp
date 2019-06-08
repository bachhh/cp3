#include <bits/stdc++.h>

using namespace std;

#define LIMIT 107

int n, d;
char v[LIMIT];
int memo[LIMIT];

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> d;
  v[0] = 1;

  for (int i = 0; i <=n; i++) {
    memo[i] = INT_MAX;
  }

  char temp;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }

  int right = 1, left =1;
  memo[1] = 0;

  while(left <= n){
    if (v[left] == '1' && memo[left] < INT_MAX){
      for (int i = 1; i <= d; i++) {
        if (v[left+i] == '1'){
          memo[left+i] = min(memo[left+i],memo[left] + 1);
        }
      }
    }
    left++;
  }

  std::cout << (memo[n] == INT_MAX ? -1: memo[n]) << std::endl;


  return 0;
}

