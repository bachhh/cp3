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
  //ios::sync_with_stdio(false);
  int p_milage, milage;
  string event;
  double fuel_cap = 0, leak = 0, fuel_eco, max_fuel_cap = 0;

  while(true){
    cin >> milage >> event;
    if(milage == 0 && event == "Fuel"){
      cin >> event >> fuel_eco;
      fuel_eco /= 100;
      if (fuel_eco == 0){
        break;
      }
    }
    else{
      fuel_cap += fuel_eco * (milage - p_milage) + leak *(milage - p_milage);
      max_fuel_cap = MAX(max_fuel_cap, fuel_cap);
      if (event == "Goal"){
        printf("%.3f\n", max_fuel_cap);
        leak = fuel_cap = max_fuel_cap = 0;
      }
      else if (event == "Fuel"){
        cin >> event >> fuel_eco;
        fuel_eco /= 100.00;
      }
      else if (event == "Mechanic"){
        leak = 0;
      }
      else if (event == "Gas"){
        cin >> event;
        fuel_cap = 0;
      }
      else if (event == "Leak"){
        leak++;
      }
    }
    printf("Total %0.3f | %.3f x %.3f\n", fuel_cap, fuel_eco + leak, milage - p_milage);
    p_milage = milage;
  }

  return 0;
}

