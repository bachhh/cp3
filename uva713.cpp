#include <bits/stdc++.h>

using namespace std;

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define LIMIT 100


//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int tc; cin >> tc;
  string a;
  string b;
  string r;
  int co;
  int i=0;

  while(tc--){
    cin >> a >> b;

    if(a == "0" )
      std::cout << b << std::endl;
    else if (b == "0")
      std::cout << a << std::endl;

    int as = a.size()-1;
    int bs = b.size()-1;

    r = "";
    i = 0;
    co = 0;

    while(i < MIN(a.size(), b.size())) {
      r += (a[i] -'0' + b[i] - '0' + co)%10 + '0';
      co = (a[i] -'0' + b[i] - '0' + co)/10;
      i++;
    }

    while(i < a.size()){
      r += (a[i] - '0' + co)%10 + '0';
      co = (a[i] - '0' + co)/10;
      i++;
    }

    while(i < b.size()){
      r += (b[i] - '0' + co)%10 + '0';
      co = (b[i] - '0' + co)/10;
      i++;
    }

    if(co != 0) r += co+'0';
    int j  =0;
    while(r[j] == '0') j++;
    r.erase(0, j);

    int k  = r.size()-1;
    while(r[k] == '0') k--;
    r.erase(k+1, r.size() - k-1);

    std::cout << r << std::endl;

  }


  return 0;
}

