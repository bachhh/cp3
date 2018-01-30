#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";

string s1 = "What are you doing while sending \"";
string s2 = "\"? Are you busy? Will you send \"";
string s3 = "\"?";

int64_t n, k;


vector<int64_t> flen(60);

char solve(int64_t index, int dep){

  int64_t sec1 = s1.size();
  int64_t sec2 = sec1 + flen[dep-1];
  int64_t sec3 = sec2 + s2.size();
  int64_t sec4 = sec3 + flen[dep-1];
  int64_t sec5 = sec4 + s3.size();

  if (dep == 0){
    return f0[index-1];
  }
  if (index <= sec1){
    return s1[index-1];
  }
  else if (index > sec1  && index <= sec2) {
    return solve(index-sec1, dep-1);
  }
  else if (index > sec2 && index <= sec3){
    return s2[index - sec2 -1];
  }
  else if (index > sec3 && index <= sec4){
    return solve(index - sec3, dep-1);
  }
  else if (index > sec4 && index <= sec5){
    return s3[index-sec4-1];
  }
  else {
    cerr << "!!!!!" << endl;
  }

}


//  ***** MAIN *****
int main(){

  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int q; cin >> q;

  int totallen = s1.size() + s2.size()+ s3.size();
  flen[0] = f0.size();

  for (int i = 1; i < 56; ++i) {
    flen[i] = totallen + 2*flen[i-1];
  }

  for (int i = 0; i < q; i++) {
    cin >> n >> k;
    if (n < 60 &&  k > flen[n]){
      cout << '.';
      continue;
    }

    if (n > 55){
      if (k <= (n-55)*s1.size()){
        return s1[(k-1)%s1.size()];
      }
      else {
        k -= (n-55)*s1.size();
        n = 55;
      }
    }
    char c = solve(k, n);
    std::cout << c;
  }

  std::cout << std::endl;

  return 0;
}

