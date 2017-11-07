#include<stdio.h>
#include<iostream>

int arr[2][301];
int num[301];
int max;

int main(void)
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", &num[i]);
    
    arr[0][1] = num[1];
    arr[1][1] = num[1];
    max = arr[0][2] = num[1] + num[2];
    arr[1][2] = num[2];
    
    for(int i=3; i<=n; i++)
    {
        arr[0][i] = arr[1][i-1] + num[i];
        arr[1][i] = arr[0][i-2] > arr[1][i-2] ? arr[0][i-2] : arr[1][i-2];
        arr[1][i] += num[i];
        max = arr[0][i] > arr[1][i] ? arr[0][i] : arr[1][i];
    }
    printf("%d", max);
}

