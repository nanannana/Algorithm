#include<stdio.h>
#include<math.h>
double m,n,h;
double low,high,mid;
double result;
double save;
double cal(double x);

void search(double low, double high)
{
	mid = (low + high) / 2.0;
	if(save == mid)
	{
		result = mid;
		return;
	}
	if(cal(mid) * cal(low) < 0)
		high = mid;
	else if(cal(mid) * cal(low) > 0)
		low = mid;
	else
	{
		result = mid;
		return;
	}
	save = mid;
	search(low,high);
}

double cal(double x)
{
	return h /( sqrt(pow(m,2) - pow(x,2) )) + h / (sqrt(pow(n,2) - pow(x,2)))-1;
}
int main(void)
{
	save = 0;
	scanf("%lf%lf%lf", &m,&n,&h);
	low = 0;
	if(m<=n)
		high = m;
	else
		high = n;
	search(low, high);
	printf("%.3lf", result);
}
