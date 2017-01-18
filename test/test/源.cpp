#include<vector>
#include<iostream>

using namespace std;

int main()
{
	//int a[10][10];
	int**a=new int *[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = new int[i];

	}



	system("pause");
}