#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <queue>
#include <deque>
#include <iterator>
#include <bitset>
#include <algorithm>

using namespace std;

typedef long int int32;
typedef long long int int64;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;

const double pi = acos(-1.0);

#define PI 3.1415926535897932384626433832795
#define INF (int)1e9
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)

map<char, int> charprime;


uint32 hashWord(map<char, int> char_prime, string word){
  uint32 hash=1;
  string word_copy = word;
  transform(word_copy.begin(), word_copy.end(), word_copy.begin(), ::tolower);
  for (char& c : word_copy){
    hash *= char_prime[c]; 
  }
  return hash;
}


int main(){
  freopen("input.txt","r", stdin);
  freopen("output.txt","w", stdout);
  string word;
  map<uint64, int> table;
  map<char, int> char_prime_table;

  vector<int> sieve;
  int prime_max = 200; 

  for (int i = 0; i <= prime_max; i++){
    sieve.push_back(1); 
  }

  sieve[0] = 0; sieve[1] = 0;

  for (int i = 2; i <= prime_max; i++){
    if (sieve[i] == 0){
      continue;
    }
    else {
      int factor = 2*i;
      while(factor <= prime_max){
        sieve[factor] = 0;
        factor += i;
      } 
    } 
  }
  int prime_index = 0;
  for (int i = 'a'; i <= 'z'; i++){
    while( sieve[++prime_index] == 0);
    char_prime_table[(char) i] = prime_index;
  }
  

  vector<string> dictionary;
  while (cin >> word && word != "#"){
    dictionary.push_back(word);
    uint64 hash = hashWord(char_prime_table, word);
    table[hash]++; 
  } 
  
  sort(dictionary.begin(), dictionary.end()); 
  for (auto &i : dictionary){
    uint64 rehash = hashWord(char_prime_table, i);
    if ( table.at(rehash) == 1 ) cout << i << endl;
  }
 
  return 0;
}
