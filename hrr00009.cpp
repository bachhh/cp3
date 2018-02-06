#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  int grade;
  for (int i = 0; i < n; ++i) {
    cin >> grade;
    if (grade >= 38){
      if ((grade/5+1)*5 - grade < 3){
        grade +=(grade/5+1)*5 - grade;
      }
    }
    std::cout << grade << std::endl;

  }

  return 0;
}

