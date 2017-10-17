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
  avlNode* treeMin();
  avlNode* treeFind(int);
  avlNode* orderStat(int);
  avlNode* recurStat(avlNode*, int&, int);

  string stringify(avlNode*);
  void printTree();

  avlNode* bfact_recal(avlNode*, int);
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
  while(node->right != NULL)
    node = node->right;
  return node;
}

avlNode* avlTree::treeMin(){
  avlNode* node = root;
  while(node->left!= NULL)
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
  return MAX(height(node->left), height(node->right) + 1);
}

bool avlTree::heightTest(avlNode* node){
  return (node->bfact == height(node->right) - height(node->left));
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
  if (node == NULL) return NULL;
  assert(value == 1 || value == -1);
  while(unsigned(node->bfact + 1) <= unsigned(2) && node->parent != NULL){
    if(node == node->parent->left){
      node->parent->bfact -= value;
    }
    else if (node == node->parent->right){
      node->parent->bfact += value;
    }
    node = node->parent;
  }

  // If we reached a balanced root
  if(unsigned(node->bfact + 1 ) <= unsigned(2) && node->parent == NULL)
    return NULL;
  else
    return node;
}

avlNode* avlTree::rebalance(avlNode* node){

}

//  ***** MAIN *****

int main(){
  ios::sync_with_stdio(false);
  vector<int> v;

  for (int i =0; i<10; i++){
    v.push_back(i);
  }

  std::random_shuffle(v.begin(), v.end());

  return 0;
}
