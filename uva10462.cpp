#include <bits/stdc++.h>

using namespace std;

#define LIMIT 102

int v, e;

typedef tuple<int, int, int> iii;
vector<iii> el;
int parent[LIMIT];

int find( int i){
  if (parent[i] == -1) return i;
  return find(parent[i]);
}

bool isSameSet(int a, int b){
  return (find(a) == find(b));
}

void unionSet( int a, int b){
  int aset = find(a);
  int bset = find(b);
  parent[bset] = aset;
}

bool isConnected(){
  int counter = 0;
  for (int i = 0; i < v; i++) {
    if(parent[i] == -1){
      counter++;
    }
  }
  // false if more than 1 vertices belongs to it's own set
  //assert(counter > 0);
  return counter == 1;
}

string kruskal(){

  for (int i = 0; i < v; i++) { parent[i] = -1; }
  // compute the tree
  vector<int> treeEdges;
  for (int i = 0; i < el.size(); i++) {
    auto e = el[i];
    if (isSameSet(get<2>(e), get<1>(e))) continue;
    treeEdges.push_back(i);
    unionSet(get<1>(e), get<2>(e));
  }

  if (!isConnected()) return "No way";

  int secondBest = INT_MAX;
  // Temporary flag each edge in the tree, run kruskal again
  for (int edge : treeEdges) {
    for (int i = 0; i < v; i++) { parent[i] = -1; }
    int output = 0;
    for (int i = 0; i < el.size(); i++) {
      if (i == edge) continue;
      auto e = el[i];
      if (isSameSet(get<1>(e), get<2>(e))) continue;
      output += get<0>(e);
      unionSet(get<1>(e), get<2>(e));
    }
    if(isConnected()){
      secondBest = min(secondBest, output);
    }

  }

  if (!(secondBest < INT_MAX)){
    return "No second way";
  }
  return (to_string(secondBest));
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(felse);
  cin.tie(NULL);

  int tc; cin >> tc;
  for(int cn = 1; cn <= tc; ++cn ){
    for (int i = 0; i < v; i++) { parent[i] = -1; }
    el.clear();
    cin >> v >> e;
    int w, x, y;
    for (int i = 0; i < e; i++) {
      cin >> x >> y >> w;
      el.push_back(iii(w, x-1, y-1));
    }
    sort(el.begin(), el.end(), [](iii a, iii b){
                            return get<0>(a) < get<0>(b); });

    cout <<  "Case #" << cn <<  " : " << kruskal() << endl;
  }


  return 0;
}

