#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

int parent[100001];
int size[100001];
int setCounter;

int n, m;
int makeSet(int v){
  parent[v] = v;
  size[v] = 0;
}

int findSet(int v){
  if (parent[v] == v) return v;
  return parent[v] = findSet(parent[v]);
}

void unionSet(int a, int b){
  a = findSet(a);
  b = findSet(b);
  if(a != b){
    setCounter--;
    if(size[a] < size[b]){
      swap(a, b);
    }
    parent[b] = a;
    size[a] += size[b];
  }
}

void initSet(){
  for (int i = 0; i < n; i++) { makeSet(i); }
  setCounter = n;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  initSet();
  int x[100001] = {0};
  int y[100001] = {0};
  bool flag[100001] = {0};
  int rmv[100001] = {0};

  for (int i = 0; i < m; i++) {
    cin >> x[i] >> y[i]; x[i]--; y[i]--;
  }

  int q; cin>>q;
  for (int i = 0; i < q; i++) {
    cin >> rmv[i]; rmv[i]--;
    flag[rmv[i]] = true;
  }

  for (int i = 0; i < m; i++) {
    if(!flag[i]){
      unionSet(x[i], y[i]);
    }
  }

  vector<int> v;
  for (int i = q-1; i >= 0; --i) {
    v.push_back(setCounter);
    unionSet(x[rmv[i]], y[rmv[i]]);
  }

  for (int i = v.size()-1; i >= 0 ; --i) {
    std::cout << v[i] << " \n"[i==0];
  }




  return 0;
}

