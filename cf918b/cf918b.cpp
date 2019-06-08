#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  getchar();

  string temp;
  map<string, string> mss;
  string ip, name;
  for (int i = 0; i < n; i++) {
    getline(cin, temp);
    int index = temp.find(' ');
    name = temp.substr(0, index);
    ip = temp.substr(index+1);
    mss[ip] = name;
  }

  for (int i = 0; i < m; i++) {
    getline(cin, temp);
    int index = temp.find(' ');
    ip = temp.substr(index+1, temp.find(';')-index-1);
    std::cout << temp << " #"<< mss[ip] << std::endl;
  }



  return 0;
}

