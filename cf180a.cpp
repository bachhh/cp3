#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int , int > ii;
typedef int64_t ll;

//  ***** MAIN *****
int main(){

  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;

  cin >> n >> m;

  int file[200];
  memset(file, -1, sizeof(int)*200);

  int temp;
  vector<int> v;
  int k;
  // i == file, j == cluster
  for (int i = 0; i < m; ++i) {
    cin >> k;
    for (int j = 0; j < k; ++j) {
      cin >> temp;
      v.push_back(temp);
      file[temp] = i;
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (file[i] == -1) {
      temp = i;
      break;
    }
  }


  vector<ii> op;
  for (int i = 0; i < v.size(); ++i) {
    int cur = i+1;
    if(v[i] != cur){
      if(file[cur] == -1){
        if (cur ==  temp){
          temp = v[i];
        }
        op.push_back(ii(v[i], cur));
        file[v[i]] = -1;
        v[i] = cur;
      }
      else {
        int j = i;
        while(v[++j] != cur);
        op.push_back(ii(cur, temp));
        op.push_back(ii(v[i], cur));
        op.push_back(ii(temp, v[i]));
        v[j] = v[i];
        file[v[i]] = file[temp];
      }
    }
  }

  std::cout << op.size() << std::endl;
  for (auto p : op) {
    printf("%d %d\n", p.first, p.second);
  }

  return 0;
}

