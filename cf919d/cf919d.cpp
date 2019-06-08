#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
int n, m;
vector<vector<int>> al;
int state[300000];

int dfs(int i,int  largest){
  if(state[i] == VISITED){
    return max(largest, freq[i]);
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> n >> m;
  cin >> s;

  al.resize(n);
  int counter[26] = {0};
  for (int i = 0; i < s.size(); i++) {
    counter[s[i]-'a']++;
  }
  memset(state, -1, n);

  int x, y;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    x--; y--;
    al[x].push_back(y);
  }


  return 0;
}

