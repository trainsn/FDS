#include <stdio.h>
#include <stdlib.h>

typedef enum { true, false, maybe } Keys;
typedef Keys ElementType;

void Read( ElementType A[], int N )
{
	int i;
	for (i=0;i<N;i++)
		scanf("%d",&A[i]);
}; /* details omitted */

void MySort( ElementType A[], int N )
{
	int i,falsenum=0,maybenum=0,truenum=0;
	for (i=0;i<N;i++)
	{
		if (A[i]==false)
			falsenum++;
		else if (A[i]==maybe )
			maybenum++;
		else truenum++;
	}
	for (i=0;i<falsenum;i++)
		A[i]=false;
	for (i=falsenum;i<falsenum+maybenum;i++)
		A[i]=maybe;
	for (i=falsenum+maybenum;i<N;i++)
		A[i]=true;		
}

void PrintA( ElementType A[], int N )
{
    int i, k;

    k = i = 0;
    for ( ; i<N && A[i]==false; i++ );
    if ( i > k )
        printf("false in A[%d]-A[%d]\n", k, i-1);
    k = i;
    for ( ; i<N && A[i]==maybe; i++ );
    if ( i > k )
        printf("maybe in A[%d]-A[%d]\n", k, i-1);
    k = i;
    for ( ; i<N && A[i]==true; i++ );
    if ( i > k )
        printf("true in A[%d]-A[%d]\n", k, i-1);
    if ( i < N )
        printf("Wrong Answer\n");
}

int main()
{
    int N;
    ElementType *A;
	
	freopen("n4.in","r",stdin);
	freopen("n4.out","w",stdout);
    scanf("%d", &N);
    A = (ElementType *)malloc(N * sizeof(ElementType));
    Read( A, N );
    MySort( A, N );
    PrintA( A, N );
    return 0;
}
