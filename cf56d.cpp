#include <bits/stdc++.h>

using namespace std;

#define LIMIT 1000
string s, t;
int dp[LIMIT][LIMIT];

int solve(int i, int j){

  // When reached end of string,
  // then every operation is an insertion
  // of the remaining length
  if (i == -1) return j+1;
  if (j == -1) return i+1;

  if (dp[i][j] != -1){
    return dp[i][j];
  }


  if(s[i] == t[j]){
    return dp[i][j] = solve(i-1, j-1);
  }
  else {
    int ins = solve(i, j-1);
    int rmv = solve(i-1, j);
    int rpl = solve(i-1, j-1);
    return dp[i][j] = 1+min(ins, min(rmv, rpl));
  }

}

int lens;
int lent;

string reconstruct(int i, int j){
  if (i < 0 && j < 0) return "";

  int ins = dp[i][j-1];
  int rmv = dp[i-1][j];
  int rpl = dp[i-1][j-1];

  string output = "";

  if (dp[i][j] == 0){
    return "";
  }

  if (i < 0 && j >= 0){
    for (int k = j; k>= 0; --k) {
      output += "INSERT " + to_string(i+2) +  t[k] + "\n" ;
    }
    return output;
  }
  else if (j <0 && i >= 0){
    for (int k = i; k>= 0; --k) {
      output += "DELETE " + to_string(k+1) + "\n" ;
    }
    return output;
  }

  if ( dp[i][j] -1 == rpl){
    return "REPLACE " + to_string(i+1) + " " + t[j] + "\n"
      + reconstruct(i-1, j-1);
  }
  else if (lens<lent && dp[i][j] - 1 == ins){
    lens++;
    return "INSERT " + to_string(i+2) + " " + t[j] + "\n"
      + reconstruct(i, j-1);
  }
  else if (lens > lent &&dp[i][j] -1 == rmv){
    lens--;
    return "DELETE " + to_string(i+1) + + "\n"
      + reconstruct(i-1, j);
  }
  else if (dp[i][j] == dp[i-1][j-1]){
    return reconstruct(i-1, j-1);
  }
  else {
    return reconstruct(i-1, j-1);
  }
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> s >> t;
  for (int i = 0; i < LIMIT; i++) {
    for (int j = 0; j < LIMIT; j++) {
      dp[i][j] = -1;
    }
  }

  lens = s.size();
  lent = t.size();
  std::cout << solve(s.size()-1, t.size()-1) << std::endl;
  std::cout << reconstruct(s.size()-1, t.size()-1);
  std::cout << endl;

  return 0;
}

