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

struct avlNode{
  struct avlNode* left = NULL;
  struct avlNode* right = NULL;
  struct avlNode* parent= NULL;
  int key;
  int bfact = 0;
};

struct avlTree{
  struct avlNode* root = NULL;

  avlNode* treeMax();
  avlNode* subtreeMax(avlNode*);
  avlNode* treeMin();
  avlNode* subtreeMin(avlNode*);
  avlNode* treeFind(int);
  avlNode* orderStat(int);
  avlNode* recurStat(avlNode*, int&, int);

  string stringify(avlNode*);
  void printTree();

  avlNode* bfact_recal(avlNode*, int);
  avlNode* rotateLeft(avlNode*);
  avlNode* rotateRight(avlNode*);
  avlNode* rebalance(avlNode*);

  avlNode* insert(int);
  bool remove(int);

  int height(avlNode*);
  bool heightTest(avlNode*);
  bool balanceTest(avlNode*);
  bool recurTest(avlNode*);
  bool avlTest();
};

// VALUE RETRIEVAL

avlNode* avlTree::treeMax(){
  avlNode* node = root;
  while(node != NULL && node->right != NULL)
    node = node->right;
  return node;
}

avlNode* avlTree::subtreeMax(avlNode* node){
  while(node != NULL && node->right != NULL)
    node = node->right;
  return node;
}

avlNode* avlTree::treeMin(){
  avlNode* node = root;
  while(node != NULL && node->left!= NULL)
    node = node->left;
  return node;
}

avlNode* avlTree::subtreeMin(avlNode* node ){
  while(node != NULL && node->left!= NULL)
    node = node->left;
  return node;
}

avlNode* avlTree::orderStat(int k){
  int i = 0;
  return recurStat(root, i, k);
}

avlNode* avlTree::recurStat(avlNode* node, int &i, int k){
  recurStat(node->right, i, k);
  i++;
  if (i == k)
    return node;
  recurStat(node->left, i, k);
}

avlNode* avlTree::treeFind(int value){
  avlNode* node = root;
  while (node != NULL && value != node->key){
    if(value < node->key)
      node = node->left;
    else if (value > node->key)
      node = node->right;
  }
  return node;
}

// PRINT

string avlTree::stringify(avlNode* node){
  string output = "";
  if (node == NULL) output += "NULL";
  else if(node->left == NULL && node->right == NULL)
    output += to_string(node->key) + "|" + to_string(node->bfact);
  else{
    output += "( " + to_string(node->key) + "|" + to_string(node->bfact) +
            " => " + stringify(node->left) + " : " + stringify(node->right) + " )";
  }
  return output;
}

void avlTree::printTree(){
  cout << stringify(root) << endl;
}

// TREE PROPERTIES CHECKING

int avlTree::height(avlNode* node){
  if (node == NULL) return 0;
  return MAX(height(node->left), height(node->right)) + 1;
}

bool avlTree::heightTest(avlNode* node){
  return (node->bfact == (height(node->right) - height(node->left)));
}

bool avlTree::balanceTest(avlNode* node){
  return unsigned(node->bfact + 1) <= unsigned(2);
}

bool avlTree::recurTest(avlNode* node){
  if (node == NULL) return true;
  else if (heightTest(node) == false){
    cout << "HEIGHT: " << node->key << endl;
    return false;
  }
  else if(balanceTest(node) == false){
    cout << "BALANCE: " << node->key << endl;
    return false;
  }
  else {
    return(recurTest(node->left) && recurTest(node->right));
  }
}

bool avlTree::avlTest(){
  return recurTest(root);
}

// TREE PROPERTIES ENFORCING

