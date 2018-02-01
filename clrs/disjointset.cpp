#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

#define INF (int)1e9

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
    setSize--;
  }
}

