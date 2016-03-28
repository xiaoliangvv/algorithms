#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

#define MAXN 100000
bool Hash[MAXN];
bool Vis[MAXN];
int Start[MAXN];
int ans[MAXN];
int ansIdx[MAXN];
vector<int> edge[MAXN];
using namespace std;
void BFS(int start)
{
	queue<int>q;
	if(Hash[start])
	{
		q.push(start);
	}
	while(!q.empty())
	{
		int tmp = q.front();
		ans[tmp] ++;
		q.pop();
		for(int i = 0;i<edge[tmp].size();i++)
		{
			if(Hash[edge[tmp][i]])
			{
				//ans[edge[tmp][i]]++;
				q.push(edge[tmp][i]);
			}
		}
	}
}
//int DFS(E start)
//{
//	stack<E>S;
//	if(Hash[start.num])
//	{
//		S.push(start);
//	}
//	while(!S.empty())
//	{
//		int tmp = S.top().num;
//		ans[tmp] ++;
//		Vis[tmp] = true;
//		S.pop();
//		for(int i = 0;i<edge[tmp].size();i++)
//		{
//			if(Hash[edge[tmp][i].num])
//			{
//				ans[edge[tmp][i].num]++ ;
//			}
//		}
//	}
//}
int main()
{
	int T,N,M,K,E,tmp;
	while(scanf("%d",&T)!=EOF)
	{
		while(T--)
		{
			for(int i = 0;i<MAXN;i++)
			{
				Hash[i] = false;
				Vis[i] = false;
				ans[i] = 0;
				edge[i].clear();
			}
			scanf("%d%d",&N,&M);
			for(int i = 0;i<M;i++)
			{
				scanf("%d",&Start[i]);
			}
			for(int i = 0 ;i<N;i++)
			{
				scanf("%d%d",&tmp,&K);
				Hash[tmp] = true;
				ansIdx[i] = tmp;
				for(int j = 0;j<K;j++)
				{
					int Etmp;
					scanf("%d",&Etmp);
					edge[tmp].push_back(Etmp);
				}
			}
			for(int i =0 ;i<M;i++)
			{
					BFS(Start[i]);
			}
			for(int i = 0;i<N;i++)
			{
					cout<<ans[ansIdx[i]]<<' ';
			}
			cout<<endl;
		}
	}
	return 0;
}