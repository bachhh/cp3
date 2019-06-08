#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int64_t a, b;
  cin >> a >> b;
  vector<int64_t> adiv;
  vector<int64_t> bdiv;
  vector<int64_t> alldiv;

  for (int i = 1; i <= sqrt(a) + 1 ; i++) {
    if (a%i ==0 ){
      adiv.push_back(i);
      if (a/i != i){
        adiv.push_back(a/i);
      }
    }
  }

  for (int i = 1; i <= sqrt(b) + 1 ; i++) {
    if (b%i ==0 ){
      bdiv.push_back(i);
      if (b/i != i){
        bdiv.push_back(b/i);
      }
    }
  }

  sort(adiv.begin(), adiv.end());
  sort(bdiv.begin(), bdiv.end());

  int i = 0, j = 0;
  while(i < adiv.size() || j < bdiv.size()){
    if (adiv[i] == bdiv[j]){
      alldiv.push_back(adiv[i]);
      i++;
      j++;
    }
    else {
      if (adiv[i] < bdiv[j]){
        i++;
      }
      else{
        j++;
      }
    }
  }

  int n; cin >> n;
  int64_t low, high;

  for (int i = 0; i < n; i++) {
    cin >> low >> high;
    int l = 0, h = alldiv.size();
    auto it = upper_bound(alldiv.begin(), alldiv.end(), high);
    it = prev(it);
    if (it != alldiv.end() && *(it) >= low){
      std::cout << (*it)<< std::endl;
    }
    else {
      std::cout << -1 << std::endl;
    }
  }

  return 0;
}

