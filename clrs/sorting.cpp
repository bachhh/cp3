#include <bits/stdc++.h>

using namespace std;

#define LIMIT 50

void debug(int* v, size_t size){
  for (int i = 0; i < size; i++) {
    cout << v[i] <<" \n"[i==size-1];
  }
}

void bubbleSort(int* v, size_t size){
  for (int i = 0; i < size; i++) {
    int j, counter;
    for (counter = 0, j = 0, counter++; j < size; ++counter, ++j) {
      if(v[j] > v[j+1]){
        counter = 0;
        swap(v[j], v[j+1]);
      }
    }
    if (counter == size) break;
  }
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int v[LIMIT];

  for (int i = 0; i < LIMIT; i++) {
    v[i] = rand() % 50;
  }

  bubbleSort(v, LIMIT);
  debug(v, LIMIT);


  return 0;
}

