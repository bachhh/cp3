#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

string trimLead(string s, char c){
  int i = 0;
  while(s[i] == c){++i;}
  return s.substr(i, s.size()-i);
}

string trimTrail(string s, char c){
  int i = s.size()-1;
  while(s[i] == c){--i;}
  return s.substr(0, i);
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string a = "000000123";
  string b = "123000000";
  std::cout << trimLead(a, '0') << std::endl;
  std::cout << trimTrail(b, '0') << std::endl;

  return 0;
}

