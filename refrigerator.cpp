#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int N;
int result;

bool sort_second(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.second < b.second;
}

int main(void)
{
	vector<pair<int, int> > v;
	int n=0,up,down;
	
	result = 0;
	scanf("%d", &N);
	
	for(int i=1; i<=N; i++)
	{ 
		scanf("%d%d", &up, &down);
		v.push_back(make_pair(up,down));
	}
	sort(v.begin(), v.end(), sort_second);
	vector<pair<int, int> >::const_iterator itr;
	printf("\n");
	for(itr = v.begin(); itr != v.end(); itr++)
	{
		printf("%d  %d\n", (*itr).first, (*itr).second);
	}
	printf("\n");
	itr = v.begin();
	up = 0;
	itr++;
	result ++;
	for(; itr != v.end(); itr++)
	{
		n++;
		if(v[up].second < (*itr).first)
		{
			up = n;
			result++;
		}
	}
	printf("%d\n", result);
}
