#include <bits/stdc++.h>

using namespace std;

#define LIMIT 1001


typedef pair<int, int> ii;

int parent[LIMIT];
int size[LIMIT];
int setSize;

void makeSet(int v){
  parent[v] = v;
  size[v] = 1;
}

void initSet(size_t n){
  assert(n<=LIMIT);
  for (int i = 0; i < n; i++) { makeSet(i); }
}

int findSet(int v){
  if(v == parent[v]) return v;
  else return parent[v] = findSet(parent[v]);
}

bool isSameSet(int u, int v){
  return findSet(u) == findSet(v);
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

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  initSet(n+1);
  int x, y;

  vector<ii> close;
  vector<ii> build;
  for (int i = 0; i < n-1; i++) {
    cin >> x >> y;
    if (!isSameSet(x, y)){
      unionSet(x, y);
    }
    else {
      close.push_back(ii(x, y));
    }
  }
  stack<int> st;
  for (int i = 1; i <= n; i++) {
    if (parent[i] == i){
      if (!st.empty()){
        build.push_back(ii(i, st.top()));
        st.pop();
        st.push(i);
      }
      else{
        st.push(i);
      }
    }
  }

  printf("%d\n", (int)close.size() );
  for (int i = 0; i < close.size(); i++) {
    printf("%d %d %d %d\n", close[i].first, close[i].second,
                            build[i].first, build[i].second);
  }

  return 0;
}

