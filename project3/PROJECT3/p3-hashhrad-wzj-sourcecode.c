#include<stdio.h>
//#include<malloc.h>

typedef struct node* ptr;
struct node{
	int n_edges_in;
	int n_edges_out;
	int* nextnodes;
};

struct heaptype{
	int n_elements;
	int* element;
};

void swap(int* a,int* b){
	int k=*a;
	*a=*b;
	*b=k;
}

void heap_insert(struct heaptype* heap,int x,int* tab){//insert tab[x] into heap 
	int now,upper;

	heap->n_elements++;
	heap->element=(int*)realloc(heap->element,sizeof(int)*(heap->n_elements+1));
	heap->element[heap->n_elements]=x;
	now=heap->n_elements;
	while(1){
		if(now==1) break;
		upper=now/2;
		if(tab[heap->element[now]]<tab[heap->element[upper]]) swap(&heap->element[now],&heap->element[upper]);
		now=upper;
	}
}
int heap_delete(struct heaptype* heap,int* tab){//delete the minimum element in the heap
	int ans;
	int now=1,l,r;

	if(heap->n_elements==0) return -998998;//means the heap is empty
	else ans=heap->element[1];

	swap(&heap->element[1],&heap->element[heap->n_elements]);
	heap->n_elements--;
	while(1){
		l=2*now;r=l+1;
		if(l<heap->n_elements){//has both left and right child
			if(tab[heap->element[l]]>tab[heap->element[r]]){
				if(tab[heap->element[now]]>tab[heap->element[r]]){
					swap(&heap->element[now],&heap->element[r]);
				}
				else break;
				now=r;
			}
			else{
				if(tab[heap->element[now]]>tab[heap->element[l]]) swap(&heap->element[now],&heap->element[l]);
				else break;
				now=l;
			}
		}
		else if(l==heap->n_elements){//only has left child
			if(tab[heap->element[now]]>tab[heap->element[l]]) swap(&heap->element[now],&heap->element[l]);
			else break;
			
		}
		else{//has no child
			break;
		}
	}
	
	return ans;
}

void linknodeab_onlydealwitha(ptr* map,int a,int b){//link the node a&b which a precedes b 
	int nedges=++map[a]->n_edges_out;
	map[a]->nextnodes=(int*)realloc(map[a]->nextnodes,sizeof(int)*(nedges+1));
	map[a]->nextnodes[nedges]=b;
}


void formmap(ptr* map,int* tab,int n,struct heaptype* heap){//draw a DAG according the given sequence
	int i,j;
	int hash;
	int nodetome;
	ptr newcell;
	for(i=0;i<n;i++) {//initiate all nodes of the map
		newcell=(ptr)malloc(1*sizeof(ptr));
		newcell->n_edges_in=0;newcell->n_edges_out=0;
		newcell->nextnodes=NULL;
		map[i]=newcell;
	}

	for(i=0;i<n;i++){
		if(tab[i]<0){ 
			map[i]->n_edges_in=-998998;//don't worry, the in-degree -998998 won't change later
			continue;
		}

		hash=tab[i]%n;
		if(hash==i) {//if there is no collision
			heap_insert(heap,i,tab);
			continue;
		}
		//if there exist collision
		map[i]->n_edges_in=(i-hash+n)%n;//change the node i's in-degree in one step
		for(j=0;j<map[i]->n_edges_in;j++){
			nodetome=(hash+j)%n;
			linknodeab_onlydealwitha(map,nodetome,i);
		}
	}
}

void topsort_onlyprint(ptr* map,int n,struct heaptype* myheap,int* tab){//topological-sort the above DAG
	int deletefromheap;
	int i;
	int next;
	int isthe1stoutput=1;
	
	while(1){
		deletefromheap=heap_delete(myheap,tab);
		if(deletefromheap==-998998) break;//-998998 means the heap is empty and we have finished
		if(isthe1stoutput){//to confirm that no extra space at the end of each line
			printf("%d",tab[deletefromheap]);
			isthe1stoutput=0;
		}
		else{
			printf(" %d",tab[deletefromheap]);
		}
		for(i=1;i<=map[deletefromheap]->n_edges_out;i++){
			next=map[deletefromheap]->nextnodes[i];
			map[next]->n_edges_in--;//don't worry, we don't need to delete the edge totally.
			if(map[next]->n_edges_in==0){//don't worry, if tab[x]<0,the in-degree of node x can't be 0
				heap_insert(myheap,next,tab);
			}
		}
	}
}

int main(){
	int a=1,b=2;
	ptr* map;
	
	int n,i,j;
	int tab[1005];

	struct heaptype* myheap=(struct heaptype*)malloc(1*sizeof(struct heaptype));
	myheap->n_elements=0;myheap->element=NULL;//create a heap

	scanf("%d",&n);
	for(i=0;i<n;i++){//input the hash table
		scanf("%d",&tab[i]);
	}
	
	map=(ptr*)malloc(n*sizeof(ptr));//give the map proper memory spaces
	formmap(map,tab,n,myheap);//form the map from the hash tab and insert all nodes whose in-degrees==0
		
	topsort_onlyprint(map,n,myheap,tab);//topsort while print the answer
}
	
