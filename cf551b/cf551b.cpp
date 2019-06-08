#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

int make(map<char, int> &from, map<char, int> to){
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  string a, b, c;
  cin >> a >> b >> c;
  map<char, int> m1, m2;
  map<char, int> _b, _c;
  for (char c : a) {
    m1[c]++;
    m2[c]++;
  }

  for (char c : b) {
    _b[c]++;

  }
  for (char ch : c) {
    _c[ch]++;
  }

  int intb, intc;

  string output="";

  return 0;
}

