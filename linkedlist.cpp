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


string s;

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
  os << "{";
  typename vector< T > :: const_iterator it;
  for( it = v.begin(); it != v.end(); it++ ) {
    if( it != v.begin() ) os << ", ";
      os << *it;
    }
  return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
  os << "[";
  typename set< T > :: const_iterator it;
  for ( it = v.begin(); it != v.end(); it++ ) {
      if( it != v.begin() ) os << ", ";
        os << *it;
  }
  return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
  os << "[";
  typename map< F , S >::const_iterator it;
  for( it = v.begin(); it != v.end(); it++ ) {
    if( it != v.begin() ) os << ", ";
      os << it -> first << " = " << it -> second ;
  }
  return os << "]";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< vector< T > > &v ) {
  os << "\n";
  typename vector< vector< T > > :: const_iterator row;
  typename vector< T > :: const_iterator col;
  for( row = v.begin(); row != v.end(); ++row ) {
    for( col = (*row).begin(); col != (*row).end(); ++col) {
      os << *col << "\n"[col == prev((*row).end())];
    }
  }
  return os << "\n";
}

ostream &operator << ( ostream & os, const  vii &v ) {
  for(int i = 0; i < v.size(); ++i){
    os << "(" << v[i].first + 1 << ", " << v[i].second << ")"
      << " \n"[i == v.size()-1];
  }
}

ostream &operator << ( ostream & os, const vector< vii > &v ) {
  for(int i = 0; i < v.size(); ++i){
    os << i+1 << " | ";
    for( int j = 0; j < v[i].size(); ++j ) {
      os << "(" << v[i][j].first + 1 << ", " << v[i][j].second << ")"
        << " \n"[j == v[i].size()-1];
    }
  }
  return os << "\n";
}


struct node {
  int data;
  struct node* next;
};

void printf(struct node* head){
  while(head != NULL){
    cout << head->data << " \n"[head->next == NULL];
    head = head->next;
  }
}

void changeToNull( struct node** headRef){
  *headRef = NULL;
}

// Insert a new node before headRef
void Push(struct node** headRef, int newData){
  struct node* newNode = (struct node*) calloc(1, sizeof(struct node));
  newNode->data = newData;
  newNode->next = *headRef;
  *headRef = newNode;
}

struct node* createNode(int value){
  struct node* n = (struct node*) calloc(1, sizeof(struct node));
  n->data = value;
  return n;
}

struct node* build(){
  struct node* head = NULL;
  struct node** lastPtrRef = &head;
  for(int i = 6; i > 0 ; --i){
    Push(lastPtrRef, i);
    lastPtrRef = &((*lastPtrRef)->next);

  }
  return head;
}

struct node* build(const vector<int> &v){
  struct node* head = NULL;
  struct node** lastPtrRef = &head;
  for(auto i : v){
    Push(lastPtrRef, i);
    lastPtrRef = &((*lastPtrRef)->next);
  }
  return head;
}

int length(struct node* head){
  int count = 0;
  while(head != NULL){
    count++;
    head = head->next;
  }
  return count;
}

int Count(struct node* head, int searchFor){
  int c = 0;
  while(head!= NULL){
    c += (head->data == searchFor);
    head = head->next;
  }
  return c;
}

void countTest(){
  struct node* head = build();
  assert(Count(head, 2) == 1);
}

int GetNth(struct node* head, int n){
  assert(n < length(head) );
  while(head!= NULL && n--){
    head = head->next;
  }
  return head->data;
}

void DeleteList( struct node** headRef){
  struct node* current = *headRef;
  struct node* nextNode;
  while(current != NULL){
    nextNode = current->next;
    free(current);
    current = nextNode;
  }
  *headRef = NULL;
}

int Pop(struct node** headRef){
  struct node* head = *headRef;
  assert(head != NULL);
  int output = head->data;
  *headRef = head->next;
  free(head);
  return output;
}

void InsertNth(struct node** headRef,int pos, int data){
  struct node* head = *headRef;
  assert( pos <= length(head));
  while(pos > 0){
    pos--;
    headRef = &((*headRef)->next);
  }
  Push(headRef, data);
}

void SortedInsert(struct node** headRef, struct node* newNode){
  while((*headRef) != NULL && (*headRef)->data < newNode->data){
    headRef = &((*headRef)->next);
  }
  newNode->next = *headRef;
  *headRef = newNode;
}

