#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;
struct stack
{char data;
 struct stack *link;
}*ptr,*top=NULL,*temp;
int priority(char t)
{ if(t=='^')
   return 3;
  if(t=='*'||t=='/')
   return 2;
  if(t=='+'||t=='-')
   return 1;
  if(t=='(')
   return 0;
  if(t=='#')
   return -1;   
}
void push(char y)
{temp=new stack;
 temp->data=y;
 temp->link=top;
 top=temp;
}
char pop()
{char z;
 if(top==NULL)
  return '\0';
 temp=top;
 z=top->data;
 top=top->link;
 delete(temp);
 return z;
}
void disp()
{temp=top;
 while(temp!=NULL)
 {cout<<temp->data;
  temp=temp->link;
 }
 cout<<endl;
}
int main()
{int i=0,j,k=0,n;
char x,infix[100],postfix[100];
cout<<"enter the infix expression\n";
gets(infix);
push('#');
for(k=0;infix[k]!='\0';k++)
 {if(infix[k]=='(')
   push('(');
  else if(isalpha(infix[k])||isdigit(infix[k]))
    postfix[i++]=infix[k];
   else if(infix[k]=='+'||infix[k]=='-'||infix[k]=='/'||infix[k]=='*'||infix[k]=='^')
    {
     if(priority(infix[k])>priority(top->data))
          push(infix[k]);
        else
          {while(priority(infix[k])<=priority(top->data))
             postfix[i++]=pop();
            push(infix[k]);
          }
    }
  else if(infix[k]==')'||infix[k+1]=='\0')
   {x=pop();
    while(x!='(' && x!='#')
     {postfix[i++]=x;
      x=pop();
     }
   }
}
x=pop();
while(top!=NULL && x!='#')
{postfix[i++]=x;
 x=pop();
}
postfix[i]='\0';
cout<<"the postfix expression is\n";
puts(postfix);
for(i=0;postfix[i]!='\0';i++)
{if(isalpha(postfix[i]))
 {cout<<"enter the value of "<<postfix[i]<<" ";
  cin>>n;
  push(n);
 }
 else if(postfix[i]!='#')
   {int p,q;
    p=pop();
    q=pop();
    if(postfix[i]=='+')
    push(p+q);
    if(postfix[i]=='*')
    push(p*q);
    if(postfix[i]=='/')
     push(q/p);
    if(postfix[i]=='-')
    push(q-p);
    if(postfix[i]=='^')
    push(pow(p,q));
   }
 }
 cout<<"the result is \n";
 k=pop();
 cout<<k;
}

                     
