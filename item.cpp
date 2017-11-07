#include<stdio.h>
#include<string.h>

int pocketSize;
int trashSize;

int pocket[3];
int trash[1000];
char input[1000];
void addTrash(int num);

bool findPocket(int num)
{
	for(int i=1; i<=3; i++)
	{
		if(num == pocket[i])
			return true;
	}
	return false;
}

void addTrash(int num)
{
	trash[trashSize] = num;
	trashSize ++;
}

void addPocket(int num)
{
	if(pocketSize == 3)
	{
		if(num == pocket[0])
			return;
		else if(num == pocket[1])
		{
			int temp = pocket[1];
			pocket[1] = pocket[0];
			pocket[0] = temp;
			return;
		}
		else if(num == pocket[2])
		{
			int temp = pocket[0];
			pocket[0] = pocket[2];
			pocket[2] = temp;
			
			return;
		}
		else
		{
			addTrash(pocket[2]);
			pocketSize--;
		}
	}
	pocket[2] = pocket[1];
	pocket[1] = pocket[0];
	pocket[0] = num;
	pocketSize++;
}

int main(void)
{
	pocketSize = 0;
	trashSize = 0;
	memset(pocket,0,sizeof(pocket));
	memset(pocket,0,sizeof(input));
	memset(pocket,0,sizeof(trash));
	gets(input);
	
	for(int i=0; i<strlen(input); i++)
	{
		if(input[i] == ' ')
			;
		else
		{
			addPocket(input[i] - '0');
		}
	}
	for(int i=0; i<trashSize; i++)
	{
		printf("%d\n", trash[i]);
	}
	if(trashSize == 0)
		printf("%d\n",0);
}
