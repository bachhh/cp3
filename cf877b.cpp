#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s; cin >> s;
  vector<int> prefa(s.size()+1);
  vector<int> prefb(s.size()+1);

  int si = s.size();
  prefa[0] = prefb[0] = 0;

  for (int i = 0; i < si; i++) {
    if(s[i] == 'a'){
      prefa[i+1] = prefa[i]+1;
      prefb[i+1] = prefb[i];
    }
    else if (s[i] == 'b'){
      prefb[i+1] = prefb[i]+1;
      prefa[i+1] = prefa[i];
    }
  }

  int mx = -1;
  for (int i = 0; i <= si; i++) {
    for (int j = i; j <= si; j++) {
      mx = max(mx, prefa[i] + prefa[si]-prefa[j] + prefb[j]-prefb[i]);
    }
  }

  std::cout << mx << std::endl;

  return 0;
}

