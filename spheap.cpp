#include<stdio.h>
#include<queue>
#include<string.h>
#include<algorithm>
#include<utility>
using namespace std;

class node{
public:
	int distance;
	pair<int, int> loc;

	node(int distance, pair<int, int> a)
	{
		this -> distance = distance;
		loc = a;
	}

	bool operator<(const node & n) const{
		return distance > n.distance;
	}
};


int input[201][201];
int N,M;
int a,b;
int result;

int main(void)
{
	pair<int ,int> start;
	pair<int ,int> end;
	priority_queue <node, vector<node>, less<node> > q;
	int a,b;

	scanf("%d", &N);
	scanf("%d", &M);
	for(int i=1; i<= N; i++)
	{
		for(int j=1; j<=M; j++)
		{
			scanf("%d", &input[i][j]);
		}
	}
	scanf("%d%d", &a,&b);
	start=make_pair(a,b);
	printf("stawrt: %d %d \n" ,a ,b);


	scanf("%d%d", &a,&b);
	end=make_pair(a,b);
	
	q.push(node( input[start.first][start.second] , start));
	node temp = q.top();
	while(!q.empty())
	{
		q.pop();
		if(temp.loc == end){
			if(temp.distance > result)
				result = temp.distance;
		}
		
	}
}
