#include<stdio.h>
#define MAX 1000

void InsertionSort(int A[],int N)     //use insertionsort algorithm to sort the numbers in the array
{
	int i,j;
	int tmp;
	for(j=1;j<N;j++){
		tmp=A[j];
		for(i=j;i>0&&A[i-1]>tmp;i--)    //find the correct position to store the number tmp
			A[i]=A[i-1];               //change the position
		A[i]=tmp;
	}
}

int FindPos(int X,int c[],int N)      //calculate hash value when insert the number to the c array
{
	int pos;
	if(X==-1) return -1;              //when the input number is equal to -1, then we return -1 as flag
	pos=X%N;
	while(c[pos]>=0)                 //use linear probing to solve the collision
		if(++pos==N)                 //when pos meets the end,then back to 0
			pos=0;
	return pos;
}

int main()
{
	int a[MAX];                   //this array is used to store the input numbers 
	int b[MAX];                   //this array is used to store the valid numbers which is sorted
	int c[MAX];                   //this array is used as an assumed hash table
	int number;
	int N;
	int i;
	int pos;
	int flag=0;                   //this flag is used at output to control the output of blank
	scanf("%d",&N);
	for(i=0;i<N;i++){             //receive the data
		scanf("%d",&a[i]);
		b[i]=c[i]=-1;             //initialize b and c array by -1
	}
	for(i=0,number=0;i<N;i++)     //select the valid numbers in a array and store in b array
		if(a[i]>=0)
			b[number++]=a[i];     //variable number is used to store the number of data
	InsertionSort(b,number);
	while(1){
		for(i=0;i<number;i++){
			pos=FindPos(b[i],c,N);
			if(pos==-1) continue;
			if(a[pos]==b[i]){                  //if b[i] is in the correct position,
				if(flag==0){                   //then output the b[i]  
					printf("%d",b[i]);
					flag=1;
				}
				else
					printf(" %d",b[i]);
				c[pos]=b[i];                   //then store the b[i] in the correct position in c array
				b[i]=-1;                       //then remove the b[i] by clearing the b[i] to -1 
				break;
			}
		}               //when a correct data is outputed, then continually calcualte the whole b array to find the next correct data
	if(i==number) break;           //if the whole data is outputed, then break
	}
	return 0;
}
