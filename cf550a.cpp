#include <bits/stdc++.h>

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
#define FLOAT_PRECISION 1e-8

void swap(int* a, int *b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}


//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  bool ba = false, ab = false;
  int i = 0;
  while( i < s.length()){
    if (s[i] == 'B' && s[i+1] == 'A'){
      ba = true;
      i++;
    }
    else if (s[i] == 'A' && s[i+1] == 'B'){
      ab = true;
      i++;
    }
    i++;
  }

  if ( ba && ab) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}

