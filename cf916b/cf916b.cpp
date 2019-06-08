#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
#define OFFSET 63

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int64_t n, k;
  cin >> n >> k;
  vector<int> s(133, 0);
  int counter = 0;
  int largest = 0;
  int smallest = INT_MAX;
  for (int bit = 0; bit < 64; ++bit) {
    if (n & ((int64_t)1<<bit)){
      s[bit+OFFSET]++;
      counter++;
      largest = bit+OFFSET;
      smallest = min(smallest, bit+OFFSET);
    }
  }

  if (counter > k){
    std::cout << "No" << std::endl;
  }
  else {

    while(counter+s[largest] <= k){
      s[largest-1] += s[largest]*2;
      counter += s[largest];
      s[largest] = 0;
      largest--;
    }

    while(counter<k){
      s[smallest]--;
      s[smallest-1]+= 2;
      smallest--;
      counter++;
    }

    printf("Yes\n%d",largest-OFFSET);
    s[largest]--;

    for (int i = 63+OFFSET; i >= 0; --i) {
      while(s[i] > 0){
        printf(" %d", i-OFFSET);
        s[i]--;
      }
    }


    printf("\n");
  }

  return 0;
}

