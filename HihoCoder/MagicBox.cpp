#include<iostream>
#define MAXN 20001
using namespace std;
int Hash[21];
char a[MAXN];
int abs(int a)
{
	if(a>0)
		return a;
	else 
		return 0 - a;
}
bool compare(int a,int b, int c, int x,int y,int z)
{
	if(a+b+c == x+y+z)
	{
		if(a == x && (b==y||b==z)) return true;
		else if(a == y && (b == x||b==z)) return true;
		else if(a == z && (b ==x||b==y)) return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int C_r,C_y,C_b;
	int x,y,z;
	while(cin>>x>>y>>z)
	{
		int max = -1;
		int count = 0;
		C_r = 0;
		C_y = 0;
		C_b = 0;
		cin>>a;
		for(int i = 0;i<21;i++)
		{
			Hash[i] = 0;
		}
		for(int i = 0;i<strlen(a);i++)
		{
			if(a[i] == 'R') C_r++;
			else if(a[i] == 'Y') C_y++;
			else if(a[i] == 'B') C_b++;
			//Hash[abs(C_r - C_y)] = 1;
			//Hash[abs(C_r - C_b)] = 1;
			//Hash[abs(C_y - C_b)] = 1;
			count ++;
			if(max<count) max = count;
			if(compare(abs(C_r - C_y),abs(C_r - C_b),abs(C_y - C_b),x,y,z))
			{
				count = 0;
				C_r = 0;
				C_y = 0;
				C_b = 0;
			}
			//Hash[x] = 0;
			//Hash[y] = 0;
			//Hash[z] = 0;
		}
		cout<<max<<endl;
	}
	return 0;
}