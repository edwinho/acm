#include <stdio.h>
#include <string.h>

int main()
{
	int n, i, j, len;
	char str[51];
	scanf("%d", &n);
	for(i=1; i<=n; i++)
	{
		scanf("%s", str);
		printf("String #%d\n", i);
		len = strlen(str);
		for(j=0; j<len; j++)
		{
			if(str[j] == 'Z')
				printf("A");
			else
				printf("%c", str[j]+1);
		}
		printf("\n\n");
	}
	return 0;	
}
