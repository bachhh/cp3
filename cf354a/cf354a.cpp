#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

#define LEFT 1
#define RIGHT 2

int n, l, r, ql, qr;
int w[100001];
int larm[100003];
int rarm[100003];

//  ***** MAIN *****
int main(){

  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> l >> r >> ql >> qr;

  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }

  larm[0] = 0;
  for (int i = 1; i <= n; i++) {
    larm[i] = larm[i-1] + w[i-1];
  }

  rarm[n] = 0;
  for (int i = n-1; i >= 0; --i) {
    rarm[i] = rarm[i+1] + w[i];
  }



  int64_t mi= INT64_MAX;
  for (int k = 0; k <= n; ++k) {
    int64_t weight = larm[k]*l + rarm[k]*r;

    if (n-k > k) weight += abs((n+1-k)-k)*qr;
    if (n-k < k) weight += abs(n+1-k-k)*ql;

    mi = min<int64_t>(mi, weight);

  }

  std::cout << mi << std::endl;

  return 0;
}

