/*
	O(n^6)
*/
#include<stdio.h>
#include<string.h>

#include <time.h> 
clock_t  start, stop; 
/* clock_t is a built-in type for processor time (ticks) */ 
double  duration;  
/* records the run time (seconds) of a function */  

int max=0;
int testtimes=1,testi=0;

int main()
{
	char finname[10];char foutname[20];
	int nown=5;

	while(1){
		sprintf(finname,"nis%d.in",nown);
		sprintf(foutname,"n6-nis%d.out",nown);
		freopen(finname,"r",stdin);
		freopen(foutname,"w",stdout);
	
	
		testtimes=160000/((nown/5)*(nown/5)*(nown/5)*(nown/5)*(nown/5)*(nown/5));
		if(testtimes==0) testtimes=1;

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
	int stx,sty,enx,eny,i,j,n,sum;
	int a[105][105];
	

	while (scanf("%d",&n)!=EOF)
	{
		start = clock(); 

		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
				scanf("%d",&a[i][j]);
	//serach all the matrix
		//(stx,sty) is the starting point
		for(testi=1;testi<=testtimes;testi++){
			max=0;
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

		
		}
		stop = clock(); 
		duration = ((double)(stop - start))/CLK_TCK;  
		printf("%d %d ",max,stop-start);
		printf("%lf\n",duration);
       
	}

	return 0;
}