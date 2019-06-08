#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;
  string w = s;

  sort(w.begin(), w.end());

  if (k > n){
    s += string(k-n, w.front());
  }
  else if (k < n){
    int i = k-1;
    while(s[i] == w.back()){i--;}
    s[i] = *upper_bound(w.begin(), w.end(), s[i]);
    s = s.substr(0, i+1);
    if(i+1<k){
      s += string(k-i-1, w.front());
    }
  }
  else {
    int i = n-1;
    while(s[i] == w.back()){i--;}
    s[i] = *upper_bound(w.begin(), w.end(), s[i]);
    s = s.substr(0, i+1);
    s += string(k-i-1, w.front());
  }

  std::cout << s << std::endl;
  return 0;
}

