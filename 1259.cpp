#include<stdio.h>
#include<iostream>
using namespace std;
int i,m,n;
bool flag;
int order[1000];
int main()
{
	while(scanf("%d",&n)&&n>0)
	{
		for(i=0;i<=n+1;i++)
			order[i]=0;
		while(scanf("%d",&m)&&m>0)
		{
			order[m]=1;
			flag=1;
			for(i=2;i<=n;i++)
			{
				scanf("%d",&m);
				order[m]=i;
				if(order[m-1]&&order[m+1]&&order[m+1]<order[m-1])
					flag=0;
			}
			if(flag)
				printf("Yes\n");
			else
				printf("No\n");		
			for(i=0;i<=n+1;i++)
				order[i]=0;
		}
		printf("\n");
	}
	return 0;
}