#include<stdio.h>
#include<string.h>

#define count 30001
int result[2][30002];
int All[30001];
int Nae[30001];
int N;
int RC;

void cal(int arr[30001])
{
	for(int i=1; i<=N; i++)
	{
		if(arr[i] != 1)
			result[0][count] += 1;
		result[0][i] = 1;
		
		if(i==1 || arr[i] >= result[1][i-1])
			result[1][i] = arr[i];
		else
		{
			if(arr[i] == 1)
				// 1쭉 최적
				;
			else
			{
			}
		}
	}
}

int main(void)
{
	memset(result,0,sizeof(result));
	sacnf("%d",&N);
	for(int i=1; i<=N; i++)
	{
		scanf("%d", &All[i]);
		Nae[N-i+1] = All[i];
	}
	cal(All);
	cal(Nae);
}

