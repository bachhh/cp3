#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;


bool isGreater(string a, string b){
  if (a.size() > b.size()) return true;
  if (a.size() < b.size()) return false;

  for (int i = 0; i < a.size(); ++i) {
    if (a[i] > b[i]) return true;
    if (a[i] < b[i]) return false;
  }
  return false;
}


//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;

  cin >> s;
  int mx = -1;

  for (int i = 1; i < s.size()-1; ++i) {
    for (int j = i+1; j < s.size(); ++j) {
      string s1 = s.substr(0,i);
      string s2 =  s.substr(i, j-i);
      string s3 = s.substr(j, s.size()-j);
      if (s1[0] == '0' && s1.size() > 1) continue;
      if (s2[0] == '0' && s2.size() > 1) continue;
      if (s3[0] == '0' && s3.size() > 1) continue;

      if (isGreater(s1, "1000000")) continue;
      if (isGreater(s2, "1000000")) continue;
      if (isGreater(s3, "1000000")) continue;

      int64_t i1 = stoi(s1);
      int64_t i2 = stoi(s2);
      int64_t i3 = stoi(s3);

      mx = max<int64_t>(i1 + i2 + i3, mx);
    }
  }
  std::cout << mx << std::endl;
  return 0;
}

