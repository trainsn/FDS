/*
	In this program,we use the variable i,j to represent the starting row and the end row,
and traverse all the possible situation. I use sum[k] to represent the sum of the kth 
column from the ith row to the jth row. Then we can solve the problem by the algorithm of 
one-dimensional problem.
	As we can see in the program, the complexity is O(n^3)
*/
#include <time.h> 
clock_t  start, stop; 
/* clock_t is a built-in type for processor time (ticks) */ 
double  duration;  
/* records the run time (seconds) of a function */  
#include<stdio.h>
#include<string.h>
int sum[105]={0},a[105][105];

int testtimes=1,testi=0;
int main()
{
	char finname[10];char foutname[20];
	int nown=5;

	while(1){
		sprintf(finname,"nis%d.in",nown);
		sprintf(foutname,"n3-nis%d.out",nown);
		freopen(finname,"r",stdin);
		freopen(foutname,"w",stdout);
		testtimes=1600000/((nown/5)*(nown/5)*(nown/5));	
		

		main_();
		
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
int main_()
{
   	int max,n,i,j,ans,k,sum1; 
	while(scanf("%d",&n)!=EOF)
	{	
		memset(a,0,sizeof(a));
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
				scanf("%d",&a[i][j]);
		
		ans=0;
		start = clock(); 
		for(testi=1;testi<=testtimes;testi++){

		for (i=1;i<=n;i++)
		{			
			memset(sum,0,sizeof(sum));
			for (j=i;j<=n;j++)	
			{
				sum1=0;
				max=0;
				//calulate the sum of the kth column  from the ith row to the jth row  
				for (k=1;k<=n;k++)
					sum[k]+=a[j][k];	
				
				//then we can solve the problem by the algorithm of one-dimensional problem
				for (k=1;k<=n;k++)
				{
					if (sum1>0) sum1+=sum[k];//if the previous is positive then it may be in the answer
					else sum1=sum[k];//else we just drop it and resrart from sum[k]
					if (sum1>max) max=sum1; 
				}
				if (max>ans)ans=max;		
			}
		}

		}

		stop = clock(); 
		duration = ((double)(stop - start))/CLK_TCK;  
		printf("%d %d ",ans,stop-start);
		printf("%lf\n",duration);
	}
		
	return 0;
}
