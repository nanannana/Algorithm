#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
#include<cmath>
#include<climits>
using namespace std;

int array[21][21];
int beep[21][3];
int N;
int a,b;
int result;
int bound;

int ss(vector<int> temp, int i);
priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > q;

void make_array()
{
	for(int i=0; i<=N; i++)
	{
		for(int j=0; j<=N; j++)
		{
			array[i][j] = ( abs(beep[i][1] - beep[j][1]) + abs(beep[i][2] - beep[j][2]) );
		}
		array[i][i] = INT_MAX;
	}


}

int cal_bound(vector<int> temp)
{
	int arr[21][21];
	for(int i=0; i<=N; i++)
	{
		for(int j=0; j<=N; j++)
		{
			arr[i][j] = array[i][j];
		}
	}

	int bound=0;
	int min;
	if(temp.size() > 2)
	{
		for(int i=1; i<= temp.size()-2; i++)
		{
			int a = temp[i];
			for(int j=0; j<=N; j++)
				arr[a][j] = INT_MAX;
		}

		for(int i=temp.size()-1; i>1; i--)
		{
			int a = temp[i];
			for(int j=0; j<=N; j++)
				arr[j][a] =INT_MAX;
		}

		arr[temp[temp.size() -1]][0] = INT_MAX;

		for(int i=1; i<= temp.size() - 2; i++)
			bound += array[temp[i]][temp[i+1]];
		
		if(temp.size() == N+2)
			bound+= array[temp[temp.size()-1]][0];

	}

	for(int i=0; i<=N; i++)
	{
		min = arr[i][0];
		for(int j=1; j<=N; j++)
			if(min > arr[i][j])
				min = arr[i][j];
		
		if(min != INT_MAX) 
			bound+= min;
		
	}

	return bound;
}

int main(){

	result = INT_MAX;
	scanf("%d%d", &a, &b);
	scanf("%d%d", &beep[0][1], &beep[0][2]);
	scanf("%d", &N);
	for(int i=1; i<=N; i++)
	{
		scanf("%d%d", &beep[i][1], &beep[i][2]);
	}
	make_array();

	vector<int> v;
	vector<int> temp;
	temp.push_back(0);
	temp.push_back(0);
	bound=cal_bound(temp);
	temp[0] = bound;
	q.push(temp);



	while(!q.empty())
	{
		temp = q.top();
		q.pop();
		if(result < temp[0])
			continue;
		if(temp.size() == N+2 && result > temp[0])
		{
			result = temp[0];
			continue;
		}

		for(int i=1; i<= N; i++)
		{
			if(ss(temp, i))
				;
			else
			{
				temp.push_back(i);
				bound = cal_bound(temp);
				temp[0] = bound;
				q.push(temp);
				temp.pop_back();
			}
		}
	}
	printf("%d\n", result);
}

int ss(vector<int> temp, int i)
{
	for(int j=1; j<=temp.size(); j++)
	{
		if(temp[j] == i)
			return 1;
	}
	return 0;
}
