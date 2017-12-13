#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

typedef long int int32; typedef long long int int64;
typedef unsigned long int uint32; typedef unsigned long long int uint64;
typedef pair<int, int> ii; typedef vector<ii> vii; typedef vector<int> vi;

#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define VISITED 1
#define UNVISITED -1

#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define LOOP(i, n) for (int i = 0; i < n; ++i)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )
#define DEBUG(x) cerr << #x << " is " << x << endl;


void swap(int32* a, int32* b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

// Detail analysis is fully explained in CLSR Chapter 21
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

#define LIMIT 100001

// Encapsulate Union-Find within the integer interface
SetMember* memberArray[LIMIT];
bool isSameSet(int a, int b) {
  return FindSet(memberArray[a]) == FindSet(memberArray[b]);
}
void unionSet(int a, int b){
  UnionSet(memberArray[a], memberArray[b]);
}


// Tree


//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}
