/*Author: 施能; ID:3140100193; No.01*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,i,num=0,flag,j,st;
	int a[100005],b[100005];

	/*freopen("n4.in","r",stdin);
	freopen("n4.out","w",stdout);*/

	scanf("%d",&n);
	//b[i] is used to store whether the number in position i should be swapped
	for (i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]!=i)
			b[i]=1;
		else
			b[i]=0;
	}
	//the case whether the position of 0 need to be swapped will influence the final result
	if (a[0]) 
		num=-2;
	
	//then in the following code,I simulate the process of swapping elements and get the answer
	while (1)
	{
		flag=1;
		for (i=0;i<n;i++)
		{
			if (b[i])
			{
				flag=0;
				st=i;
				b[i]=0;
				j=a[i];
				num+=2;
				while (j!=st)
				{
					b[j]=0;
					j=a[j];
					num++;
				}
			}
		}
		if (flag)
			break;
	}
	printf("%d",num);
	return 0;
}
