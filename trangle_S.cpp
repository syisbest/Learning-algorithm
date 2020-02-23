#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <string.h>
using namespace std;

double trangle_area(double x0,double y0,double x1,double y1,double x2,double y2)
{
	double s = x0*y1 + x2*y0 + x1*y2 - x2*y1 - x1*y0 - x0*y2;
	return fabs(s);
}
int main()
{
	double x0,y0,x1,y1,x2,y2;
	int count = 0;
	cin>>x0>>y0>>x1>>y1>>x2>>y2;
	for(int i=1;i<=99;i++)
		for(int j=1;j<=99;j++)
			if(fabs(trangle_area(x0,y0,x1,y1,x2,y2) - (trangle_area(x0,y0,x1,y1,i,j)+trangle_area(x0,y0,i,j,x2,y2)+trangle_area(i,j,x1,y1,x2,y2)))<1e-9)
				count++;
	cout<<count;
	return 0;
}
