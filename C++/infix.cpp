#include<iostream>
#include<stack>
using namespace std;
bool isOperator(char t)
{
  if(t=='+'|| t=='-' || t=='*' || t=='/')
  {
    return true;
  }else{
    return false;
  }
}
int main()
{
  string e="*-A+B*C/D";
  stack<string>s;
  for(int i=e.size()-1; i>=0; i--)
  {
    if (isOperator(e[i]))
    {
      string t1,t2;
      t1=s.top();
      s.pop();
      t2=s.top();
      s.pop();
      s.push("("+t1+e[i]+t2+")");
    }
     else{
      s.push(string (1,e[i]));
    }
  }
cout<<s.top();
}
