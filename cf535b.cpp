#include <bits/stdc++.h>

using namespace std;

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;

  int output = 0;
  for (int i = 0; i < s.size(); i++) {
    // The highest for  is equal to 77... (repeating n times)
    // == 2 + 4 + 2^3 +.. + 2^(s.size)
    output += 1<< (i+1);
    // For every index equal to 4 subtract the index by half the distance
    // From the highest number of that size
    if (s[i] == '4'){
      output -= (1<< (s.size()-i))/2;
    }

  }

  std::cout << output << std::endl;


  return 0;
}

