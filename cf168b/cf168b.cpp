#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  string w = "";
  bool wempty = true;
  while(true ){
    getline(cin, s);
    if(cin.eof()){
      if(!wempty) std::cout << w << std::endl;
      break;
    }

    if (s==""){
      wempty = false;
      continue;
    }

    bool amplify = false;
    for (char c : s) {
      if(c != ' ' && c != '#'){
        break;
      }
      else if (c == '#'){
        amplify = true;
        break;
      }
    }

    // strip all spaces, move into v
    if (!amplify){
      for(char c : s){
        if (c != ' ')
        w += c;
      }
      wempty = false;
    }

    // flush out all string in v, concatenaed
    if (amplify){
      if (!wempty) std::cout << w << std::endl;
      w = "";
      wempty = true;
      cout << s << endl;
    }

  }

  return 0;
}

