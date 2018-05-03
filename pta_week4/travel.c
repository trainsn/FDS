#include <stdio.h>
#include <stdlib.h>

#define MaxTree 10 /* maximum number of nodes in a tree */
typedef int ElementType;

typedef struct TreeNode *Tree;
struct TreeNode {
    ElementType Element;
    Tree  Left;
    Tree  Right;
};

Tree BuildTree()
{
	return NULL;
}/* details omitted */
void PrintNode( Tree NodePtr )
{
   printf(" %d", NodePtr->Element);
}

void Level_order ( Tree T, void (*visit)(Tree ThisNode) )
{
	Tree queue[100];
	int st=0,en=1;
	if (T==NULL)
		return;
	queue[en]=T;
	while (st<en)
	{
		if (queue[st]!=NULL)
		{
			st++;
			T=queue[st];
			printf(" %d", T->Element);			
		}			
		if (T->Left!=NULL)
			queue[++en]=T->Left;
		if (T->Right!=NULL)
			queue[++en]=T->Right;
	}
}

int main()
{
   
   freopen("n4.in","r",stdin);
   freopen("n4.out","w",stdout);
   Tree T = BuildTree();
    printf("Level-order:");
    Level_order(T, PrintNode);
    return 0;
}
