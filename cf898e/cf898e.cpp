#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;

  vector<int64_t> square;
  for (int i = 0; i*i <= 1e9+1e8; i++) {
    square.push_back(i*i);
  }

  vector<int64_t> sq;
  vector<int64_t> notsq;

  for (int i = 0; i < n; i++) {
    int64_t a;
    cin >> a;

    auto it = upper_bound(square.begin(), square.end(), a);
    int64_t upper = (it != square.end() ) ? (*it) : INT64_MIN;
    int64_t lower = *(prev(upper_bound( square.begin(), square.end(), a)));
    int64_t diff = min<int64_t>(abs<int64_t>(a-upper), a-lower);
    //std::cout << a << " | " << lower<< std::endl;

    if (diff){
      notsq.push_back(diff);
    }
    else {
      if (a== 0) sq.push_back(2);
      else sq.push_back(1);
    }
  }


  sort(notsq.begin(), notsq.end());
  sort(sq.begin(), sq.end());

  int64_t sum = 0;
  if (sq.size() > notsq.size()){
    for (int i = 0; i < (sq.size() - notsq.size())/2; i++) {
      sum += sq[i];
    }
  }
  else{
    for (int i = 0; i < (notsq.size() - sq.size())/2; i++) {
      sum += notsq[i];
    }
  }
  std::cout << sum << std::endl;

  return 0;
}

