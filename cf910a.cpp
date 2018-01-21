#include <bits/stdc++.h>

using namespace std;

#define LIMIT 107

int n, d;
char v[LIMIT];
int memo[LIMIT];
int minJump(int x){
  if (x <= 1) return 0;
  if (memo[x] != -1) return memo[x];
  int mi = INT_MAX;
  for (int i = 1; (x-i)>=1 && i <= d; i++) {
    if(v[x-i] == '1') mi = min(mi, minJump(x-i));
  }
  if (mi == -1 || mi == INT_MAX) return memo[x] = -1;
  else return memo[x] = mi+1;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> d;
  v[0] = 1;

  for (int i = 0; i <=n; i++) {
    memo[i] = -1;
  }

  char temp;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }

  cout << minJump(n) << endl;

  return 0;
}

