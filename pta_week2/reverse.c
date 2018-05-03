#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node {
    ElementType Element;
    Position Next;
};

List Read()
{
	int n,i;
	List p,head,tail;
	head=tail=(PtrToNode)malloc(sizeof(struct Node));
	scanf("%d",&n);i                  bhiobbbo 
	for (i=0;i<n;i++)
	{
		p=(PtrToNode)malloc(sizeof(struct Node));
		scanf("%d",&p->Element);
		p->Next=NULL;
		tail->Next=p;
		tail=p;
	}
	return head;
} /* details omitted */
void Print( List L )
{
	while (L->Next!=NULL)
	{
		L=L->Next;
		printf("%d ",L->Element);
	}
} /* details omitted */
List Reverse( List L )
{
	List old,new,temp;
	old=L->Next;
	new=NULL;
	temp=NULL;
	while (old)
	{
		temp=old->Next;
		old->Next=new;
		new=old;
		old=temp;
	}
	L->Next=new;
	return L;
}

int main()
{
    List L1, L2;
	freopen("n4.in","r",stdin);
	freopen("n4.out","w",stdout);
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

