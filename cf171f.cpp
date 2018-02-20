#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int a;
  bool sieve[100];
  memset(sieve, true, 100);
  sieve[0] = false;
  sieve[1] = false;


  for (int i = 2; i < 100; ++i) {
    if (sieve[i]){
      for (int j = 2; j*i < 100 ; ++j) {
        sieve[i*j] = false;
      }
    }
  }

  vector<int> p;

  for (int i = 0; i < 100; ++i) {
    if (sieve[i]) p.push_back(i);
  }

  for (int i = 100; i < 10000000; ++i) {
    bool isPrime = true;
    for (int j = 0; j < p.size(); ++j) {
      if (p[j]*p[j] > i ) break;
      else if (i%p[j] == 0){
        isPrime = false;
        break;
      }
    }
    if (isPrime){
      p.push_back(i);
    }
  }

  for (int i = 0; i < p.size(); ++i) {
    std::cout << p[i] << " \n"[i==p.size()-1];
  }

  return 0;
}

