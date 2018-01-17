#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

int frequency(string w, string e){
  int counter = 0;
  int index = 0;
  int previ = 0;
  while(index != e.size()){
  }

  return counter;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int k, e;

  int tn = 1;
  while(cin >> k >> e){
    getchar();

    string temp;
    vector<string> keywordsV;

    for (int i = 0; i < k; i++) {
      getline(cin, temp);
      keywordsV.push_back(temp);
    }

    vector<string> v;
    int worstMetric = 0;

    for (int i = 0; i < e; i++) {
      getline(cin, temp);
      int lameMetric = 0;
      for (string s : keywordsV) {
        lameMetric += frequency(s, temp);
      }
      if(lameMetric > worstMetric){
        worstMetric = lameMetric;
        v.clear();
        v.push_back(temp);
      }
      else if(lameMetric == worstMetric){
        v.push_back(temp);
      }
    }

    std::cout << "Excuse Set #" << tn << " " << std::endl;
    for (string s : v) {
      std::cout << s << std::endl;
    }
    std::cout << std::endl;

    tn++;
  }

  return 0;
}

