#include <stdio.h>
#include <string.h>

/*
	���⣬Ҫע�����ZOJ�ϵĲ������ݻ�ܴ�ܳ�����������Ĳ������ݱ���Ҫ�ַ��͡�
*/

int repeat(int sum)
{
	int temp = sum;
	sum = 0;
	while( temp/10 )
	{
		sum += temp % 10;
		temp /= 10;
	}
	sum += temp;
	if( sum > 9)
		return repeat(sum);
	return sum;
}
int main(void)
{
	char num[1005];
	int sum, length, i;
	while(1)
	{
		scanf("%s", &num);
		if( num[0] == '0' )
			break;
		length = strlen(num);
		sum = 0;
		for(i=0; i<length; i++)
		{
			sum += num[i] - '0';
		}
		if( sum > 9 )
		{
			sum = repeat(sum);     /* digital rootֻ����һλ�� */
		}
		printf("%d\n", sum);
	}
	return 0;
}