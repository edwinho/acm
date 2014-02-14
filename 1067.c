#include <stdio.h>

int main(void)
{
	int color[16][3];
	int i , j;
	for(i=0; i<16; i++)
	{
		for(j=0; j<3; j++)
		{
			scanf("%d", &color[i][j]);
		}
	}
	int r, g, b;
	int distance, index, d;
	while(1)
	{
		distance = 255*255*3;
		index = -1;
		scanf("%d", &r);
		scanf("%d", &g);
		scanf("%d", &b);
		if(r==-1 && g==-1 && b==-1)
			break;
		for(i=0; i<16; i++)
		{
			d = (r - color[i][0]) * (r - color[i][0]) + (g - color[i][1]) * (g - color[i][1]) + (b - color[i][2]) * (b - color[i][2]);
			if(d < distance){
				distance = d;
				index = i;
			}
		}
		printf("(%d %d %d) maps to (%d %d %d)\n", r, g, b, color[index][0], color[index][1], color[index][2]);
	}
	return 0;
}
