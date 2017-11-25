#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<utility>
#include<iostream>

using namespace std;
int parent[50001];
int level[50001];
int N;
int M;
int result;

void set(){
	for(int i=1; i<=N; i++)
	{
		parent[i] = i;
		level[i] = 1;
	}
}

int find(int a) {
	while(a != parent[a])
	{
		a = parent[a];
	}
	return a;
}

int main(void)
{
	int a,b, u, v, temp;

	scanf("%d%d", &N, &M);
	
	set();
	for(int i=1; i<=M; i++)
	{
		scanf("%d%d", &a, &b);
		u = find(a);
		v = find(b);
		if(u == v)
			continue;
		else {
			if(u > v)
			{
				temp = u;
				u = v;
				v = temp;
			}

			parent[u] = v;

			if(level[u] == level[v])
				level[u]++;
		}
	}
	for(int i=1; i<=N; i++)
	{
		if(parent[i] == i)
			result++;
	}

	printf("%d" ,result);
}