void InsertSort( struct node** headRef){
  struct node* right = *headRef;
  struct node* insertNode;
  while( right->next != NULL){
    if( right->next->data >= right->data){
      right = right->next;
    }
    else {
      insertNode = right->next;
      right->next = right->next->next;
      SortedInsert(headRef, insertNode);
    }
  }
}

void Append(struct node** aRef, struct node** bRef){
  struct node* tail = *aRef;
  while(tail->next != NULL){
    tail = tail->next;
  }
  tail->next = *bRef;
  *bRef = NULL;
}


void FrontBackSplit(struct node* source, struct node** frontRef, struct node** backRef){
  assert(source != NULL);
  struct node** midRef = &source;
  struct node** fastRef= &source;
  *frontRef = source;
  while(*fastRef != NULL){
    fastRef = &((*fastRef)->next);
    midRef = &((*midRef)->next);
    if (*fastRef == NULL) break;
    fastRef = &((*fastRef)->next);
  }
  *backRef = (*midRef);
  *midRef = NULL;
}


void RemoveDuplicates(struct node* head){
  struct node* trash = NULL;
  while( head->next != NULL){
    while(head->data == head->next->data){
      trash = head->next;
      head->next = head->next->next;
      free(trash);
    }
    head = head->next;
  }
}


void MoveNode(struct node** sourceRef, struct node** destRef){
  if ((*sourceRef) != NULL){
    struct node* temp = (*sourceRef)->next;
    (*sourceRef)->next = *destRef;
    *destRef = *sourceRef;
    *sourceRef = temp;
  }
}


void AlternatingSplit(struct node* source, struct node** aRef, struct node** bRef){
  struct node** moveRef = &source;
  bool to_b = true;
  while(*moveRef != NULL){
    if(to_b){
      MoveNode(moveRef, bRef);
    }
    else{
      MoveNode(moveRef, aRef);
    }
    // Pun intended
    to_b = !to_b;
  }
}


struct node* ShuffleMerge(struct node* a, struct node* b){
  struct node* result = NULL;
  while( a != NULL || b!= NULL){
    MoveNode(&a, &result);
    if(a == NULL){
      while (b != NULL){
        MoveNode(&b, &result);
      }
      break;
    }
    MoveNode(&b, &result);
    if(b == NULL){
      while (a != NULL){
        MoveNode(&a, &result);
      }
      break;
    }
  }
  return result;
}


struct node* SortedMerge(struct node* a, struct node* b){
  struct node* head = NULL;
  struct node** tailRef = &head;
  while(a != NULL && b != NULL){
    if(a->data > b->data){
      *tailRef = b;
      b = b->next;
    }
    else{
      *tailRef = a;
      a = a->next;
    }
    tailRef = &((*tailRef)->next);
  }
  if ( a == NULL){
    *tailRef = b;
  }
  else if (b == NULL){
    *tailRef = a;
  }
  return head;
}

void MergeSort(struct node** headRef){
  if(length(*headRef) < 2){
    return;
  }
  struct node* aRef = NULL;
  struct node* bRef = NULL;
  FrontBackSplit(*headRef, &aRef, &bRef);
  MergeSort(&aRef);
  MergeSort(&bRef);
  *headRef = SortedMerge(aRef,bRef);
}

struct node* SortedIntesect(struct node* a, struct node* b){
  struct node* head = NULL;
  struct node** tailRef = &head;
  while( a != NULL && b != NULL){
    if (a->data < b->data){
      a = a->next;
    }
    else if (b->data < a->data){
      b = b->next;
    }
    else if (b->data == a->data){
      Push(tailRef, b->data);
      tailRef = &((*tailRef)->next);
      a = a->next;
      b = b->next;
    }
  }
  return head;
}

void Reverse(struct node** headRef){
  assert(*headRef != NULL);
  struct node* newHead = NULL;
  struct node* topNode = *headRef;
  struct node* nextNode = (*headRef)->next;
  while(topNode != NULL){
    topNode->next = newHead;
    newHead = topNode;
    topNode = nextNode;
    if (nextNode != NULL) nextNode = nextNode->next;
  }
  *headRef = newHead;
}

void RecursiveReverse(struct node** headRef){
  if ( (*headRef)->next == NULL) return;
  struct node* currentNode = *headRef;
  *headRef = (*headRef)->next;
  RecursiveReverse(headRef);
  currentNode->next->next = currentNode;
  currentNode->next = NULL;
}

//  ***** MAIN *****

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  struct node* head2 = build(vector<int> {1, 2, 5, 6, 9, 11 });
  RecursiveReverse(&head2);
  printf(head2);

  return 0;
}
