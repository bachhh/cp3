#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string temp;
  getline(cin, temp);
  getline(cin, temp);
  string output = "";
  while(temp != "___________"){
    int mult = (1<<7);
    char c = 0;
    for (int i = 1; i <10 ; i++) {
      if (temp[i] == '.') continue;
      if (temp[i] == 'o'){
        c += mult;
        mult = (mult>>1);
      }
      if(temp[i] == ' '){
        mult = (mult>>1);
      }
    }
    output += c;
    getline(cin, temp);
  }
  std::cout << output;

  return 0;
}

