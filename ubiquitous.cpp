#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<utility>
#include<iostream>

using namespace std;

int N;
int M;
int result;

int main(void)
{
	int a,b;
	vector<pair<int, int> > v;

	scanf("%d%d", &N, &M);
	
	for(int i=1; i<=M; i++)
	{
		scanf("%d%d", &a, &b);
		v.push_back(make_pair(a,b));
	}
	sort(v.begin(), v.end());

	vector<pair<int, int> >::const_iterator itr;
/*	for(itr = v.begin(); itr!= v.end(); itr++)
	{
		printf("%d  %d \n", (*itr).first, (*itr).second);
	}*/


}
