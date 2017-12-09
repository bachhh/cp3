#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

typedef long int int32; typedef long long int int64;
typedef unsigned long int uint32; typedef unsigned long long int uint64;
typedef pair<int, int> ii; typedef vector<ii> vii; typedef vector<int> vi;
typedef tuple<int, int, int> iii;
typedef vector<vi> vvi;

#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define VISITED 1
#define UNVISITED -1
#define EXPLORED 2
#define FLOAT_EPSILON 1e-6

#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define LOOP(i, n) for (int i = 0; i < n; ++i)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )
#define DEBUG(x) cerr << #x << " is " << x << endl;


void debug(const vector<tuple<int, int, int>>&v){
  printf("\n");
  for(auto t : v){
    printf("{%d, %d, %d}\n",get<0>(t),get<1>(t),get<2>(t)  );
  }
  printf("\n");
}
// Linked List
typedef struct disjointset {
  struct setmember* tail = NULL;
  struct setmember* head = NULL;
  size_t length;
}DisjointSet;

typedef struct setmember{
  struct disjointset* memberOf = NULL;
  int id;
  struct setmember* nextMember = NULL;
}SetMember;

SetMember* MakeSet(int value){
  SetMember* m = (SetMember*) calloc(1, sizeof(SetMember));
  DisjointSet* s = (DisjointSet*) calloc(1, sizeof(DisjointSet));
  s->length = 1;
  s->head = s->tail = m;
  m->memberOf = s;
  m->id = value;
  return m;
}

DisjointSet* FindSet(SetMember* u){
  return u->memberOf;
}

DisjointSet* UnionSet(SetMember* u, SetMember* v){
  DisjointSet* larger;
  DisjointSet* smaller;
  if (u->memberOf->length > v->memberOf->length){
    larger = u->memberOf;
  }
  else{
    larger = v->memberOf;
  }
  if (u->memberOf->length > v->memberOf->length){
    smaller = v->memberOf;
  }
  else{
    smaller = u->memberOf;
  }

  SetMember* current = smaller->head;
  larger->length += smaller->length;
  larger->tail->nextMember = current;
  larger->tail = smaller->tail;
  while(current != NULL ){
    current->memberOf = larger;
    current = current->nextMember;
  }
  free(smaller);
  return larger;
}

#define LIMIT 200001

// Encapsulate Union-Find within the integer interface
SetMember* memberArray[LIMIT];
bool isSameSet(int a, int b) {
  return FindSet(memberArray[a]) == FindSet(memberArray[b]);
}
void unionSet(int a, int b){
  UnionSet(memberArray[a], memberArray[b]);
}

vector< tuple<int, int, int> > el;
vector<vii> al;

int dfs_num[101];

int dfs(int u, int destination){
  dfs_num[u] = VISITED;
  if (u == destination) return 0;
  int r;
  for(ii p : al[u]){
    int neighbor = p.first;
    if (dfs_num[neighbor] == UNVISITED){
      r = dfs(neighbor, destination);
      if (r == 0){
        r = p.second;
        return r;
      }
      else if(r > 0){
        r = MIN(r, p.second);
        return r;
      }
    }
  }
  return -1;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int rolling;
  int n, r, s,d, t;
  int x, y, c;
  vi route;

  int cn = 1;
  while(cin >> n >> r && n > 0){
    el.clear();
    LOOP(i, n+1){
      memberArray[i] = MakeSet(i);
      al.push_back(vii {});
      dfs_num[i] = UNVISITED;
    }
    LOOP(i, r){
      cin >> x >> y >> c;
      el.push_back( iii(x, y, c-1) );
    }
    sort(el.begin(), el.end(), [](iii a, iii b){
        return get<2>(a) > get<2>(b);
    });
    cin >> s >> d >> t;
    al.clear();
    route.clear();
    for(auto edge : el){
      if (!isSameSet(get<0>(edge), get<1>(edge))){
        al[get<0>(edge)].push_back( {get<1>(edge), get<2>(edge)} );
        al[get<1>(edge)].push_back( {get<0>(edge), get<2>(edge)} );
        unionSet(get<0>(edge), get<1>(edge));
      }
    }
    int min_cost = dfs( s, d);
    printf("Scenario #%d\n", cn++);
    printf("Minimum Number of Trips = %d\n", (t % min_cost)?(t/min_cost+1):(t/min_cost));
    printf("\n");

  }

  return 0;
}

