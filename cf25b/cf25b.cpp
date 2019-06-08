#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; string s;
  cin >> n >> s;
  if (n == 2 || n == 3){
    std::cout << s << std::endl;
    return 0;
  }

  int counter = 0;
  for (int i = 0; i < s.size()-1; i++ ) {
    if (counter == 2 ){
      s.insert(s.begin() + i, '-');
      counter = 0;
    }
    else { counter++;}
  }
  std::cout << s << std::endl;


  return 0;
}

