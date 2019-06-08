#include <bits/stdc++.h>

using namespace std;
#define LIMIT 100
vector<int> v;
int dp[LIMIT][LIMIT];
int sol[LIMIT][LIMIT];
string output;

int solve(int l, int r){
  if(r<= l) return 0;
  if (dp[l][r] != -1 ) return dp[l][r];
  int mi = INT_MAX;
  int solution;
  for (int k = l; k < r; k++) {
    int temp = solve(l, k) + solve(k+1, r) + v[l]*v[k+1]*v[r+1];
    if (temp < mi){
      mi = temp;
      solution = k;

    }
  }
  sol[l][r] = solution;
  return dp[l][r] = mi;
}

string construct(int l, int r){
  if(l == r){
    return "A" + to_string(l+1);
  }
  else if (r == l+1){
    return string("(A") + to_string(l+1) +" x "  + "A" + to_string(r+1) + ")";
  }
  else {
    assert(sol[l][r] != -1);
    int sep = sol[l][r];
    return "("+construct(l, sep) + " x " + construct(sep+1, r) + ")";
  }
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  int temp;
  int c = 1;

  while(cin >> n && n != 0){

    v.clear(); output = "";

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dp[i][j] = -1;
        sol[i][j] = -1;
      }
    }

    cin >> temp;
    v.push_back(temp);
    for (int i = 1; i < n*2; i++) {
      cin >> temp;
      if (i%2) v.push_back(temp);
    }
    solve(0, n-1);
    std::cout << "Case " << c << ": ";
    std::cout << construct(0, n-1) << std::endl;
    c++;

  }

  return 0;
}