avlNode* avlTree::bfact_recal(avlNode* node, int value){
  if (node == NULL){
    return NULL;
  }
  assert(value == 1 || value == -1);
  while(unsigned(node->bfact + 1) <= unsigned(2) && node->parent != NULL){
    if(node == node->parent->left){
      node->parent->bfact -= value;
    }
    else if (node == node->parent->right){
      node->parent->bfact += value;
    }
    node = node->parent;
    if(value == 1 && node->bfact == 0 )
      break;
    else if (value == -1 && node->bfact != 0)
      break;
  }
  // If the node is unbalanced
  if(unsigned(node->bfact + 1 ) > unsigned(2)){
    return node;
  }
  // If we reached a balanced node or root
  else if ( unsigned(node->bfact +1 ) <= unsigned(2) && node->parent == NULL){
    return NULL;
  }
  else {
    return node;
  }
}

avlNode* avlTree::rotateLeft(avlNode* node){
  avlNode* child = node->right;
  if ( child == NULL) return NULL;
  else {
    // Recalculates balance factor
    int old_node_bfact  = node->bfact;
    int old_child_bfact = child->bfact;
    // For the node
    node->bfact = old_node_bfact - MAX(0, old_child_bfact) - 1;
    // For the child
    child->bfact = old_child_bfact + MIN(0, node->bfact) - 1;
    // Moving pointers
    node->right = child->left;
    if (child->left != NULL){
      child->left->parent = node;
    }
    child->parent = node->parent;
    if (node->parent == NULL){
      root = child;
    }
    else if (node == node->parent->left){
      node->parent->left = child;
    }
    else if (node == node->parent->right){
      node->parent->right = child;
    }
    child->left = node;
    node->parent = child;
    return child;
  }
}

avlNode* avlTree::rotateRight(avlNode* node){
  avlNode* child = node->left;
  if (child == NULL) return NULL;
  else {
    // Recalculates balance factor
    int old_node_bfact  = node->bfact;
    int old_child_bfact = child->bfact;
    // For the node
    node->bfact = old_node_bfact - MIN(0, old_child_bfact) + 1;
    // For the child
    child->bfact = old_child_bfact + 1 + MAX(0, node->bfact);

    // Moving pointers
    node->left= child->right;
    if (child->right != NULL){
      child->right->parent = node;
    }
    child->parent = node->parent;
    if (node->parent == NULL){
      root = child;
    }
    else if (node == node->parent->left){
      node->parent->left = child;
    }
    else if (node == node->parent->right){
      node->parent->right = child;
    }
    child->right = node;
    node->parent = child;
    return child;
  }
}

avlNode* avlTree::rebalance(avlNode* node){
  if ( node != NULL && unsigned(node->bfact +1) > unsigned(2)){
    if(node->bfact == 2){
      if (node->right->bfact == -1){
        rotateRight(node->right);
      }
      return rotateLeft(node);
    }
    else if (node->bfact == -2){
      if (node->left->bfact == 1){
        rotateLeft(node->left);
      }
      return rotateRight(node);
    }
  }
  else {
    return NULL;
  }
}

//  ***** INSERT / DELETE *****
avlNode* avlTree::insert(int value){
  if (treeFind(value) != NULL) return NULL;
  else{
    avlNode* parent = root;
    avlNode* new_node = (avlNode*) calloc(1, sizeof(struct avlNode));
    new_node->key = value;
    while(parent != NULL){
      if(value < parent->key){
        if (parent->left == NULL) break;
        parent = parent->left;
      }
      else if (value > parent->key){
        if (parent->right == NULL) break;
        parent = parent->right;
      }
    }
    new_node->parent = parent;
    if(parent == NULL) root = new_node;
    else{
      if(value < parent->key) parent->left = new_node;
      else parent->right = new_node;
    }
    avlNode* imbalance = bfact_recal(new_node, 1);
    rebalance(imbalance);
    return new_node;
  }
}

