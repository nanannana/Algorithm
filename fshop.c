#include<stdio.h>
#include<string.h>
int vase;
int flower;
int arr[101][101];
int result[101][101];
int max;
void search(int n)
{
	int i,k,temp, resultN;
	int last = vase - (flower -n + 1) + 1;
	for(i=n; i<=last; i++)
	{
		resultN = result[n-1][n-1] + arr[n][i];
		for(k=n; k< i; k++)
		{
			if(resultN <=  result[n-1][k] + arr[n][i])
			{
				resultN = result[n-1][k] + arr[n][i];
			}
		}
		result[n][i] = resultN;
	//	printf("%d ", resultN);
		if(i == n)
			max = resultN;
		else if(max <= result[n][i])
			max = result[n][i];
		else 
			;
	}
	//printf("\n");
}

int main(void)
{
	memset(arr, 0, sizeof(arr));
	memset(result, 0 , sizeof(result));
	
	int i,j;
	
	scanf("%d%d", &flower, &vase);
	
	for(i=1; i<= flower; i++)
	{
		for(j=1; j<=vase; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	for(i=1; i<=flower; i++)
	{
		search(i);
	}
	printf("%d\n" ,max);
}
