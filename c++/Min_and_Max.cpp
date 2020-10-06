/*
Find the minimum and maximun number in an array
2
5
1 2 7 3 5
1 7
5
0 0 0 0 0
0 0
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //write your code here
  int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int x[n];
		for(int i=0;i<n;i++)
		{
			cin>>x[i];
		}
		int a=x[0],b=x[0];
		for(int i=0;i<n;i++)
		{
			if(x[i]<a)
			{
				a=x[i];
			}
			if(x[i]>b)
			{
				b=x[i];
			}
		}
		cout<<a<<" "<<b<<"\n";
	}

  return 0;
}
