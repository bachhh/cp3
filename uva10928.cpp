#include <bits/stdc++.h>

using namespace std;
typedef long int int32;
typedef long long int int64;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;
typedef pair<int, int> ii;
typedef vector<pair<int, int>> V_ii;
const double pi = acos(-1.0);

#define PI 3.1415926535897932384626433832795
#define INF (int)1e9
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define LOOP(n) for (int z = 0; z < n; ++z)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )
#define FLOAT_PRECISION 1e-8

void swap(int* a, int *b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}


//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);

  int m, n, p, temp, min_count;
  string line;
  vector<int> min_index;

  cin >> n;
  while(n--){
    cin >> p;
    getchar();

    min_index.clear();
    min_count = p*2;

    for(int i = 1; i <= p; ++i){
      getline(cin, line);
      temp = count(line.begin(), line.end(), ' ');
      if(temp < min_count){
        min_count = temp;
        min_index.clear();
        min_index.push_back(i);
      }
      else if (temp == min_count){
        min_index.push_back(i);
      }
    }
    for(int i = 0; i < min_index.size(); ++i){
      cout << min_index[i];
      if ( i < min_index.size() -1) cout << " ";
      else cout << endl;
    }

      getline(cin, line);
  }

  return 0;
}

