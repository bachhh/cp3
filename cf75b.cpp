#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
    //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string temp, myname;
  map<string, int> factor;
  getline(cin, temp);
  myname = temp;

  getline(cin, temp);
  int n = stoi(temp);
  for (int i = 0; i < n; i++) {
    getline(cin, temp);
    string firstname, action, secondname;
    int index = temp.find(' ');

    firstname = temp.substr(0,index);

    action = temp.substr(index+1, temp.find(' ',index+1)-index-1);

    index = temp.find(' ',index+1);
    if (action == "likes"){
      secondname = temp.substr(index+1, temp.find('\'', index+1)- index - 1);
      if (firstname == myname) factor[secondname] += 5;
      else {
        factor[firstname] += 0;
        factor[secondname] += 0;
      }
    }
    else {
      index = temp.find(' ',index+1);
      secondname = temp.substr(index+1, temp.find('\'', index+1) - index-1);
      if (action == "posted"){
        if (firstname == myname) factor[secondname] += 15;
        else {
          factor[firstname] += 0;
          factor[secondname] += 0;
        }
      }
      else if(action == "commented"){
        if (firstname == myname) factor[secondname] += 10;
        else {
          factor[firstname] += 0;
          factor[secondname] += 0;
        }
      }
    }
  }

  vector<pair<int, string>> v;
  for (auto p : factor) {
    if (p.first != myname){
      v.push_back(pair<int, string>(p.second, p.first));
    }
  }

  sort(v.begin(), v.end(), []( pair<int, string> a, pair<int, string> b){
                              if (a.first != b.first){
                                return a.first > b.first;
                              }
                              else {
                                return a.second.compare(b.second) < 0;
                              }
                              });

  for (int i = 0; i < v.size(); i++) {
    std::cout << v[i].second << std::endl;
  }
  return 0;
}

