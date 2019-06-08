#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

bool isSuffix(string a, string b){
  if(b.size() > a.size()) return false;

  int i = a.size();
  int j = b.size();
  while(j-- && i--){
    if (a[i] != b[j]) return false;
  }
  return true;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  string name, phone;
  int k;

  map<string, vector<string>> book;
  for (int i = 0; i < n; i++) {
    cin >> name >> k;
    if (book.find(name) == book.end()) book[name] = vector<string>(0);
    for (int j = 0; j < k; j++) {
      cin >> phone;
      int flag = false;
      for (auto it = book[name].begin();
          it != book[name].end(); ++it ) {
        if (isSuffix(*it, phone)){
          flag = true;
          break;
        }
        else if (isSuffix(phone, *it)){
          flag = true;
          book[name].erase(it);
          book[name].push_back(phone);
          break;
        }
      }
      if (!flag){
        book[name].push_back(phone);
      }
    }
  }
  std::cout << book.size() << std::endl;
  for (auto p : book) {
    std::cout << p.first << " " << p.second.size();
    for (auto w : p.second) {
      std::cout << " " << w;
    }
    std::cout << std::endl;
  }

  return 0;
}

