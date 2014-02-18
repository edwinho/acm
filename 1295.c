#include <stdio.h>

int main()
{
	int n, length = 0;
	char str[71], c;
	scanf("%d", &n);
	scanf("%c", &c);    /*处理掉第一个字符*/
	while(n--)
	{
		while(scanf("%c", &str[length]) != EOF && str[length] != '\n')
			length++;
		while(length)
			printf("%c", str[--length]);
		printf("\n");
	}
	return 0;
}
