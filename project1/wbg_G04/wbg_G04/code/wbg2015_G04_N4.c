/*
	O(n^4)
*/
#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,j,k,sty,y,sum,max=-32767;
	int pre[105],a[105][105];
	//freopen("n4.in","r",stdin);
   	//freopen("n4.out","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		memset(a,0,sizeof(a));
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
			{
				scanf("%d",&a[i][j]);
			}

		for (i=1;i<=n;i++)
		{
			memset(pre,0,sizeof(pre));
			for (j=i;j<=n;j++)
			{
				//calulate the sum of the kth column  from the ith row to the jth row
				for (k=1;k<=n;k++)
					pre[k]+=a[j][k];
				//the following is just like the O(n^2) algorithm of one-dimensional problem
				for (sty=1;sty<=n;sty++)
				{
					sum=0;
					for (y=sty;y<=n;y++)
					{
						sum+=pre[y];
						if (sum>max) max=sum;
					}
				}
			}
		}

		printf("%d",max);
	}
}
