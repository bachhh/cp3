#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
int main()
{
  char q[5055];
  int sol = 0;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>q+1;
  int n=strlen(q+1);
  for(int i=1;i<n;++i)
  {
      int l=0,r=0;
      for(int j=i;j<=n;++j)
      {
          if(q[j]=='(')
              ++l,++r;
          if(q[j]==')')
              --l,--r;
          if(q[j]=='?')
              --l,++r;
          if(l<0)
              l+=2;
          if(r<0)
              break;
          if(l==0)
              ++sol;
      }
  }
  cout<<sol;
  return 0;
}
