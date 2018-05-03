#include <stdio.h>
#include <stdlib.h>
#define ERROR 32000
typedef int ElementType;
typedef enum { push, pop, end } Operation;

typedef struct StackRecord *Stack;
struct StackRecord  {
    int Capacity;       /* maximum size of the stack array */
    int Top1;           /* top pointer for Stack 1 */
    int Top2;           /* top pointer for Stack 2 */
    ElementType *Array; /* space for the two stacks */
};

Stack CreateStack( int MaxElements )
{
	Stack s;
	s=malloc(sizeof(struct StackRecord));
	s->Array=malloc(sizeof(int)*MaxElements);
	s->Top1=-1;
	s->Top2=MaxElements;
	s->Capacity=MaxElements;
	return s;
}
int IsEmpty( Stack S, int Stacknum )
{
	if (Stacknum==1)
	{
		if (S->Top1==-1)
			return ERROR;
	}
	else
		if (S->Top2==S->Capacity)
			return ERROR;
	return 0;
}
int IsFull( Stack S )
{
	return S->Top1+1==S->Top2;
}
int Push( ElementType X, Stack S, int Stacknum )
{
	if (IsFull(S))
		return 0;
	if (Stacknum==1)
	{
		S->Array[++S->Top1]=X;
	}
	else
	{
		S->Array[--S->Top2]=X;
	}
	return 1;
}
ElementType Top_Pop( Stack S, int Stacknum )
{
	if (IsEmpty(S,Stacknum))
		return ERROR;
	if (Stacknum==1)
		return S->Array[S->Top1--];
	else
		return S->Array[S->Top2++];
}

void PrintStack( Stack S, int Stacknum )
{
	printf("%d ",Stacknum);
	while (!IsEmpty(S,Stacknum))
	{
		printf("%d ",Top_Pop(S,Stacknum));
	}
	printf("\n");
} /* details omitted */

int main()
{
    int N, Sn, X;
    Stack S;
	int done = 0,type;

    freopen("n4.in","r",stdin);
	freopen("n4.out","w",stdout);

	scanf("%d", &N);
    S = CreateStack(N);
    while ( !done ) {
		scanf("%d",&type);
        switch( type ) {
        case 1:
            scanf("%d %d", &Sn, &X);
            if (!Push(X, S, Sn))
				printf("Stack %d is Full!\n", Sn);
            break;
        case 2:
            scanf("%d", &Sn);
            X = Top_Pop(S, Sn);
			if ( X==ERROR )
				printf("Stack %d is Empty!\n", Sn);
            break;
        case 3:
            PrintStack(S, 1);
            PrintStack(S, 2);
            done = 1;
            break;
        }
    }
    return 0;
}
