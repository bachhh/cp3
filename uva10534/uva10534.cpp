#include <bits/stdc++.h>

using namespace std;

#define LIMIT 10002
int v[LIMIT];
int lds[LIMIT];
int lis[LIMIT];
int n;

vector<int> l1;
vector<int> l2;

int increSeq(){
  l1.push_back(v[0]); lis[0] = 1;
  for (int i = 1; i < n; i++) {
    vector<int>::iterator it = lower_bound(l1.begin(), l1.end(), v[i]);
    if (it == l1.end()){
      l1.push_back(v[i]);
      lis[i] = l1.size();
    }
    else {
      int len;
      if (it != l1.begin()){
        len = it - l1.begin() + 1;
      }
      else {
        len = 1;
      }
      *it = v[i];
      lis[i] = len;
    }
  }
}

int decreSeq(int i){
  l2.push_back(v[n-1]); lds[n-1] = 1;
  for (int i = n-2; i >= 0 ; --i) {
    vector<int>::iterator it = lower_bound(l2.begin(), l2.end(), v[i]);
    if (it == l2.end()){
      l2.push_back(v[i]);
      lds[i] = l2.size();
    }
    else {
      int len;
      if (it != l2.begin()){
        len = it - l2.begin() + 1;
      }
      else {
        len = 1;
      }
      *it = v[i];
      lds[i] = len;
    }
  }
}


//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  while(cin >> n && n){
    l1.clear();
    l2.clear();

    for (int i = 0; i < n; i++) {
      cin >> v[i];
      lis[i] = -1;
      lds[i] = -1;
    }

    decreSeq(0);
    increSeq();
    int maxWave = -1;

    for (int i = 0; i < n; i++) {
      maxWave = max(maxWave, 2*min(lis[i], lds[i]) - 1);
    }

    std::cout << maxWave << std::endl;
  }

  return 0;
}

