#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100001

int parent[LIMIT];
int size[LIMIT];
int setSize;

void makeSet(int v){
  parent[v] = v;
  size[v] = 1;
}

void init(size_t n){
  assert(n<=LIMIT);
  for (int i = 0; i < n; i++) { makeSet(i); }
}

int findSet(int v){
  if(v == parent[v]) return v;
  else return parent[v] = findSet(parent[v]);
}

void unionSet(int a, int b){
  a = findSet(a);
  b = findSet(b);
  if ( a != b){
    if(size[a]<size[b]) swap(a, b);
    size[a]+= size[b];
    parent[b] = a;
  }
}

int getSize(int v){
  return size[findSet(v)];
}


//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  init(n+1);

  int x, y;
  cin >> x >> y;

  int a_set = x;
  int b_set = y;

  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    int x_set = findSet(x);
    int y_set = findSet(y);
    if (x_set == a_set){
      unionSet(b_set,y_set);
      b_set = findSet(b_set);
    }
    else if(x_set == b_set){
      unionSet(a_set,y_set);
      a_set = findSet(a_set);
    }
    else if ((x_set == b_set && y_set == b_set) || (x_set == a_set && y_set == b_set)){
      std::cout << -1 << std::endl;
      return 0;
    }
    else {
      unionSet(a_set,y_set);
      b_set = findSet(b_set);
      unionSet(b_set,y_set);
      a_set = findSet(a_set);
    }
  }

  return 0;
}

