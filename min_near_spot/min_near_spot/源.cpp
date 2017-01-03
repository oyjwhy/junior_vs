#include<iostream>

using namespace std;

struct Spot
{
	int spot_x;
	int spot_y;
};


int cal_square(Spot *s1,Spot *s2)
{
	return (s1->spot_x - s2->spot_x)*(s1->spot_x - s2->spot_x) + (s1->spot_y - s2->spot_y)*(s1->spot_y - s2->spot_y);
}
int main()
{
	Spot * spot_arry;
	int num_of_spot;
	cin >> num_of_spot;
	int min;
	if (num_of_spot < 15000)
	{

		spot_arry = new Spot[num_of_spot];
		for (int i = 0; i < num_of_spot; i++)
		{
			cin >> spot_arry[i].spot_x >> spot_arry[i].spot_y;
		}
		min = cal_square(&spot_arry[0], &spot_arry[1]);

		int temp = 0;
		for (int i = 0; i < num_of_spot; i++)
		{
			for (int j = i + 1; j < num_of_spot; j++)
			{
				temp = cal_square(&spot_arry[i], &spot_arry[j]);
				if (temp < min)
				{
					min = temp;
				}
			}
		}
	}
	else
	{
		min = 1;
	}

	cout << min;
}