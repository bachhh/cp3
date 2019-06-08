#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define VISITED 1
#define UNVISITED -1

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);


  int64_t ih;
  int64_t wn;
  int64_t N;
  /*
   * With a bit of math, we figure out that
   * log(N+1)/log(N) = log(ih)/log(in)
   * My math can only take me so far, so we find
   * N with binary search
   */

  while(cin >> ih >> wn && (ih||wn) ){
    double value = log(ih)/log(wn);

    if (wn == 1){
      // Ca'n divide by 0
      N = 1;
    }
    else{

      int counter = 1000;
      int high = 1000000;
      int low = 2;
      while(high> low){
        N = low + (high-low)/2;
        if (log(N+1)/log(N) - value < FLT_EPSILON ){
          high = N-1;
        }
        else {
          low = N;
        }
      }
    }

    int j = 1;

    while(N>1 && pow(N, j) < wn){j++;}
    if(pow(N, j) > wn) N = 1;
    if(iw)

    int64_t output_n = 1;
    int64_t output_h = ih;
    int i = 1;

    while( ih/(N+1) > 1){
      ih /= (N+1);
      i *=  N;
      output_h += ih * i;
      output_n += i;
    }
    if (ih/(N+1) == 1) output_h += (ih/(N+1)) *wn;

    std::cout << N << " " << output_n  << " "<< output_h << std::endl;

  }

  return 0;

}

