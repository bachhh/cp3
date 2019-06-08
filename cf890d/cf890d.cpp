#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

char parent[200];
char child[200];

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  string s;
  memset(parent, 0, 123);
  for (int z = 0; z < n; ++z) {
    cin >> s;
    for (int j = 0; j+1 < s.size(); ++j) {
      char p = s[j];
      char c = s[j+1];
      // If the next character already belonged to some other most frequent string
      if (parent[c] != 0 && parent[c] != p){
        std::cout << "NO" << std::endl;
        return 0;
      }
      // If the previous character already belonged to
      // the start of some other most frequent string
      if (child[p] != 0 && child[p] != c){
        std::cout << "NO" << std::endl;
        return 0;
      }
      parent[c] = p;
      child[p] = c;
    }
  }

  vector<string> v;

  for(char c = 'a'; c <= 'z'; ++c){
    string temp = "";
    char head = c;
    while(parent[head] != 0){
      head = parent[head];
    }
    while(child[head] != 0){
      temp += head;
      head = child[head];
      child[parent[head]] = 0;
      parent[head] = 0;
    }
    v.push_back(temp);
  }
  sort(v.begin(), v.end());
  for (string s : v) {
    cout << s;
  }
  cout << endl;


  return 0;
}

