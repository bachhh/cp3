#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

int n, m;
//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  int k;
  vector<vector<int>> small;
  vector<int64_t> total(n);
  vector<int64_t> prefix(n, INT64_MIN);
  vector<int64_t> suffix(n, INT64_MIN);
  vector<int64_t> gen(n, INT64_MIN);

  for (int i = 0; i < n; i++) {
    cin >> k;
    vector<int> temp(k);
    int64_t sum = 0;
    for (int j = 0; j < k; j++) {
      cin >> temp[j];
      sum += temp[j];
      prefix[i] = max<int64_t>(prefix[i], sum);
    }

    total[i] = sum;
    small.push_back(temp);
    for (int j = k-1, sum = 0; j >= 0; --j) {
      sum += temp[j];
      suffix[i] = max<int64_t>(suffix[i], sum);
    }
    for (int j = 0, sum = 0; j < k; j++) {
      sum += temp[j];
      gen[i] = max<int64_t>(gen[i], sum);
      sum = max<int64_t>(sum, 0);
    }
  }

  int index;
  int64_t sum = 0, maxsum = INT64_MIN;
  for (int i = 0; i < m; i++) {
    cin >> index; index--;
    // If the largest seq is entirely contained in small
    maxsum = max<int64_t>(maxsum, gen[index]);

    maxsum = max<int64_t>(maxsum, sum + prefix[index]);
    sum = max<int64_t>(suffix[index],max<int64_t>(sum + total[index], (int64_t)0));

  }
  std::cout << maxsum << std::endl;

  return 0;

}

