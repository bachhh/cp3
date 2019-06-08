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
    int big;
    int small;
    scanf("%d%d", &big, &small);  
    if(big < 1 && small< 1){
      break;
    }
    else{
      char bigSq[big][big];
      char smallSq[small][small]; 
      getchar();

      for (int r=0; r < big; r++){
        for( int c=0; c < big; c++){
          bigSq[r][c] = getchar();  
        }
        getchar();
      }

      for (int r = 0; r < small; r++){
        for (int c = 0; c < small; c++){
          smallSq[r][c] = getchar();
        }
        getchar();
      }
      
      bool flag; 
      int count = 0;

      // No rotation test
      for (int big_r = 0; big_r <= big - small; big_r++){
        for (int big_c = 0; big_c <= big - small ; big_c++){

          flag = true; 
          for (int small_r = 0; small_r < small; small_r++){
            for (int small_c = 0; small_c < small; small_c++){

              if (smallSq[small_r][small_c] != bigSq[big_r + small_r][small_c + big_c]){
                flag = false;
              }
              if (!flag) break;
            }
            if (!flag) break;
          }
          if(flag) count++;
        }
      } 
      cout << count << ' ';

      // 90* rotation test
      count = 0;
      for (int big_r = big - 1; big_r >= small-1; big_r--){
        for ( int big_c = 0; big_c <= big - small; big_c++){

          flag = true;
          for (int small_r = 0; small_r < small; small_r++){
            for (int small_c = 0; small_c < small; small_c++){

               if ( smallSq[small_r][small_c] != bigSq[big_c +  small_c][big_r - small_r]){
                 flag = false;
               }
               if (!flag) break;
              
            }
            if (!flag) break;
          }
          if (flag) count++;
        }
      }
      cout << count << ' ';
      
      // 180* rotation test
      count = 0;
      for (int big_r = big - 1 ; big_r >= small -1  ; big_r--){
        for ( int big_c = big -1 ;big_c >= small - 1; big_c--){

          flag = true;
          for (int small_r = 0; small_r < small; small_r++){
            for ( int small_c = 0; small_c < small; small_c++){
              if ( smallSq[small_r][small_c] != bigSq[big_r - small_r][big_c - small_c]){
                flag = false;
              }

              if(!flag) break;
            }
            if(!flag) break;
          }
          if(flag) count++;
        }
      }
      cout << count << ' ' ;

      // 270* rotation test
      count = 0;
      for (int big_r = 0; big_r <= big - small; big_r++){
        for ( int big_c = big - 1;big_c >=  small - 1; big_c--){

          flag = true;
          for (int small_r = 0; small_r < small; small_r++){
            for ( int small_c = 0; small_c < small; small_c++){


              if ( smallSq[small_r][small_c] != bigSq[big_c - small_c][big_r + small_r]){
                flag = false;
              }

              if(!flag) break;
            }
             if(!flag) break;
          }
          if(flag) count++;
        }
      }
      cout << count << endl;
    }
  }
  return 0;
}
