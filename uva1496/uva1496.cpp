#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <queue>
#include <deque>
#include <iterator>
#include <bitset>
#include <algorithm>

using namespace std;

typedef long int int32;
typedef long long int int64;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;

const double pi = acos(-1.0);

#define PI 3.1415926535897932384626433832795
#define INF (int)1e9
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)


int main(){
  //freopen("input.txt","r", stdin);
  //freopen("output.txt","w", stdout);
  

  while(true){
    int numberOfSamples;
    int peaks = 0;
    scanf("%d", &numberOfSamples);
    if (numberOfSamples < 2) {
      break;
    }
    else{
      int array[numberOfSamples+2];
      int i = 0;
      while (i < numberOfSamples){
        scanf("%d", &array[i]); 
        i++;
      }
      array[i] = array[0];
      array[i+1] = array[1];
      for(int j = 1; j <= i; j++){
        if (array[j] < array[j-1] && array[j] < array[j+1]){
          peaks++;
        }
        else if (array[j] > array[j-1]  && array[j] > array[j+1]){
          peaks++;
        }
      }
    }
    cout << peaks << endl;
  }
  return 0;
}
