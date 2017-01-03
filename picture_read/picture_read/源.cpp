#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	fstream infile;
	infile.open("1.jpg", ios::binary | ios::in);
	string c;
	string temp;
	while (getline(infile,temp))
	{
		temp += "\n";
		c += temp;
	}
	infile.close();

	fstream outfile;
	outfile.open("2.jpg", ios::binary | ios::out);
	outfile << c;

}