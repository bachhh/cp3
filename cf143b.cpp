#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  bool neg = s[0] == '-';
  if (neg) s = s.erase(0, 1);
  int dot = s.find('.');

  string output = "";

  if (dot < s.size()){
    int counter = 0;
    for (int i = dot-1; i >= 0; --i) {
      if (s[i] == '-') continue;
      output += s[i];
      counter++;
      if (i && counter %3 == 0){
        output += ',';
      }
    }
    reverse(output.begin(), output.end());
    output += ".00";
    output[output.size()-2] = s[dot+1];

    if (dot+2 < s.size()){
      output[output.size()-1] = s[dot+2];
    }

  }
  else{
    int counter = 0;
    for (int i = s.size()-1; i >= 0; --i) {
      if (s[i] == '-') continue;
      output += s[i];
      counter++;
      if (i && counter %3 == 0){
        output += ',';
      }
    }
    reverse(output.begin(), output.end());
    output += ".00";
  }

  output = string("$")+ output;
  if (neg ){
    output = "(" + output + ")";
  }
  std::cout << output << std::endl;
  return 0;
}

