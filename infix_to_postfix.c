#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 100
char stack[SIZE];
int top=-1;
void push(char);
char pop();
int prio(char);

int prio(char op)
{
  if(op=='+'||op=='-')
  return 1;
  if(op=='*'||op=='/'||op=='%')
  return 2;
  if(op=='(')
  return 0;
	else
	printf("wrong operator");
	
	
}
 
void push(char e)
{
	    if(top==SIZE- 1) 
            printf("\nStack Overflow … "); 
       else 
        stack[++top]=e;
        
}
char pop()
{
	    if(top==- 1) 
            printf("\nStack Underflow … "); 
       else 
       return stack[top--];	
}
void main()
{
char in[50],pn[50];
int i,j=0;
printf("enter infix notation\n");
scanf("%s",in);
for(i=0;in[i]!='\0';i++)
{
	if(in[i]=='(')
	push(in[i]);
	else if((in[i]>='a'&&in[i]<='z')||(in[i]>='0'&&in[i]<='9'))
	pn[j++]=in[i];
	else if(in[i]==')')
	{
		while(stack[top]!='(')
		{
			pn[j++]=pop();

		}
	pop();
	}
	else
	{
		while(top>-1&&(prio(stack[top])>=prio(in[i])))
		pn[j++]=pop();
		push(in[i]);
	}
	}
	while(top>-1){
		pn[j++]=pop();
	}
	pn[j]='\0';
	printf("Equivalent postfix expression = %s",pn);	
}


