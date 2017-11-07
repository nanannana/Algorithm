#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<utility>
#include<iostream>

using namespace std;
int array[500001];
int N;
int M;
int result;

int search(vector<vector<int> > group, int a) {

	for(int i=0; i<group.size(); i++)
	{
		for(int j=0; j< group[i].size(); j++)
		{
			if(group[i][j] == a)
				return i;
		}
	}
	return -1;
}

int main(void)
{
	int a,b,g, groupSize=-1;
	vector<int > v;
	vector<vector<int> > group;

	result = 0;
	memset(array, 0 , sizeof(array));

	scanf("%d%d", &N, &M);
	
	for(int i=1; i<=M; i++)
	{
		scanf("%d%d", &a, &b);
		if(array[a]==0 && array[b] == 0)
		{
			groupSize++;
			group.push_back(vector<int>());
			group[groupSize].push_back(a);
			array[a] = 1;
			
			if(a != b){
				group[groupSize].push_back(b);
				array[b] = 1;
			}
		}
		else if(array[a] - array[b] < 0)
		{
			g= search(group, b);
			group[g].push_back(a);
			array[a] = 1;
		}
		else if(array[a] -  array[b] > 0)
		{
			g = search(group, a);
			group[g].push_back(b);
			array[b] = 1;
		}
		else
		{
			g = search(group, a);
			int k = search(group,b);
			if(g != k)
			{
				for(int j=0; j< group[k].size(); j++)
				{
					group[g].push_back(group[k][j]);
				}
				group.erase(group.begin() + k);
				groupSize--;
			}
			else
				;
		}
		
	}

	for(int i=0; i< group.size(); i++)
	{
		result += group[i].size();
		if(M==100000) {
			for(int j=0; j<group[i].size(); j++)
			{
				v.push_back(group[i][j]);
			}
		}
	}
	if(M==100000)
	{
		sort(v.begin(), v.end());
		for(int i=0; i<v.size()-1; i++)
		{
			if(v[i] == v[i+1])
				printf("%d\n", v[i]);
		}
	}
	printf("%d", groupSize + 1+  N-result);

}
