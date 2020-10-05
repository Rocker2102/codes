/*
Power Set
abc
 a
 ab
 abc
 ac
 b
 bc
 c
*/

#include<bits/stdc++.h>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
void solve(string ip,string op,std::vector<string> &v)
{
  if(ip.length()==0)
  {
    v.push_back(op);
    return;
  }
  string op1,op2;
  op1=op;
  op2=op;
  op2.push_back(ip[0]);
  ip.erase(ip.begin()+0);
  solve(ip,op1,v);
  solve(ip,op2,v);
  return;
}
int main()
{
  std::vector<string> v;
  std::set<string>s;

  string ip,op=" ";
  cin>>ip;
  sort(ip.begin(),ip.end());
  solve(ip,op,v);
  for(auto x:v)
  {
    s.insert(x);
  }
  for(auto it=s.begin();it!=s.end();it++)
  {
    if(*it!=" ")
    {
        cout<<*it<<endl;
    }

  }
}
