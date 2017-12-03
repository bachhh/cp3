#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <cmath>
#include <string>
#include <string.h>
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
#include <functional>
#include <ctime>

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

void swap(int* a, int *b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

struct node {
  struct node* left = NULL;
  struct node* right = NULL;
  int value;
};

//Return pointer to newly inserted node
struct node* insertNode(struct node* root, struct node* new_node){
  struct node* parent = NULL;
  while(root != NULL){
    parent = root;
    if (new_node->value < root->value){
      root = root->left;
    }
    else if(new_node->value > root->value){
      root = root->right;
    }
  }
  if(parent != NULL && new_node->value < parent->value){
    parent->left = new_node;
  }
  else if ( parent != NULL && new_node->value > parent->value){
    parent->right = new_node;
  }
  return new_node;
}

// Transform a Binary tree of node to a double ended circular linked list
// Return pointer to the first element of the list
struct node* transform(struct node* root){
  stack<struct node*> s;
  struct node* prev = NULL;

  struct node* current= root;

  while(!s.empty() || current != NULL){
    if (current!= NULL){
      s.push(current);
      current = current->left;
    }
    else{
      current = s.top();
      s.pop();
      // Process popped item
      if (prev!= NULL) prev->right = current;
      current->left = prev;
      prev = current;

      current = current->right;
    }
  }
  // done stack;

  //Rewind to connect last and firs node
  struct node* head = prev;
  while(head->left != NULL){
    head = head->left;
  }
  prev->right = head;
  head->left = prev;
  return head;
}

void printTree(struct node* root){
  queue<struct node*> q;
  q.push(root);
  struct node* temp;
  while(!q.empty()){
    temp = q.front();
    q.pop();
    cout << (temp->value) << endl;
    if (temp->left != NULL)q.push(temp->left);
    if (temp->right!= NULL)q.push(temp->right);
  }
}

int main(){
  ios::sync_with_stdio(false);
  vector<int> v;

  for (int i =0; i<10; i++){
    v.push_back(i);
  }

  std::random_shuffle(v.begin(), v.end());

  struct node* root = (struct node*) calloc(1, sizeof(struct node));

  root->value = v[0];

  for(int i=1; i<v.size(); ++i){
    struct node* temp =  (struct node*) calloc(1, sizeof(struct node));
    temp->value = v[i];
    temp->left = NULL;
    temp->right= NULL;
    insertNode(root, temp);
  }
  cout <<  "done inserting" << endl;
  root =transform(root);
  while(root != NULL) {
    cout << root->value << " ";
    root = root->right;
  }
  cout << endl;

  return 0;
}
