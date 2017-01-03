#include<vector>
#include<iostream>
#include<stack>

using namespace std;

class Dot
{
public:
	int in_degree;
	int out_degree;
	vector<int> * point_to;
	bool accept_to_topological;
};

int num_of_spots;
int num_of_lines;

int main()
{
	cin >> num_of_spots;
	cin >> num_of_lines;

	Dot * spots = new Dot[num_of_spots + 1];
	for (int i = 1; i <= num_of_spots; i++)
	{
		spots[i].in_degree = 0; 
		spots[i].out_degree = 0;
		spots[i].point_to = new vector<int>;
		spots[i].accept_to_topological = false;
	}

	int start_spot;
	int end_spot;

	for (int i = 0; i < num_of_lines; i++)
	{
		cin >> start_spot;
		cin >> end_spot;
		spots[start_spot].point_to->push_back(end_spot);
		spots[start_spot].out_degree++;
		spots[end_spot].in_degree++;
	}

	stack<int> zero_degree;
	for (int i = 1; i <= num_of_spots; i++)
	{
		if (spots[i].in_degree == 0)
		{
			zero_degree.push(i);
		}
	}


	int spot_to_release;
	int*topologocal = new int[num_of_spots];
	int count = 0;
	while (!zero_degree.empty())
	{
		spot_to_release = zero_degree.top();
		topologocal[count] = spot_to_release;
		count++;
		zero_degree.pop();
		spots[spot_to_release].accept_to_topological = true;
		for (int i = 0; i < spots[spot_to_release].point_to->size(); i++)
		{
			spots[(*spots[spot_to_release].point_to)[i]].in_degree--;
			if (spots[(*spots[spot_to_release].point_to)[i]].in_degree == 0)
			{
				zero_degree.push((*spots[spot_to_release].point_to)[i]);
			}
		}
	}


	
	if (count == num_of_spots)
	{
		cout << "YES" << endl;
		for (int i = 0; i < count - 1; i++)
		{
			cout << topologocal[i] << ",";
			
		}
		cout << topologocal[count - 1];
		return 0;
	}

	for (int i = 1; i <= num_of_spots; i++)
	{
		if (spots[i].out_degree == 0 && spots[i].in_degree != 0)
		{
			count++;	
			spots[i].accept_to_topological = true;

		}
	}
	
	int spots_exiting = num_of_spots - count;
	
	bool ready_to_accept = true;
	for (int i = 0; i < spots_exiting; i++)
	{
		for (int j = 1; j <= num_of_spots; j++)
		{
			ready_to_accept = true;
			for (int k = 0; k < spots[j].point_to->size(); k++)
			{
				if (!spots[(*spots[j].point_to)[k]].accept_to_topological)
				{
					ready_to_accept = false;
				}
			}
			if (ready_to_accept)
			{
				spots[j].accept_to_topological = true;
			}
		}
	}


	int spot_to_start = 1;
	while (spots[spot_to_start].accept_to_topological)
	{
		spot_to_start++;
	}
	
	
	int*loop = new int[spots_exiting + 1];
	loop[0] = spot_to_start;
	int loop_start = 0, loop_end = 0;

	int m;
	for (int i = 1; i <= spots_exiting; i++)
	{
		m = 0;
		while (spots[(*spots[loop[i - 1]].point_to)[m]].accept_to_topological)
		{
			m++;
		}	
		loop[i] = (*spots[loop[i - 1]].point_to)[m];
		for (int j = i - 1; j >= 0; j--)
		{
			if (loop[j] == loop[i])
			{
				loop_start = j;
				loop_end = i;
				break;
			}
		}

	}

	cout << "NO" << endl;
	for (int i = 0; i < loop_end - loop_start; i++)
	{
		cout << loop[i + loop_start]<< ",";
	}
	cout << loop[loop_end];
	return 0;
}