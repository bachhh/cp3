#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
#define PLIMIT 10000010
#define MOD 1000000007ll
#define INF 1e9
typedef long long ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};

// deg = 4 || -4 = 360 rotation aka  | degree | < 4
void rotate(char axis, int degree, char source[6], char dest[6]){
  int v[4];
  if(axis == 'x'){
    v[0] = 0; v[1] = 1; v[2] = 5; v[3] = 4;
  }
  if(axis == 'y'){
    v[0] = 1; v[1] = 3; v[2] = 4; v[3] = 2;
  }
  if(axis == 'z'){
    v[0] = 0; v[1] = 3; v[2] = 5; v[3] = 2;
  }

  for (int i = 0; i < 6; ++i) {
    dest[i] = source[i];
  }

  for (int i = 0; i < 4; ++i) {
    dest[v[i]] = source[v[ (i+degree) % 4]];
  }
}

bool check(char cube1[6], char cube2[6]){
  for (int i = 0; i < 6; ++i) {
    if(cube1[i] != cube2[i]) return false;
  }
  return true;
}

bool checkRot(char cube1[6], char cube2[6]){
  int t = 1;
  char temp1[6];
  char temp2[6];
  char temp3[6];
  for(char a1 = 'x'; a1 <= 'z'; ++ a1){
    for (int d1 = 0; d1 < 4; ++d1) {

      for(char a2 = 'x'; a2 <= 'z'; ++ a2){
        for (int d2 = 0; d2 < 4; ++d2) {

          for(char a3 = 'x'; a3 <= 'z'; ++ a3){
            for (int d3 = 0; d3 < 4; ++d3) {

              rotate(a1, d1, cube1, temp1);
              rotate(a2, d2, temp1, temp2);
              rotate(a3, d3, temp2, temp3);

              if(check(cube2, temp3)) return true;

            }
          }
        }
      }
    }
  }

  return false;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  string ans[2] = {"FALSE", "TRUE"};
  char cube1[6]= {'1','2','3','4','5'};
  char cube2[6]= {'1','2','3','4','5'};
  char* v[1000];

  int n = 1;
  v[0] = cube1;

  do{
    bool flag = false;
    for (int i = 0; i < n; ++i) {
      flag |= checkRot(v[i], cube2);
    }
    if(!flag){
      char* newcube = (char*)malloc(sizeof(char)*6);
      v[n++] = newcube;
      break;
    }

  }while(next_permutation(cube2, cube2+6));
  std::cout << n << std::endl;

  return 0;
}

