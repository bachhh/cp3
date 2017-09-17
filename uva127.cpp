#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <unordered_map>
#include <sstream>
#include <stack>
#include <queue>
#include <deque>
#include <iterator>
#include <bitset>
#include <algorithm>
#include <tuple>

using namespace std;

typedef long int int32;
typedef long long int int64;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;

const double pi = acos(-1.0);


#define PI 3.1415926535897932384626433832795
#define INF (int)1e9
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

struct node {
  struct node *prev = NULL;
  struct node *next = NULL;
  string stack[52];
  int st_top = -1;

  struct node* remove(struct node* n){
    if (n->prev != NULL) n->prev->next = n->next;
    if (n->next != NULL) n->next->prev = n->prev;
    struct node* r = n->next;
    free(n);
    return r;
  }

  string top(){
    if ( st_top <  52 && st_top >-1)
      return stack[st_top];
    else
      return "";
  }
  void push(string s){
    st_top++;
    assert(st_top<52);
    stack[st_top] = s;
  }

  bool empty(){
    return st_top == -1;
  }
  string pop(){
    string result = stack[st_top];
    stack[st_top] = "";
    st_top--;
    assert(st_top > -2);
    return result;
  }
  void printStack(struct node* n){
    for (int i=0; i<= n->st_top; i++){
      cout << n->stack[i] << " ";
    }
  }

  void printList(struct node* cur, struct node* from){
    while(from != NULL){
      printStack(from);
      if (from == cur) cout << "*";
      cout << endl;
      from = from->next;
    }
  }
};

bool match(struct node* a, struct node* b){
  if (a == NULL || b == NULL) return false;
  string string_a = a->stack[a->st_top];
  string string_b = b->stack[b->st_top];
  return string_a[0] == string_b[0] || string_a[1] == string_b[1];
}

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdin);


  string temp;
  cin >> temp;
  while(temp != "#"){

    int count = 51;
    struct node* head = ( struct node* ) calloc(1, sizeof(struct node));
    head->st_top = 0;
    head->stack[0] = temp;
    head->prev = NULL;
    struct node* tail = head;

    while(count--){
      cin >> temp;
      struct node* new_node = ( struct node* ) calloc(1, sizeof(struct node));
      new_node->st_top = 0;
      new_node->stack[0] = temp;
      tail->next = new_node;
      new_node->prev = tail;
      new_node->next = NULL;
      tail = new_node;
    }

    int k = 0;
    struct node* cur= head;

    while(cur!= NULL){
      if(cur->empty()){
        cur = cur->remove(cur);
        continue;
      }
      else if (cur->prev != NULL){
        struct node* left = cur->prev;
        struct node* third = (left->prev != NULL ) ? left->prev->prev : NULL;
        if (match(cur, third)){
          third->push(cur->pop());
          cur = head;
          continue;
        }
        else if (match(cur, left)){
          left->push(cur->pop());
          cur = head;
          continue;
        }
      }
      cur = cur->next;
    }

    cur = head;
    int i = 0;
    while(cur != NULL){
      i++;
      cur = cur->next;
    }
    if (i > 1)
      cout << i << " piles remaining:";
    else
      cout << i << " pile remaining:";
    cur = head;
    while(cur != NULL){
      cout << " " << cur->st_top + 1;
      cur = cur->next;
    }
    cout << endl;
    cur = head;
    while(head != NULL){
      cur = head;
      head = head->next;
      free(cur);
    }
    cin >> temp;
  }
  return 0;
}

