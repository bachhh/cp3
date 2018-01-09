#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

int childcount[1000] = {0};
int parent[1000] = {0};
int leafcount[1000] = {0};

bool isLeaf(int node){
  return parent[node] != 0 && childcount[node] == 0;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;

  int temp;

  for (int i = 2; i <= n; i++) {
    cin >> temp;
    childcount[temp]++;
    parent[i] = temp;
  }

  for (int i = 1;i <= n; i++) {
    if (isLeaf(i)){
      leafcount[parent[i]]++;
    }
  }
  for (int i = 1; i <=n ; i++) {
    if (!isLeaf(i) && leafcount[i] < 3){
      std::cout << "No" << std::endl;
      return 0;
    }
  }

  std::cout << "Yes" << std::endl;
  return 0;
}

