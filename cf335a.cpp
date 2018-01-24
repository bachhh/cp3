#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
#define EPS 1e-9

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  map<char, int> counter;
  int totalChar = 0;
  string s; cin>>s;
  int n; cin >> n;

  for (char c : s) {
    if (counter[c] == 0){
      totalChar++;
    }
    counter[c]++;
  }

  if (totalChar > n){
    std::cout << -1 << std::endl;
    return 0;
  }

  map<char, int> output;
  for (auto p : counter) {
    //p.second--;
    output[p.first]++;
  }
  n -= totalChar;

  while(n>0){
    int highestChar;
    double highestRatio = -1;
    for (auto p : counter) {
      double r = p.second/((double)output[p.first]);
      if (r>highestRatio){
        highestChar = p.first;
        highestRatio = r;
      }
    }
    output[highestChar]++;
    n--;
  }

  int highestChar;
  double highestRatio = -1;
  for (auto p : counter) {
    double r = p.second/((double)output[p.first]);
    if ( r - highestRatio >EPS){
      highestChar = p.first;
      highestRatio = r;
    }
  }

  std::cout << ceil(highestRatio) << std::endl;
  string o = "";
  for (auto p : output) {
    while(p.second>0){
      o+= p.first;
      p.second--;
    }
  }
  std::cout << o << std::endl;


  return 0;
}

