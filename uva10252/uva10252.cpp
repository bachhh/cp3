#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  string a, b;
  while(true){
    getline(cin, a);
    getline(cin, b);
    if(cin.eof()) break;

    map<char, int> _b;
    map<char, int> _a;
    for (char c : a) { _a[c]++; }
    for (char c : b) { _b[c]++; }
    string output = "";
    for (char c = 'a'; c <= 'z'; ++c) {
      output.insert(output.end(), min(_a[c], _b[c]), c);
    }
    std::cout << output << std::endl;
  }

  return 0;
}

