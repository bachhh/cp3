#include <bits/stdc++.h>

using namespace std;

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string y = "Bulbasaur";

  string z;
  cin >> z;
  int v[7] = {0};

  for(char c: z){
    switch(c){
      case 'B': v[0]++; break;
      case 'u': v[1]++; break;
      case 'l': v[2]++; break;
      case 'b': v[3]++; break;
      case 'a': v[4]++; break;
      case 's': v[5]++; break;
      case 'r': v[6]++; break;
    }
  }
  int min = INT_MAX;
  for (int i = 0; i < 7; i++) {
    if(i == 1 || i == 4){
      min = MIN(min, v[i]/2);
    }
    else {
      min = MIN(min, v[i]);
    }
  }
  std::cout << min << std::endl;


  return 0;
}

