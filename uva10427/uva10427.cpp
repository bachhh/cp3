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

int32_t countDigitFrom0(int d){
  return d*pow(10, d);
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int32_t n;
  int32_t pow10[10] = {1, 10, 100, 1000, 10000, 100000,
                      1000000, 10000000, 100000000,
                      1000000000};


  while(cin>>n){
    int i = 1;
    int32_t temp = n;

    if (n<10) { cout << n << endl; continue;}
    while( temp - 9*i*pow10[i-1] > 0){
      temp -= 9*i*pow10[i-1];
      i++;
    }

    // row and col counting start from 0
    int32_t col = (temp-1)/i;
    int32_t row = (temp-1)%i;

    int mostSD = 1 ;



    if (row == 0){
      std::cout << col/pow10[i-1] + 1 << endl;
    }
    else {
      std::cout << (col%pow10[i-row])/pow10[i-row-1] << endl;
    }
    /*k
    else if(row == 2){
      std::cout << (col%pow10[i-3])/pow10[i-3] << std::endl;
    }
    else if (row == 3){
      std::cout << (col%pow10[i-4])/pow10[i-4] << std::endl;
    }*/
  }
  return 0;

}

