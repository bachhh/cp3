#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
bool checkPalin(int64_t n){
  string s = to_string(n);
  int i = s.size()/2-1;
  int j = i+1;
  while(i>= 0 && j < s.size()){
    if (s[i] != s[j]) return false;
    i--;
    j++;
  }
  return true;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int64_t k, p;
  cin >> k >> p;

  int64_t ret = 0;


  int64_t offset = 0;
  for (int64_t i = offset; i <= offset+k; i++) {
    int64_t palin;
    if (i < 10){
      palin = i*10 + i;
    }
    // 1221
    else if (i <100){
      palin = i*100 + i%10*10 + i/10 ;
    }
    // 122 221
    else if (i < 1000){
      palin = i*1000  + (i%10)*100 + ((i/10)%10)*10 + i/100;
    }
    // 1234 4321
    else if (i < 10000){
      palin = i*10000  + (i%10)*1000 + ((i/10)%10)*100 + ((i/100)%10)*10 + i/1000;
    }
    // 12345 54321
    else if (i < 100000){
      palin = (i*100000) + ((i%10)*10000) + (((i/10)%10)*1000)
        + (((i/100)%10)*100) + ((i/1000)%10)*10 + i/10000;
    }
    // 100000 00001
    else if (i == 100000){
      palin = i*1000000 + 1;
    }
    ret += palin% p;
    ret %= p;
  }
  std::cout << ret << std::endl;

  return 0;
}

