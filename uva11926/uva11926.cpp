#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
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



int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdin);
  int n, m;
  cin >> n >> m;
  while( n!= 0 || m != 0){

    bool flag = false;
    bitset<1000000> bitmap;

    queue<int> n_queue;
    queue<int> m_queue;

    while(n--){
      int from, to;
      cin >> from >> to;
      n_queue.push(from);
      n_queue.push(to);
    }

    while(m--){
      int from, to, interval;
      cin >> from >> to >> interval;
      m_queue.push(from);
      m_queue.push(to);
      m_queue.push(interval);
    }
      
    while( !n_queue.empty() && !flag){
      int from = n_queue.front();
      n_queue.pop();
      int to = n_queue.front();
      n_queue.pop();

      for (int i = from; i < to && !flag; i++){
        // if bit not set then flip it
        if( !bitmap.test(i) ) bitmap.set(i);
        else flag = true;
      } 
    }

    while (!m_queue.empty() && !flag){

      int from = m_queue.front(); 
      m_queue.pop();
      int to = m_queue.front(); 
      m_queue.pop();
      int interval = m_queue.front(); 
      m_queue.pop();

      int rep = 0;
      int t_from = from+interval*rep;
      int t_to = to+interval*rep;

      while ( t_from < 1000000 && !flag ){
        for (int i = t_from; i < t_to && !flag;  i++){
          if ( !bitmap.test(i) ) bitmap.set(i); 
          else flag = true;
        }

        rep++;
        t_from = from+interval*rep;
        t_to = MIN(to+interval*rep, 1000000);
      } 
    }

    if (!flag) cout << "NO CONFLICT" << endl;
    else cout << "CONFLICT" << endl;
    cin >> n >> m;
  }
   
}

