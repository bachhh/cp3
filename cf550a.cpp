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
  vector<int> ba;
  vector<int> ab;
  for(int i =0; i < s.length() -1; i++){
    if(s[i] == 'B' && s[i+1] == 'A'){
      ba.push_back(i);
    }
    else if (s[i] == 'A' && s[i+1] == 'B'){
      ab.push_back(i);
    }
  }

  bool found = false;
  for(int i = 0; !found && i < ab.size(); ++i){
    for(int j = 0; !found && j < ba.size(); ++j){
      if(abs(ab[i] - ba[j]) > 1){
        found = true;
      }
    }
  }
  if (found) cout << "YES" << endl;
  else cout << "NO" << endl;



  return 0;
}

