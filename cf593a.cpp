#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

int check(string s){
  set<char> st;
  for (char c : s) {
    st.insert(c);
  }
  return st.size();
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  string w;
  vector<string> v;
  int single[200] = {0};
  int duo[200][200] = {0};

  for (int i = 0; i < n; i++) {
    cin >> w;
    if(check(w) == 1){
      single[w.front()] += w.size();
    }
    else if(check(w) == 2){
      sort(w.begin(), w.end() );
      duo[w.front()][w.back()] += w.size();
      duo[w.back()][w.front()] += w.size();
    }
  }
  int m = 0;
  for (char i = 'a'; i <= 'z'; i++) {
    for (char j = 'a'; j <= 'z'; j++) {
      if (i!= j){
        int d = single[i] + single[j] + duo[i][j];
        m = max(m, d);
      }
    }
  }
  std::cout << m << std::endl;

  return 0;
}

