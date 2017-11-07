#include<stdio.h>
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<string.h>

using namespace std;

int arr[31];
int result1;
int result2;
int trueResult;

bool check(int n)
{
	int i;
	for(i=1; i<=15; i++)
	{
		if(n == arr[i])
			return false;
	}
	return true;
}

bool sort_second(const pair<int, pair<int, int> > &a, const pair<int, pair<int , int> > &b)
{
	return (a.second.second > b.second.second);
}

bool sort_first(const pair<int, pair<int, int> > &a, const pair<int, pair<int , int> > &b)
{
	return (a.second.first > b.second.first);
}

int main(void)
{
	int i=1,a,b;
	vector<pair<int, pair<int, int> > > v1;
	vector<pair<int, pair<int, int> > > v2;
	
	while(scanf("%d%d", &a, &b) != -1)
	{
		v1.push_back( make_pair(i, make_pair(a,b)) );
		v2.push_back( make_pair(i, make_pair(a,b)) );
		i++;
	}
	sort(v1.begin(), v1.end(), sort_first);
	sort(v2.begin(), v2.end(), sort_second);
	vector<pair<int, pair<int, int> > >::iterator iter;
	
	iter = v1.begin();
	for(i=1; i<=15; i++)
	{
		arr[i] += (*iter).first;
		result1 += (*iter).second.first;
		iter++;
	}
	iter = v2.begin();
	i=1;
	while(i<=15)
	{
		if(check((*iter).first))
		{
			result1+= (*iter).second.second;
			i++;
		}
		else
			;
		iter++;
	}

	memset(arr, 0, sizeof(arr));

	iter = v2.begin();
	for(i=1; i<=15; i++)
	{
		arr[i] += (*iter).first;
		result2 += (*iter).second.second;
		iter++;
	}
	iter = v1.begin();
	i=1;
	while(i<=15)
	{
		if(check((*iter).first))
		{
			result2+= (*iter).second.first;
			arr[i+15] += (*iter).first;
			i++;
		}
		else
			;
		iter++;
	}
	sort(arr, arr+31);
}


