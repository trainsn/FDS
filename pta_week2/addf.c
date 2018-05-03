#include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
struct Node  {
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};
typedef PtrToNode Polynomial;

Polynomial Read()
{
	int n,i;
	Polynomial p,head,tail;
	head=tail=(PtrToNode)malloc(sizeof(struct Node));
	scanf("%d",&n);

	for (i=0;i<n;i++)
	{			
		p=(PtrToNode)malloc(sizeof(struct Node));
		scanf("%d%d",&p->Coefficient,&p->Exponent);
		p->Next=NULL;
		tail->Next=p;
		tail=p;
	}
	return head;
	
} /* details omitted */
void Print( Polynomial p )
{
	while (p->Next!=NULL)
	{
		p=p->Next;
		printf("%d %d ",p->Coefficient,p->Exponent);
	}		
}/* details omitted */
Polynomial Add( Polynomial a, Polynomial b )
{
	Polynomial head,tail,p;
	head=tail=(PtrToNode)malloc(sizeof(struct Node));
	a=a->Next;
	b=b->Next;
	while (a!=NULL && b!=NULL)
	{
		if (a->Exponent<b->Exponent)
		{
			p=(PtrToNode)malloc(sizeof(struct Node));
			p->Coefficient=b->Coefficient;
			p->Exponent=b->Exponent;
			p->Next=NULL;
			tail->Next=p;
			tail=p;
			b=b->Next;
		}
		if (a->Exponent>b->Exponent)
		{
			p=(PtrToNode)malloc(sizeof(struct Node));
			p->Coefficient=a->Coefficient;
			p->Exponent=a->Exponent;
			p->Next=NULL;
			tail->Next=p;
			tail=p;
			a=a->Next;
		}
		if (a->Exponent==b->Exponent)
		{
			p=(PtrToNode)malloc(sizeof(struct Node));
			if (a->Coefficient+b->Coefficient!=0)
			{
				p->Coefficient=a->Coefficient+b->Coefficient;
				p->Exponent=b->Exponent;
				p->Next=NULL;
				tail->Next=p;
				tail=p;
			}
			a=a->Next;
			b=b->Next;
		}
	}
	while (a!=NULL)
	{
		p=(PtrToNode)malloc(sizeof(struct Node));
		p->Coefficient=a->Coefficient;
		p->Exponent=a->Exponent;
		p->Next=NULL;
		tail->Next=p;
		tail=p;
		a=a->Next;
	}
	while (b!=NULL)
	{
		p=(PtrToNode)malloc(sizeof(struct Node));
		p->Coefficient=b->Coefficient;
		p->Exponent=b->Exponent;
		p->Next=NULL;
		tail->Next=p;
		tail=p;
		b=b->Next;
	}
	return head;
}

int main()
{
	Polynomial a, b, s;
	freopen("n4.in","r",stdin);
	freopen("n4.out","w",stdout);
    a = Read();
    b = Read();
    s = Add(a, b);
    Print(s);
    return 0;
}
