#include <bits/stdc++.h>

using namespace std;

#define LIMIT 1000002

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, k;
  cin >> n >> m >> k;

  vector<int> v(LIMIT, 0);
  int temp, sum = 0;

  for (int i = 0; i < n; i++) {
    cin >> temp;
    v[temp]++;
    if ( temp <=m ) sum++;
  }

  int index = m;
  int output = (sum >= k)?(sum-k+1):0;

  while(index > 0 && sum >= k){
    if (v[index] < sum ){
      sum -= v[index];
      v[index] = 0;
      index--;
    }
    else {
      v[index] -= sum;
      sum = 0;
    }
  }

  int l = 1;
  int r = m+1;
  while(r <= LIMIT){
    sum += v[r]; sum -= v[l];

    if(sum >= k){
      v[r] = v[r] - (sum - k + 1);
      output += sum-k+1;
      sum = k-1;
    }
    r++;
    l++;
  }
  std::cout << output << std::endl;

  return 0;
}

