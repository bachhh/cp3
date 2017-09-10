#include <iostream>
#include <stdio.h>
#include <sstream>
#include <iterator>
#include <stack>
#include <queue>
#include <assert.h>

using namespace std;

typedef long int int32;
typedef long long int int64;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;

#define PI 3.1415926535897932384626433832795
#define INF (int)1e9

enum color {RED, BLACK};
struct node {
  int key;
  enum color color;
  node *parent;
  node *left;
  node *right;
};

class RBT {
  public:
    node* root;  
    node* nil;
    RBT(){
      nil = new node;
      root = nil;
       
      nil->color = BLACK;
      root->parent = nil;
      root->left = nil;
      root->right = nil;
    }
    void leftRotate(node *);
    void rightRotate(node *);
    void insert(node *);
    void remove(node *);
    void preOrderTraverse();
    bool search( int );
    node* treeMin(node *);

  private:
    void insertFix(node *);
    void removeFix(node *);
    void transplant(node*, node*);
};

void RBT::leftRotate(node* x){
  if (x == nil || x == NULL) return;
  node *y = x->right;
  if (y == nil || y == NULL) return;

  x->right = y->left;
  if (y->left != nil){
    y->left->parent = x;
  }
  y->parent = x->parent;
  if (x->parent == nil){
    root = y; 
  }
  else if (x == x->parent->left) {
    x->parent->left = y; 
  }
  else {
    x->parent->right = y;
  }
  y->left = x;
  x->parent = y;

}

void RBT::rightRotate(node *x){
  if (x == nil || x == NULL) return;
  node *y = x->left;
  if (y == nil || y == NULL) return;

  x->left = y->right;
  if (y->right != nil){
    y->right->parent = x;
  }
  y->parent = x->parent;
  if (x->parent == nil){
    root = y;
  }
  else if (x == x->parent->right){
    x->parent->right = y;
  }
  else {
    x->parent->left = y;
  }
  y->right = x;
  x->parent = y;
}

void RBT::insert(node *z){

  assert(z != NULL);   

  node *y = nil;
  node *x = root;

  while (x != nil){
    y = x;
    if (z->key < x->key)
      x = x->left;
    else 
      x = x->right;
  }

  z->parent = y;
  if (y == nil){
    root = z;
  }
  else if (z->key < y->key)
    y->left = z;
  else
    y->right = z;

  z->left = nil;
  z->right = nil;
  z->color = RED;
  insertFix(z);
}

void RBT::insertFix(node *z){
  assert(z != NULL);
  while(z->parent->color == RED){
    if(z->parent == z->parent->parent->left){
      node *y = z->parent->parent->right;
      if (y->color == RED){
        z->parent->color = BLACK;
        y->color = BLACK;
        z->parent->parent->color = RED;
        z = z->parent->parent;
      }
      else {
        if(z == z->parent->right){
          z = z->parent;
          leftRotate(z);
        }
        z->parent->color = BLACK;
        z->parent->parent->color = RED;
        rightRotate(z->parent->parent);
      }
    }
    else {
      node *y = z->parent->parent->left;  
      if (y->color == RED){
        z->parent->color = BLACK;
        y->color = BLACK;
        z->parent->parent->color = RED;
        z = z->parent->parent;
      }
      else {
        if(z == z->parent->left){
          z = z->parent;
          rightRotate(z);
        }
        z->parent->color = BLACK;
        z->parent->parent->color = RED;
        leftRotate(z->parent->parent);
      }
    }
  } 
  root->color = BLACK;
}

void RBT::transplant(node *u, node *v){
  if (u->parent == nil || u->parent == nil){
    root = v;
  }
  else if( u == u->parent->left){
    u->parent->left = v;
  }
  else {
    u->parent->right = v;
  }
  v->parent = u->parent;
}

node* RBT::treeMin(node *u){
  while( u->left != nil && u->left != NULL) {
    u = u->left;
  }
  return u;
}

void RBT::preOrderTraverse(){
  if (root == NULL) return; 
  else {
    queue<node*> node_queue;
    node_queue.push(root);
    while (!node_queue.empty()){
      cout << node_queue.front()->key;
      if (node_queue.front()->color == BLACK) cout << "B" << " ";
      else cout << "R" << " ";
      if (node_queue.front()->left != nil) node_queue.push(node_queue.front()->left);
      if (node_queue.front()->right != nil) node_queue.push(node_queue.front()->right);
      node_queue.pop();
    }
  }
}

bool RBT::search(int key){
  node *x = root;
  while(x != nil && x != NULL) {
    if (key < x->key ) x = x->left;
    else if (key > x->key) x = x->right;
    else if (key == x->key) return true;
  }
  return false;
}

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdin);

  int m, n;
  cin >> n >> m;
  while( m != 0 && n != 0){
    RBT tree; 
    while( n--){
      int i; cin >> i;
      node *x = new node();
      x->key = i; x->parent = NULL; x->left = NULL, x->right = NULL;
      tree.insert(x);
    }
    int count = 0;
    while(m--){
      int temp; cin >> temp;       
      if(tree.search(temp)) count++;
    }
    cout << count << endl;
    cin >> n >> m;
  }
  return 0;
}

