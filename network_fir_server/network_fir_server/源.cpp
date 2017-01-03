#include<afxsock.h>
#include<iostream>
using namespace std;

int main()
{
	CAsyncSocket socket;
	BOOL bFlag = socket.Create(2000, SOCK_STREAM, FD_ACCEPT);
	if (!bFlag)
	{S
		cerr << "fault" << endl;
	}


}