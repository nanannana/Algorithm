#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<climits>
using namespace std;
int map[201][201];
int start[3];
int end[3];
int N,M;
int result;

priority_queue<vector<int>,  vector<vector<int> > ,greater<vector<int> > > q;

void DaehoPush(int i, int j, int distance)
{
	vector<int> v;
	v.push_back(distance);
	v.push_back(i);
	v.push_back(j);
	q.push(v);
}

int isend(int i, int j)
{
	return ( (i == end[1]) && (j == end[2]) );
}

void hi(vector<int> temp)
{
	int i = temp[1];
	int j = temp[2];
	int dis = temp[0];
	if(i < N && i > 0)
		DaehoPush(i+1 , j, dis + map[i+1][j]);
	if(i > 1 && i <= N)
		DaehoPush(i-1, j, dis + map[i-1][j]);
	if(j < M && j > 0)
		DaehoPush(i, j+1, dis + map[i][j+1]);
	if(j > 1 && j <= M)
		DaehoPush(i, j-1, dis + map[i][j-1]);
}

int main(void)
{
	vector<int> temp;
	result = INT_MAX;
	scanf("%d%d", &N, &M);
	for(int i=1; i<= N; i++)
	{
		for(int j=1; j<=M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	scanf("%d%d", &start[1], &start[2]);
	scanf("%d%d", &end[1], &end[2]);

	DaehoPush(start[1], start[2], map[start[1]][start[2]]);
	while(!q.empty())
	{
		temp = q.top();
	//	printf("i : %d / j : %d / distance: %d\n", temp[1], temp[2], temp[0]);
		q.pop();
		if(result < temp[0])
			continue;
		if(temp[1] == end[1] && temp[2] == end[2])
			result = temp[0];
		hi(temp);
	}
	printf("%d\n", result);
}

