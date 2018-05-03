/* Author: 施能; ID:3140100193; No.02 */
#include <iostream>
#include <cstdio>
#include <queue>
#include<string.h>
#include <map>
using namespace std;
#define arraysize 1005
int maxData = 0x7fffffff;
int capacity[arraysize][arraysize]; //store the capacity of the network
int flow[arraysize];                //sign how much flow is left from the source to current node  
int pre[arraysize];                 //sign the precursor of this node in the path, and sign whether the node is in the queue
int n,m;
queue<int> myqueue;
char s[10];
map<string,int> mapstring;

int get(string s) 
{
	map<string,int>::iterator t = mapstring.find(s);
    if (t == mapstring.end()) 
	{
        mapstring.insert(make_pair(s, mapstring.size()+1));
        return mapstring.size();
    }
    return t->second;
}

int BFS(int src,int des)
{
    int i,j;
    while(!myqueue.empty())       //clear the queue
        myqueue.pop();
    for(i=1;i<m+1;++i)
    {
        pre[i]=-1;
    }
    pre[src]=0;
    flow[src]= maxData;
    myqueue.push(src);
    while(!myqueue.empty())
    {
        int index = myqueue.front();
        myqueue.pop();
        if(index == des)            //now we find the augmenting path
            break;
        for(i=1;i<m+1;++i)
        {
            if(i!=src && capacity[index][i]>0 && pre[i]==-1)
            {
                 pre[i] = index; //sign the precursor
                 flow[i] = min(capacity[index][i],flow[index]);   
                 myqueue.push(i);
            }
        }
    }
    if(pre[des]==-1)      //there is no augmenting path in the residual graph
        return -1;
    else
        return flow[des];
}
int maxFlow(int src,int des)
{
    int increasement= 0;
    int sumflow = 0;
    while((increasement=BFS(src,des))!=-1)
    {
         int k = des;          //use the precursor to find route
         while(k!=src)
         {
              int last = pre[k];
              capacity[last][k] -= increasement; //change the capacity of the forward edge
              capacity[k][last] += increasement; //change the capacity of the backward edge
              k = last;
         }
         sumflow += increasement;
    }
    return sumflow;
}
int main()
{
    //freopen("n4.in","r",stdin);
	//freopen("n4.out","w",stdout);
	int i,j;
    int start,end,ci;
	scanf("%s",s);
	int source =get((string) s);
	scanf("%s%d",s,&n);
	int target =get((string) s);	
	memset(capacity,0,sizeof(capacity));
    memset(flow,0,sizeof(flow));
	for(i=0;i<n;++i)
    {
        scanf("%s",s);
		start= get((string) s);
		scanf("%s",s);
		end= get((string) s);
		scanf("%d",&ci);
        if(start == end)               //consider the case that the starting vertice is the same as the ending vertice
            continue;
        capacity[start][end] +=ci;     //i don't know whether there is more than one edges with the same start and the same end
    }
    m=mapstring.size();
    cout<<maxFlow(source,target)<<endl;
    return 0;
}
