#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;
char s[10];
map<string,int> mapstring;
int a[1005][1005];

int get(string s) 
{
	map<string,int>::iterator t = mapstring.find(s);
    if (t == mapstring.end()) {
        mapstring.insert(make_pair(s, mapstring.size()));
        return mapstring.size() - 1;
    }
    return t->second;
}

int max_flow(int n,int mat[][1005],int source,int sink)
{
    int v[1005],c[1005],p[1005],ret=0,i,j;
    while(1)
	{
        for (i=0;i<n;i++)
            v[i]=c[i]=0;
		c[source]=214748367;
		while(1)
		{
            for (j=-1,i=0;i<n;i++)
                if (!v[i]&&c[i]&&(j==-1||c[i]>c[j]))
                    j=i;
            if (j<0) return ret;
            if (j==sink) break;
            for (v[j]=1,i=0;i<n;i++)
                if (mat[j][i]>c[i]&&c[j]>c[i])
				{
					c[i]=mat[j][i]<c[j]?mat[j][i]:c[j];
					p[i]=j;
				}                                       
        }
		
        for (ret+=j=c[i=sink];i!=source;i=p[i])
		{
			mat[p[i]][i]-=j;
			mat[i][p[i]]+=j;					
		}                  
    }
}
int main() 
{
	//freopen("bonus.in","r",stdin);
	//freopen("bonus.out","w",stdout);
    scanf("%s",s);
    int source = get((string) s);
    int m;
    scanf("%s%d",s, &m);
    int target = get((string) s);
    for (;m;--m) 
	{
        scanf("%s",s);
        int x = get((string) s);
		scanf("%s",s);
        int y = get((string) s);
        int z;
        scanf("%d",&z);
         if (z > a[x][y]) 
		{
            a[x][y] = z;
        }
    }
    printf("%d\n",max_flow(mapstring.size(), a, source, target));
    return 0;
}
