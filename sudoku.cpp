#include<stdio.h>
#include<vector>
#include<string.h>

using namespace std;

int array[10][10];
int data[3] = {1,4,7};
int last;
int start;
int finish = 0;

vector<int>  n;
vector<int> s;

void cal()
{
	//printf("n size : %lu, s size: %lu    ", n.size(), s.size());
//	printf("f : %d \n", finish);
	if(n.size() == s.size()){
		printf("\n");
		finish = 1;
		for(int i=1; i<=9; i++){
			for(int j=1; j<=9; j++)
				printf("%d", array[i][j]);
			printf("\n");
		}
		
		return;
	}
	if(finish)
		return;
	int d;
	int arr[10];
	int loc = n[s.size()];
	int i= loc / 10;
	int j = loc % 10;
	int k,l;
	memset(arr, 0 ,sizeof(arr));

//	printf("loc : %d %d \n", i,j);
	for( k =1; k<= 9; k++)
	{
		arr[array[k][j]] = -1;
	}
	for( k =1; k<= 9; k++)
	{
		arr[array[i][k]] = -1;
	}
//	printf("cla :i %d\n", data[(i-1) / 3]);
//	printf("cla :j %d\n", data[(j-1) / 3]);
	for( k = data[(i-1) /3]; k <= data[(i-1) /3] + 2; k++)
	{
		for( l = data[(j-1)/3] ; l<= data[(j-1)/3] + 2; l++) 
		{
			arr[array[k][l]] = -1;
		}
	}
//	printf("k : %d, l : %d", k,l);
//	printf("\n");
	
/*	for(int k=1; k<=9; k++)
	{
		printf("%d  ", arr[k]);
	}		
	printf("\n");
*/
	for( k=1; k<= 9; k++)
	{
		if(arr[k] == 0)
		{
			array[i][j] = k;
			s.push_back(k);
			cal();
			s.pop_back();
			array[i][j] = 0;
		}
	}
}

int main(void)
{

	start = 0;
	char a[10];
	for(int i=1; i<=9; i++)
	{
		scanf("%s", a);
		for(int j=0; j< 9; j++)
		{
			array[i][j+1] = a[j] -'0';
			if(array[i][j+1] == 0) {
				n.push_back( (i*10) + j+1);
				last = array[i][j +1];
				if(start ==0)
					start = array[i][j+1];
			}
		}
	}

/*	printf("\n");
	for(int i=1; i<=9; i++)
	{
		for(int j=1; j<=9; j++)
		{
			printf("%d", array[i][j]);

		}
		printf("\n");
	}*/
	cal();

}
