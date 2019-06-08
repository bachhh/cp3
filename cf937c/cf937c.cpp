#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b){ll i=(a/gcd(a,b))*b;assert(i>0);return i;}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll k, d, t;
  cin >> k >> d >> t;


  ll m = ceil((double)k/d)*d;

  ll f = k*2;
  ll h = (m-k);

  ll c = t*2/(f+h);


  ll left = 2*t - c*(f+h);

  if(left <= f){
    //std::cout << m << std::endl;
    printf("%.2f\n", (double)(c*f)/2 + (c*h) + (double) left/2);
  }
  else {
    printf("%.2f\n", c*(f)/2 + (c*h)+ (double)f/2 + (left-f));
  }

  return 0;
}


