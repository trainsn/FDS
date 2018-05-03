/*
	O(n^4)
*/

#include <time.h> 
clock_t  start, stop; 
/* clock_t is a built-in type for processor time (ticks) */ 
double  duration;  
/* records the run time (seconds) of a function */  

#include<stdio.h>
#include<string.h>

//#include <stdlib.h>

int main()
{
	char finname[10];char foutname[20];
	int nown=5;
	int testtimes=0,testi=0;
	int n,i,j,k,sty,y;
	int sum,max=0;//-2147483648~2147483647
	int pre[105],a[105][105];

	while(1){
	testtimes=1600000/((nown/5)*(nown/5)*(nown/5)*(nown/5));
	sprintf(finname,"nis%d.in",nown);
	sprintf(foutname,"n4-nis%d.out",nown);
	freopen(finname,"r",stdin);
   	freopen(foutname,"w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		memset(a,0,sizeof(a));
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
			{
				scanf("%d",&a[i][j]);
			}

		start = clock(); 
		for(testi=1;testi<=testtimes;testi++){
			max=0;
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
		}
		stop = clock(); 
		duration = ((double)(stop - start))/CLK_TCK;  
		printf("%d ",max);
		printf("%d ",stop - start);
		printf("%lf\n",duration);
		
	}
	fclose(stdin);
	fclose(stdout);
	if(nown==5) nown=10;
	else if(nown==10) nown=30;
	else if(nown==30) nown=50;
	else if(nown==50) nown=80;
	else if(nown==80) nown=100;
	else if(nown==100) break;//5 10 30 50 80 100

	}
}
