#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<string>	
using namespace std;

int pre(char op)
{
	if(op=='^')
		return 3;
	else if(op=='/' or op == '*' or op=='%')
		return 2;
	else if(op == '+' or op == '-')
		return 1;
	return 0;

}

string infix_postfix_converter(string &infix)
{
	stack<char> op; //stack to store operator
	string postfix; int check = 0; 
	//cout<<infix.length()<<endl;
	for(int i=0;i<infix.length();i++)
	{	
		
		if((infix[i]>= '0' and infix[i]<='9') or infix[i]==' ')
			{ postfix += infix[i]; continue;}
		if(infix[i]== '(')
			{ op.push('(');continue;}
		if(pre(infix[i])>0)
		{ if(infix[i-1]!=' ' and infix[i+1]!=' ')
			postfix += ' ';
		/*if(infix[i]=='/')
			{while((!op.empty())&& op.top()=='/')
				{postfix += '/';op.pop();}
				op.push('/');
			}
		else if(infix[i]=='*')
			{
				while((!op.empty())&&(op.top()=='/'||op.top()=='*'))
				{postfix += op.top();op.pop();}
			op.push('*');
			}
		else if(infix[i]=='+')
			{
				while((!op.empty())&&(op.top()=='/'||op.top()=='*'||op.top()=='+'))
				{postfix += op.top();op.pop();}
			op.push('+');
			}
		else if(infix[i]=='-')
			{
				while((!op.empty())&&(op.top()=='/'||op.top()=='*'||op.top()=='+'||op.top()=='-'))
				{postfix += op.top();op.pop();}
			op.push('-');
			}*/
		while((!op.empty()) and (pre(op.top()) >= pre(infix[i])))
			{postfix += op.top(); op.pop();}
		op.push(infix[i]);
		}
		if(infix[i]==')')
			{while(op.top()!='(')
				{postfix += op.top();op.pop();}
			op.pop();
			}
		
	}
	while(!op.empty())
		{postfix += op.top();op.pop();}
	//cout<<postfix<<endl;
	return postfix;
}
int main()
{	ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	freopen("infix","r",stdin);
	freopen("postfix","w",stdout);
	string infix;
	getline(cin,infix);//cout<<infix.length()<<endl;
	string postfix = infix_postfix_converter(infix);
	cout<<postfix<<"\n";
	return 0;
}