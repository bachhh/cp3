#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  bitset<1000001> sieve;
  sieve.set();

  for (int i = 2; i <= 1000; ++i) {
    if(sieve[i])
      for (int j = i*i; j <= 1000000 ; j += i)
        sieve[j] = 0;
  }

  while(true){
    getline(cin, s);
    if (cin.eof()) break;
    int from =  0, to;
    int x = 1;

    while(from < s.size()){
      int p, k;
      to = s.find(' ', from);
      p = stoi(s.substr(from, to));
      from = to+1;

      to = s.find(' ', from);
      if(to == s.npos) to = s.size();
      k = stoi(s.substr(from, to));
      from = to+1;
      x *= pow(p, k);
    }
    x--;
    int rep[100000], n = 0;
    for(int p = x; p >= 2; --p){
      if(sieve[p] && x%p == 0){
        int e = 0;
        while(x%p == 0){
          e++;
          x /= p;
        }
        rep[n] = p, rep[n+1] = e;
        n+= 2;
      }
    }
    for (int i = 0; i < n; ++i) {
      std::cout << rep[i] << " \n"[i==n-1];
    }

  }


  return 0;
}

