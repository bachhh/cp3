#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

string add(string a, string b){

  string output = "";
  int co = 0;

  while (true) {

    char c = 0;

    if (!a.empty()){
      c += a.back() - '0';
      a.pop_back();
    }

    if (!b.empty()){
      c += b.back() - '0';
      b.pop_back();
    }

    if( co > 0){
      c += co;
      co = 0;
    }

    if (c > 9){
      co = c/10;
      c = c%10;
    }

    output += c + '0';
    if (a.empty() && b.empty() && co == 0) break;
  }

  reverse(output.begin(), output.end());

  while(output.size() > 1 && output.front() == '0'){
    output.erase(output.begin());
  }

  return output;
}
//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  string a1, a2;
  cin >> a1 >> a2;


  reverse(a2.begin(), a2.end());

  std::cout << add(a1, a2) << std::endl;

  return 0;
}

