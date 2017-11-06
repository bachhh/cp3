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
#define LOOP(n) for (int z = 0; z < n; ++z)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  int M, N, temp1, temp2, temp3;
  int case_no = 1;
  vector<int> message_size;
  int current_buff_size;
  vector<int> q;
  vector<map<int, int>> buffer;
  vector<int> order;
  vector<int> highest_byte;
  while(cin >> N >> M && M != 0 && N != 0){
    int min_buff_size = INF;
    order.clear();
    message_size.clear();
    message_size.push_back(0);
    q.clear();
    for(int i =1; i <=N; ++i){
      cin >> temp1;
      message_size.push_back(temp1);
      order.push_back(i);
    }
    LOOP(M){
      cin >> temp1 >> temp2 >> temp3;
      q.push_back(temp1);
      q.push_back(temp2);
      q.push_back(temp3);
    }
    do {
      int max_buff_size = 0;
      current_buff_size = 0;
      highest_byte.clear();
      buffer.clear();
      LOOP(N+1){
        highest_byte.push_back(0);
        buffer.push_back(map<int, int>());
      }
      int o = 0;
      int current_message = order[o];
      for(int packet_no = 0; packet_no < M*3; packet_no+=3){
        // If packet can be passed directly
        if(q[packet_no+0] == current_message &&
          q[packet_no+1] == highest_byte[current_message]+1){
          highest_byte[current_message] = q[packet_no+2];
          //Search for next packet to pass in buffer
          while(buffer[current_message].count(highest_byte[current_message]+1) &&
            buffer[current_message][highest_byte[current_message]+1] > 0){

            current_buff_size -= (buffer[current_message][highest_byte[current_message]+1]-
                                  highest_byte[current_message]);
            // Soft delete is much simplier
            highest_byte[current_message] = buffer[current_message][highest_byte[current_message]+1];
            buffer[current_message][highest_byte[current_message]] = -1;
          }

          // If we completed a message
          while(o < N && highest_byte[current_message] == message_size[current_message]){
            // Next message
            o++;
            current_message = order[o];
            //Search for all packet can be passed in buffer
            while(buffer[current_message].count(highest_byte[current_message]+1) &&
              buffer[current_message][highest_byte[current_message]+1] > 0){
              current_buff_size -= (buffer[current_message][highest_byte[current_message]+1] -
                                    highest_byte[current_message]);

              buffer[current_message][highest_byte[current_message]] = -1;
              // Soft delete is much simplier
              highest_byte[current_message] =
                buffer[current_message][highest_byte[current_message]+1];
            }
          }
        }
        // Only buffer undirected packet
        else {
          buffer[q[packet_no]][q[packet_no+1]] = q[packet_no+2];
          current_buff_size += (q[packet_no+2] - q[packet_no+1]+1);
          max_buff_size = MAX(current_buff_size, max_buff_size);
        }
      }
      min_buff_size = MIN(max_buff_size, min_buff_size);
    }while(next_permutation(order.begin(), order.end()));
    cout << "Case " << case_no << ": "<< min_buff_size << endl << endl;
    case_no++;
  }
  return 0;
}

