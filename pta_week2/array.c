#include<stdio.h>
int main(void)
{
	
	int na,nb;
	int coans[1005],expans[1005],coa[1005],cob[1005],expa[1005],expb[1005];
	int i;
	freopen("n4.in","r",stdin);
	freopen("n4.out","w",stdout);
	
	scanf("%d",&na);
	for (i=0;i<na;i++)
	{
		scanf("%d%d",&coa[i],&expa[i]);
	}
	scanf("%d",&nb);
	for (i=0;i<nb;i++)
	{
		scanf("%d%d",&cob[i],&expb[i]);
	}
	
	int ta=0,tb=0,tans=0;
	while (ta<na&&tb<nb)
	{
		if (expa[ta]>expb[tb])
		{
			coans[tans++]=coa[ta];
			expans[tans]=expa[ta];
			ta++;
		}
		if (expa[ta]<expb[tb])
		{
			coans[tans++]=cob[tb];
			expans[tans]=expb[tb];
			tb++;
		}
		if (expa[ta]==expb[tb])
		{
			coans[tans++]=coa[ta]+cob[tb];
			expans[tans]=expa[ta];
			ta++;
			tb++;
		}
	}
	while (ta<na)
	{
		coans[tans++]=coa[ta];
		expans[tans]=expa[ta];
		ta++;
	}
	while (tb<nb)
	{
		coans[tans++]=cob[tb];
		expans[tans]=expb[tb];
		tb++;
	}
	
	for (i=0;i<tans;i++)
	{
		printf("%d %d",coans[i],expans[i]);
	}
}