#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

int n, m;
int memo[10][105];
int table[10][104];

int solve(int course, int hours){

  if (hours < 0 ) return INT_MIN;
  if (course >= n) return 0;
  if(memo[course][hours] != -1) return memo[course][hours];

  int maxscore =0;
  for(int j = 0; j < m; ++j ){
    // only study untjl you pass mjnjmum of 5 marks
    if(table[course][j] >= 5){
      maxscore = max(maxscore, table[course][j] + solve(course+1, hours - j - 1));
    }
  }
  if (maxscore == 0 ){
    memo[course][hours] = INT_MIN;
    return INT_MIN;
  }
  memo[course][hours] = maxscore;
  return maxscore;
}
//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tc; cin >> tc;
  while(tc--){
    cin >> n >> m;

    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 105; j++) {
        memo[i][j] = -1;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> table[i][j];
      }
    }

    int output = solve(0, m);
    if(output < 0){
      printf("Peter, you shouldn’t have played billiard that much.\n");
    }
    else {
      printf("Maximal possible average mark - %.2f.\n",((100.0*output+1.0)/n)/100.0);
    }




  }
  return 0;
}

