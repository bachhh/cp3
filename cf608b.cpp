#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string a, b;

  cin >> a >> b;

  int64_t prefix[200000][2];
  memset(prefix, 0, sizeof(prefix[0][0])*200000*2);
  prefix[0][0] = (b[0] == '0');
  prefix[0][1] = (b[0] == '1');

  for (int i = 1; i < b.size(); i++) {
    prefix[i][0] += prefix[i-1][0] + (b[i] =='0');
    prefix[i][1] += prefix[i-1][1] + (b[i] =='1');
  }

  int as = a.size(), bs = b.size();
  int64_t output = prefix[bs-as][a[0] == '0'];

  for (int i = 1; i < a.size(); i++) {
    // Find the number of difference between a[i] and
    // digits in the interval b[i, bs-as+i];
    output += prefix[bs-as+i][a[i] == '0'] - prefix[i-1][a[i] == '0'];
  }

  std::cout << output << std::endl;

  return 0;
}

