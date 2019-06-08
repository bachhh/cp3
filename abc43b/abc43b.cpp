#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;

  string output = "";
  string s;
  cin >> s;
  for ( char c : s){
    if (!output.empty() && c == 'B'){
      output.pop_back();
    }
    else if( c != 'B'){
      output += c;
    }
  }
  std::cout << output << std::endl;

  return 0;
}

