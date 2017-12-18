#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

typedef long int int32; typedef long long int int64;
typedef unsigned long int uint32; typedef unsigned long long int uint64;
typedef pair<int, int> ii; typedef vector<ii> vii; typedef vector<int> vi;
typedef tuple<int, int, int> iii; typedef tuple<int, int, int, int> iiii;
typedef vector<vi> vvi;

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )
#define LIMIT 1000

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);

  string s1, s2, s3;
  cin >> s1 >> s2;
  int counter = 0;
  for (int i = 0; i < s1.size(); ++i) {
    if (s1[i] != s2[i] ) counter++;
  }

  if (counter%2) std::cout << "impossible" << std::endl;
  else {
    s3 = "";
    counter = counter/2;
    for (int i = 0; i < s1.size(); ++i) {
      if(s1[i] == s2[i]){
        s3 += s1[i];
      }
      else {
        if (counter %2){
          s3 += s1[i];
        }
        else{
          s3 += s2[i];
        }
        counter--;
      }
    }
    std::cout << s3 << std::endl;
  }
  return 0;
}
