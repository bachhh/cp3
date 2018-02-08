#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

string nextNumber(string w, int index){
  if (index < 0 ){
    return "1"+w;
  }

  w[index]++;
  if(w[index] > '9'){
    w[index] = '0';
    w = nextNumber(w, index-1);
  }
  return w;
}

bool isMask(string s, string t){
  string temp = "";
  for (int i = 0; i < s.size(); ++i) {
    if(s[i] == '4' || s[i] == '7')
      temp += s[i];
  }
  return temp == t;

}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string a, b;
  cin >> a >> b;


  a = nextNumber(a, a.size()-1);
  while(!isMask(a, b)){
    a = nextNumber(a, a.size()-1);
  }

  std::cout << a << std::endl;

  return 0;
}

