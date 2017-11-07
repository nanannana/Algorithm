#include<stdio.h>

int array[130][130];
int N;
int pinkCount;
int whiteCount;
int save[130][130];

void merge(int n)
{
	int i=1, j=1;
	int a,b,count=0;
	if(n<=1)
		return;
	while(i < n)
	{
		if(array[i][j] == array[i+1][j])
			count++;
		if(array[i][j] == array[i][j+1])
			count++;
		if(array[i][j] == array[i+1][j+1])
			count++;
		if(count == 3)
		{
			if(array[i][j] == 1)
				pinkCount -=3;
			else if(array[i][j] == 0)
				whiteCount -=3;
			else
				;
			save[1 + i/2 ][1+j/2] = array[i][j];
		}
		else
		{
			save[1 + i/2 ][1+j/2] = 2;
		}
		count =0;
		
		j+=2;
		if(j > n)
		{
			i+=2;
			j=1;
		}
	}
	
	
	for(a=1; a<=n/2; a++)
	{
		for(b=1; b<=n/2; b++)
		{
			array[a][b] = save[a][b];
	//		printf("%d  ", save[a][b]);
		}
//		printf("\n");
	}
	merge(n/2);
}


int main(void)
{
	pinkCount = 0;
	whiteCount = 0;
	scanf("%d",&N);
	int i,j;
	for(i=1; i<=N; i++)
	{
		for(j=1; j<=N; j++) 
		{
			scanf("%d",&array[i][j]);
			if(array[i][j] == 1)
				pinkCount++;
			else if(array[i][j] == 0)
				whiteCount++;
		   	else
				;
		}
	}
	merge(N);
	printf("%d\n", whiteCount);
	printf("%d", pinkCount);
}
