#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define ERROR 30000
typedef enum { push, pop, inject, eject, end } Operation;

typedef struct Node *PtrToNode;
struct Node {
    ElementType Element;
    PtrToNode Next, Last;
};
typedef struct DequeRecord *Deque;
struct DequeRecord {
    PtrToNode Front, Rear;
};
Deque CreateDeque()
{
	Deque D;
	D=malloc(sizeof(struct DequeRecord));
	D->Front=D->Rear=malloc(sizeof(struct Node));
	return D;
}

int Push( ElementType X, Deque D )
{
	PtrToNode newnode;
	newnode=malloc(sizeof(struct Node));
	if (newnode==NULL)
		return 0;
	newnode->Element=X;
	newnode->Next=D->Front->Next;
	newnode->Last=D->Front;

	if (D->Front==D->Rear)
		D->Rear=newnode;
	else
		D->Front->Next->Last=newnode;
	D->Front->Next=newnode;
	return 1;
}
ElementType Pop( Deque D )
{
	PtrToNode temp;
	if (D->Front==D->Rear)
		return ERROR;
	else
	{
		temp=D->Front->Next;
		D->Front->Next=temp->Next;
		if (temp!=D->Rear) 
           temp->Next->Last=D->Front;
		if (temp==D->Rear)
		{
			D->Rear=D->Front;
		}
		free(temp);
		return temp->Element;
	}

}

int Inject( ElementType X, Deque D )
{
	PtrToNode newnode;
	newnode=malloc(sizeof(struct Node));
	if (newnode==NULL)
		return 0;

	newnode->Element=X;
	newnode->Next=NULL;
	newnode->Last=D->Rear;

	D->Rear->Next=newnode;
	D->Rear=newnode;
	return 1;

}
ElementType Eject( Deque D )
{
	PtrToNode temp;
	if (D->Front==D->Rear)
		return ERROR;
	else
	{
		temp=D->Rear;
		D->Rear=temp->Last;
		temp->Next=NULL;
		free(temp);
		return temp->Element;
	}
}

int GetOp()
{
	int op;
	scanf("%d",&op);
	return op;
}
         /* details omitted */
void PrintDeque( Deque D )
{
	PtrToNode node=D->Front->Next;
	while (node!=D->Rear)
	{
		printf("%d ",node->Element);
		node=node->Next;
	}
	printf("%d\n",node->Element);

} /* details omitted */

int main()
{
    ElementType X;
    Deque D;
    int done = 0;

    freopen("n4.in","r",stdin);
	freopen("n4.out","w",stdout);
	D = CreateDeque();
    while (!done) {
        switch(GetOp()) {
        case 1:
            scanf("%d", &X);
            if (!Push(X, D)) printf("Memory is Full!\n");
            break;
        case 2:
            X = Pop(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case 3:
            scanf("%d", &X);
            if (!Inject(X, D)) printf("Memory is Full!\n");
            break;
        case 4:
            X = Eject(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case 5:
            PrintDeque(D);
            done = 1;
            break;
        }
    }
    return 0;
}
