#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
class Solution{
public:
	stack<int>p;
	int stringToInt(string a)
	{
		int ans = 0;
		bool flag = true;
		if(a.empty())
		{
			return 0;
		}
		if(a[0] == '-')
		{
			flag = false;
		}
		else
		{
			ans = a[0] - '0';
		}
		for(int i=1;i<a.size();i++)
		{
			ans =  ans * 10 + a[i] - '0';
		}
		//printf("%d\n",ans);
		if(!flag)
			return 0-ans;
		else
			return ans;
	}
	int evalRPN(vector<string> &token){
		for(int i=0;i<token.size();i++){
			if(token[i] =="+")
			{
				int a,b; 
				a = p.top();
				p.pop();
				b = p.top();
				p.pop();
				p.push(a+b);
			}
			else if(token[i] =="-")
			{
				int a,b; 
				a = p.top();
				p.pop();
				b = p.top();
				p.pop();
				p.push(b-a);
			}
			else if(token[i] =="*")
			{
				int a,b; 
				a = p.top();
				p.pop();
				b = p.top();
				p.pop();
				p.push(a*b);
			}
			else if(token[i] =="/")
			{
				int a,b; 
				a = p.top();
				p.pop();
				b = p.top();
				p.pop();
				p.push(b/a);
			}
			else
			{
				p.push(stringToInt(token[i]));
			}
		}
		return p.top();
	}

};
int main()
{
	char * words[] = {"4", "13", "5", "/", "+"};
	Solution sol;
	vector<string> token(words,words + sizeof(words)/sizeof(char *));
	cout<<sol.evalRPN(token)<<endl;
	return 0;
}