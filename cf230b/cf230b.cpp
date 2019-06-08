#include <iostream>
#include <assert.h>
#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <list>
#include <unordered_map>
#include <sstream>
#include <stack>
#include <queue>
#include <deque>
#include <iterator>
#include <bitset>
#include <algorithm>
#include <tuple>
#include <functional>
#include <ctime>

using namespace std;

typedef long int int32;
typedef long long int int64;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;
const double pi = acos(-1.0);

#define PI 3.1415926535897932384626433832795
#define INF (int)1e9
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define LOOP(n) for (int z = 0; z < n; ++z)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

void swap(int* a, int *b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  int n; cin >> n;
  int64 temp;


  bitset<1000001> sieve;
  sieve.set(); sieve.reset(0); sieve.reset(1);
  for(int i = 2; i <= 1000; ++i){
    if (sieve[i]){
      for(int j = i*i; j <= 1000000; j+= i){
        sieve.reset(j);
      }
    }
  }
  LOOP(n){
    cin >> temp;
    /*  @@@ NOT FAST ENOUGH @@@
     *
      if (temp == 4){ cout << "YES" << endl; continue;}
      for(int i = 3; i <= 1000000; i += 2){
        if ((sieve[i]) && ((temp%i) == 0) && ((temp/i)== i) ){
          cout << "YES" << endl;
            temp = -1;
          break;
        }
      }
      if (temp > 0) cout << "NO" << endl;
     */

      // If square root is an integer
    if (sqrt(temp) == ceil(sqrt(temp)) &&
      // and square root is a prime
        sieve[sqrt(temp)]){
      cout << "YES" << endl;
    }
    else cout << "NO" << endl;
  }

  return 0;
}


