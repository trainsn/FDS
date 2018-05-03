#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TreeNode *Tree;
struct TreeNode {
    ElementType Element;
    Tree  Left;
    Tree  Right;
};/*Tree is defined as this */

Tree  Insert( ElementType X, Tree T );
int isequal( Tree T1, Tree T2 );

int main()
{	
	int i,j,N,L;
	ElementType x;
	Tree T0=NULL,T;
	
	freopen("p2.in","r",stdin);
	freopen("p2.out","w",stdout);
	
	while(1){     
		scanf("%d",&N);
		if(!N)
			return 0;
		scanf("%d",&L);/*input N and L*/
		T0=NULL;
		for(i=1;i<=N;i++){
			scanf("%d",&x);
			T0=Insert(x,T0);/*The initially inserted numbers*/
		}
		for(i=1;i<=L;i++){
			T=NULL;
			for(j=1;j<=N;j++){
				scanf("%d",&x);
				T=Insert(x,T);
			}/* N integers to be checked.*/
				if(isequal(T,T0))
	  				printf("Yes\n");/*If these two trees are equal,then print "Yes"*/
		  		else
		  			printf("No\n");/*If these two trees are not equal,then print "No"*/
		}
	}
}

Tree  Insert( ElementType X, Tree T )
{

    if (T==NULL) /* Create and return a one-node tree */
	{
		T = malloc( sizeof( struct TreeNode ) );
		if ( T == NULL )
		   return;
		else {
		   T->Element = X;
		   T->Left = T->Right = NULL; }
    }  /* End creating a one-node tree */
    else if ( X < T->Element ) /* If there is a tree */
		 T->Left = Insert( X, T->Left );
	else if ( X > T->Element )
		 T->Right = Insert( X, T->Right ); /*All the N numbers are distinct and no greater than N. */
	return  T;
}

int isequal(Tree T1, Tree T2 ) /*The function that shows two trees are equal or not*.If they're same,then return 1,else return 0.*/
{
	if(T1==NULL&&T2==NULL)/*If they're both NULL*/
		return 1;
	if(T1==NULL||T2==NULL)/*If only one of them are NULL*/
		return 0;
	if(T1->Element!=T2->Element)/*If they are both not NULL*/
		return 0;
	return isequal(T1->Left,T2->Left)*isequal(T1->Right,T2->Right);
}
