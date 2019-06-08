#include <bits/stdc++.h>

using namespace std;

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define LIMIT 100

// Time for codegolf
//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t[5];
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    cin >> t[i];
    sum+= t[i];
  }
  sort(t, t+5);
  int three=0, two=0;
  for (int i = 0; i < 5; i++) {
    if(i < 3 && t[i] == t[i+1] && t[i+1] == t[i+2] &&
                      t[i]*3 > three){
      three = t[i]*3;
    }
    else if (t[i] == t[i+1]
            && t[i]*2 > two){
      two = t[i]*2;
    }
  }
  std::cout << sum - MAX(three, two) << std::endl;



  return 0;
}

