#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;

int toInt(string s){
  if (s == "") return 0;
  else return stoi(s);
}

int gcd(int a, int b){
  if (b== 0) return a;
  return gcd(b, a%b);
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int j;
  string s;
  int c = 1;

  while(cin >> j >> s && j > -1 ){
    s = s.substr(2, s.size()-2);

    string nonrep = s.substr(0, s.size()-j);
    string rep = s.substr(s.size()-j, j);

    int num, den;
    if (rep == ""){
      num = stoi(nonrep);
      den = pow(10, s.size());
    }
    else {
      num = stoi(nonrep+rep) - toInt(nonrep);
      den = pow(10,s.size()) - pow(10, s.size()-j);
    }

    int reduce = gcd(num, den);
    num /= reduce;
    den /= reduce;

    printf("Case %d: %d/%d\n",c,  num, den);
    c++;
  }

  return 0;
}

