#include<time.h>
#include<math.h>
#include<stdio.h>

#define FLT_MIN 0.000000001

float InvSqrt(float x)
{
	float xhalf = 0.5f*x;
	int i = *(int*)&x; // get bits for floating value
	i = 0x5f3759df - (i >> 1); // gives initial guess y0
	x = *(float*)&i; // convert bits back to float
	x = x*(1.5f - xhalf*x*x); // Newton step, repeating increases accuracy
	return x;
}
double mySqrt_newton(int x)
{
	if (x <= 0)   return 0;

	double res, lastres;

	res = x;    //初始值，可以为任意非0的值  

	do{
		lastres = res;
		res = (res + x / res) / 2;
	} while (abs(lastres - res) > FLT_MIN);

	return res;
}
double mySqrt_binarysearch(int x)
{
	if (x <= 0)   return 0;

	double begin = 1;
	double end = x / 2 + 1;
	double mid, lastmid;

	mid = begin + (end - begin) / 2;
	do{
		if (mid < x / mid) begin = mid;
		else    end = mid;

		lastmid = mid;
		mid = begin + (end - begin) / 2;
	} while (abs(lastmid - mid) > FLT_MIN);

	return mid;
}

int main(int argc, char **argv)
{
	clock_t begin, end;
	int num = 65535;
	double res;

	int i;
	int loopcnts = 100000;


	begin = clock();
	for (i = 0; i < loopcnts; i++)
		res = mySqrt_binarysearch(num);
	end = clock();
	printf("mySqrt_binarysearch(%d) = %f, spent time is %f\n", num, res, (double)(end - begin));


	begin = clock();
	for (i = 0; i < loopcnts; i++)
		res = mySqrt_newton(num);
	end = clock();
	printf("mySqrt_newton(%d) = %f, spent time is %f\n", num, res, (double)(end - begin));

	
		begin = clock();
	for (i = 0; i < loopcnts; i++)
		res = InvSqrt(num);
	end = clock();
	printf("InvSqrt(%d) = %f, spent time is %f\n", num, 1/res, (double)(end - begin));
	




	begin = clock();
	for (i = 0; i < loopcnts; i++)
		res = sqrt((double)num);
	end = clock();
	printf("system sqrt(%d) = %f, spent time is %f\n", num, res, (double)(end - begin));

	
	getchar();
}