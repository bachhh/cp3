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
#include <climits>

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

// Finding the lowest value of interest
// In which the balance at the end of terms is equal or less than 0
// Interest rate is inversely proportion to end of term balance
// p(x) : balance <= 0

double interestRate(double price, double monthlyPayment, int loanTerm){

  if (loanTerm * monthlyPayment - price < 1e-10 )
    return -1;

  double low = 0, high = 1, mid, balance;

  while( (high - low) > 1e-15){
    mid = low + (high - low) / 2;

    balance = price;
    for(int i = 0; i < loanTerm; ++i){
      balance += (mid/12)*balance - monthlyPayment;
    }
    if (balance > 0){
      high = mid;
    }
    else {
      low = mid;
    }
  }
  return low;
}

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  printf("%.18f\n", interestRate( 15000, 364, 48) * 100);


  return 0;
}

