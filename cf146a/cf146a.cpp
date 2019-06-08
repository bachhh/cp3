#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int fh = 0, sh =0;
  int i = (n-1)/2;
  int j = i+1;

  while( i >= 0 ){
    fh += s[i]-'0';
    sh += s[j]-'0';

    if (s[i] != '4' && s[i] != '7'){
      std::cout << "NO" << std::endl;
      return 0;
    }
    if (s[j] != '4' && s[j] != '7' ){
      std::cout << "NO" << std::endl;
      return 0;
    }
    i--;
    j++;
  }
  if(fh == sh){
    std::cout << "YES" << std::endl;
  }
  else {
    std::cout << "NO" << std::endl;
  }

  return 0;
}

