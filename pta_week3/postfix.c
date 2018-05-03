#include <stdio.h>
#include <stdlib.h>

typedef double ElementType;
#define Infinity 1e8
#define Max_Expr 30   /* max size of expression */

ElementType EvalPostfix( char *expr )
{
	int i=0,dot=0,top=0;
	double dig=1,num=0,fu=1;
	double s[100];
	
	while ((expr[i]>='0'&&expr[i]<='9') ||
	expr[i]==' ' || expr[i]=='+' || expr[i]=='-' || expr[i]=='*' || expr[i]=='.' || expr[i]=='/')
	{
		if (expr[i]>='0' && expr[i]<='9')
		{
			if (!dot)
				num=num*10+expr[i]-'0';
			else
			{
				num+=dig*0.1*(expr[i]-'0');
				dig*=0.1;
			}
		}
		if (expr[i]==' ')
		{
			num*=fu;
			s[++top]=num;
			num=0;
			dot=0;
			fu=1;
			dig=1;
		}
		if (expr[i]=='+')
		{
			if (top<2)
				return Infinity;
			num=s[top--];
			num+=s[top--];
		}
		if (expr[i]=='-')
		{
			if (expr[i+1]>='0' && expr[i+1]<='9')
			{
				fu*=-1;
			}
			else
			{
				if (top<2)
					return Infinity;
				num=s[top-1];
				num-=s[top--];
				top--;
			}
		}
		if (expr[i]=='*')
		{
			if (top<2)
				return Infinity;
			num=s[top--];
			num*=s[top--];
		}
		if (expr[i]=='/')
		{
			if (top<2)
				return Infinity;
			num=s[top-1];
			if (s[top]==0)
				return Infinity;
			num/=s[top--];
			top--;
		}
		if (expr[i]=='.')
		{
			dot=1;
		}
		i++;
	}
	
	if (top)
		return Infinity;
	else
		return num*fu;
}

int main()
{
    ElementType v;
    char expr[Max_Expr];
	freopen("n4.in","r",stdin);
	freopen("n4.out","w",stdout);
    gets(expr);
    v = EvalPostfix( expr );
	if ( v < Infinity )
        printf("%f\n", v);
    else
        printf("ERROR\n");
    return 0;
}
