#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

int64_t memo[311][311][311];

int64_t solve(int coins,int denominator ,int price){
  if(price==0 && coins==0)
    return 1;
  if( denominator> 300 || price < 0 || coins == 0)
    return 0;

  if (memo[coins][denominator][price] != -1) return memo[coins][denominator][price];
  return memo[coins][denominator][price] =
          solve(coins-1, denominator, price-denominator)
        + solve(coins, denominator+1, price);
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  int n, l1, l2;


  for (int i = 0; i < 301; i++) {
    for (int j = 0; j < 301; j++) {
      for (int k = 0; k < 301; ++k) {
        memo[i][j][k] = -1;
      }
    }
  }
  while(true){
    getline(cin, s);
    if(cin.eof() || s == "") break;

    int i1 = s.find(' ', 0);
    int i2 = s.find(' ', i1+1);

    l1 = 0;
    l2 = 300;
    if(i1 == string::npos){
      n = stoi(s);
    }
    else if (i1 != string::npos && i2 == string::npos){
      n = stoi(s.substr(0, i1));
      l1 = 0;
      l2 = stoi(s.substr(i1+1, s.size()-i1));
    }
    else if(i1 != string::npos && i2 != string::npos){
      n = stoi(s.substr(0, i1));
      l1 = stoi(s.substr(i1+1, i2-i1));
      l2 = stoi(s.substr(i2+1, s.size()-i2));
    }
    l1 = min(l1, 300);
    l2 = min(l2, 300);

    int64_t output = 0;
    for (int i = l1; i <= l2 ; i++) {
      output += solve(i, 1, n);
    }
    std::cout << output << std::endl;

  }

  return 0;
}

