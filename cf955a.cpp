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

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int hh, mm;
  cin >> hh >> mm;

  int h, d, n;
  double c;

  double cost1, cost2;
  cin >> h >> d >> c >> n;
  if(hh<20){
    int wait = (20-hh-1)*60 + 60-mm;
    int h2 = h+(d*wait);

    cost1 = (h2/n+(h2%n!=0))*(c*0.8);
    cost2 = (h/n+(h%n!=0))*c;
    printf("%.5f\n", min<double>(cost1, cost2));
  }
  else{
    cost1 = (h/n+(h%n!=0))*(c*0.8);
    printf("%.5f\n", cost1);
  }


  return 0;
}