bool avlTree::remove(int value){
  avlNode* n = treeFind(value);
  if (n == NULL) return false;
  else {
    if(n->left == NULL && n->right == NULL){
      if (n->parent == NULL){
        root = NULL;
      }
      else if (n == n->parent->left){
        n->parent->left = NULL;
        n->parent->bfact++;
      }
      else if (n == n->parent->right){
        n->parent->right = NULL;
        n->parent->bfact--;
      }
      avlNode* imbalance = n->parent;
      if (  imbalance != NULL &&
            (unsigned(imbalance->bfact+1) > unsigned(2) ||
            imbalance->bfact == 0)){
        while(imbalance != NULL){
          if (unsigned(imbalance->bfact + 1) > unsigned(2)){
            imbalance = rebalance(imbalance);
          }
          if(imbalance->bfact == 0 ){
            imbalance = bfact_recal(imbalance, -1);
          }
          else if (imbalance->bfact == 1 || imbalance->bfact == -1){
            break;
          }
        }
      }
    }
    else if (n->left == NULL ^ n->right == NULL){
      avlNode* n_child = MAX(n->left, n->right);
      assert(n_child != NULL);
      n_child->parent = n->parent;
      if (n->parent == NULL){
        root = n_child;
      }
      else if (n == n->parent->left){
        n->parent->left = n_child;
        n->parent->bfact++;
      }
      else if(n == n->parent->right){
        n->parent->right = n_child;
        n->parent->bfact--;
      }
      avlNode* imbalance = n->parent;
      if ( imbalance != NULL &&
           (unsigned(imbalance->bfact+1) > unsigned(2) ||
           imbalance->bfact == 0) ){
        while(imbalance != NULL){
          if (unsigned(imbalance->bfact + 1) > unsigned(2)){
            imbalance = rebalance(imbalance);
          }
          if ( imbalance->bfact == 0){
            imbalance = bfact_recal(imbalance, -1);
          }
          else if (imbalance->bfact == 1 || imbalance->bfact == -1){
            break;
          }
        }
      }
    }
    else if(n->left != NULL && n->right != NULL){
      // Successor is guaranteed not NULL
      avlNode* successor = subtreeMin(n->right);
      // May be null
      avlNode* s_child = successor->right;
      // Replace n with it's successor (key value copy)
      n->key = successor->key;
      // Snipped off the successor
      if (successor == successor->parent->left){
        successor->parent->left = s_child;
        successor->parent->bfact++;
      }
      else if (successor == successor->parent->right){
        successor->parent->right= s_child;
        successor->parent->bfact--;
      }
      if (s_child != NULL){
        s_child->parent = successor->parent;
      }
      // Free the successor node instead of n
      avlNode* imbalance = successor->parent;
      if ( unsigned(imbalance->bfact+1) > unsigned(2) || imbalance->bfact == 0){
        while(imbalance != NULL){
          if (unsigned(imbalance->bfact + 1) > unsigned(2)){
            imbalance = rebalance(imbalance);
          }
          if (imbalance->bfact == 0){
            imbalance = bfact_recal(imbalance, -1);
          }
          else if (imbalance->bfact == 1 || imbalance->bfact == -1){
            break;
          }
        }
      }
      n = successor;
    }
    free(n);
    return avlTest() ;
  }
}
//  ***** MAIN *****

int main(){
  ios::sync_with_stdio(false);
  vector<int> v;
  int total = 1000;

  avlTree tree = avlTree();
  for (int i =0; i<total; i++)
    v.push_back(i);

  std::random_shuffle(v.begin(), v.end());

  for(int i = 0; i<total; ++i){
    tree.insert(v[i]);
    if (tree.avlTest() == false){
      cout << v[i] << endl;
      break;
    }
  }

  std::random_shuffle(v.begin(), v.end());
  for(int i =0; i < total;  ++i){
    if (!tree.remove(v[i]) ) {
      cout << v[i] << endl;
      break;
    }
  }

  if (tree.avlTest() == true)

    cout << "TRUE" << endl;
  else cout << "FALSE" << endl;



  return 0;
}
