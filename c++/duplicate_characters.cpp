/*
3
python
-1
java
a=2
Leet
e=2


*/

#include <bits/stdc++.h>
using namespace std;
const int MAX=26;
void count(string &str)
{
  int cc[MAX]={0},c=0;
  for(int i=0;i<str.length();i++)
  {
    cc[str[i]-'a']++;
  }
  for(int i=0;i<MAX;i++)
  {
    for(int j=0;j<cc[i];j++)
    {
      if(cc[i]>1)
      {
        cout<<(char)(i+'a')<<"="<<cc[i]<<" ";
        c++;
        break;
      }
    }
  }
  if(c==0)
  {
    cout<<"-1";
  }
  cout<<endl;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string s="";
    cin>>s;
    count(s);

  }

  return 0;
}
