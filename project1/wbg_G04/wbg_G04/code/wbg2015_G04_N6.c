/*
	O(n^6)
*/
#include<stdio.h>
#include<string.h>
int main()
{
	int stx,sty,enx,eny,i,j,n,sum,max=-32767;
	int a[105][105];
	freopen("n4.in","r",stdin);
	freopen("n4.out","w",stdout);

	while (scanf("%d",&n)!=EOF)
	{
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
				scanf("%d",&a[i][j]);
	//serach all the matrix
		//(stx,sty) is the starting point
		for (stx=1;stx<=n;stx++)
			for (sty=1;sty<=n;sty++)
				//(enx,eny) is the end point
				for (enx=stx;enx<=n;enx++)
					for (eny=sty;eny<=n;eny++)
					{
						//sum represents the sum of the current matrix 
						sum=0;
						for (i=stx;i<=enx;i++)
							for (j=sty;j<=eny;j++)
							{
								sum+=a[i][j];								
							}
						if (sum>max) max=sum;
					}
       printf("%d",max);
	}
}
