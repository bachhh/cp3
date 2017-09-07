#include <iostream>
#include <stdio.h>
#include <sstream>
#include <iterator>

using namespace std;

typedef long int int32;
typedef long long int int64;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;

const double pi = acos(-1.0);

#define PI 3.1415926535897932384626433832795
#define INF (int)1e9
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

enum color {RED, BLACK};
struct node {
  int key;
  enum color color;
  node *parent;
  node *left;
  node *right;
};

class RBT {
  node* root;  
  public:
    RBT(){
      root = NULL;
    }
    void leftRotate(node *);
    void rightRotate(node *);
    void insert(node *);
  
};

void RBT::leftRotate(node* x){
  node *y = x.right;
  x.right = y.left;
  if (y.left != NULL){
    y.left.parent = x;
  }
  y.parent = x.parent;
  if (x.parent == NULL){
    root = y;
  }
  else if (x == x.parent.left){
    x.parent.left = y; 
  }
  else {
    x.parent.right = y;
  }
  y.left = x;
  x.parent = y;
}

void RBT::rightRotate(node *x){
  node *y = x.left;
  x.left = y.right;
  if (y.right != NULL){
    y.left.parent = x;
  }
  y.parent = x.parent;
  if (x.parent == NULL){
    root = y;
  }
  else if (x == x.parent.right){
    x.parent.right = y;
  }
  else {
    x.parent.left = y;
  }
  y.right = x;
  x.parent = y;
}

void RBT::insert(node *z){
  node *y = NULL;
  node *x = root;
  while(x!= NULL){
    y = x;
    if (z.key < x.key){
      x = x.left;
    }
    else {
      x = x.right;
    }
  }
  z.parent = y;
  if (y == NULL){
    root = z;
  }
  else if( z.key < y.key){
    y.left = z;
  } 
  else {
    y.right = z;
  }
  z.left = NULL;
  z.right = NULL;
  z.color = RED;
  insertFix(x);
}

void RBT::insertFix(node *z){
  if( root == z){
    z.color = BLACK;
    return;
  }

  while(z.parent != NULL && z.parent.color == RED){
    if(z.parent = z.parent.parent.left){
      node *y = z.parent.parent.right;
      if (y.color == RED){
        z.parent.color = BLACK;
        y.color = BLACK;
        z.parent.parent.color = RED;
        z = z.parent.parent;
      }
      else {
        if(z == z.parent.right){
          z = z.parent;
          leftRotate(z);
        }
        z.parent.color = BLACK;
        z.parent.parent.color = RED;
        rightRotate(z.parent.parent);
      }
    }
    else{
      node y* = z.parent.parent.left;  
      if (y.color == RED){
        z.parent.color = BLACK;
        y.color = BLACK;
        z.parent.parent.color = RED;
        z = z.parent.parent;
      }
      else {
        if(z == z.parent.left){
          z = z.parent;
          rightRotate(z);
        }
        z.parent.color = BLACK;
        z.parent.parent.color = RED:
        leftRotate(z.parent.parent);
      }
    }
  } 
  root.color = BLACK;
}

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdin);
  int n, m;
  while (true){
    cin >> n >> m;
    if (!n && !m) 
      break;

    int temp;
    while(n--){
      cin >> temp;
    }

    while(m--){
      cin >> temp;
    }
  }
   
  return 0;
}

