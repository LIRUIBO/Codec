#ifndef ENCODER_H_INCLUDED
#define ENCODER_H_INCLUDED
#include <math.h>
#include <iostream>
using namespace std;

int encode(int before, double *map,int w,int np)
{
	double d_b = before;
	double d_w = w;
	double d_np = np;
	double d_p = d_np/d_w;

	double j1,j2;
	// L
	map[0] = (d_b+0.5)/d_w;
	
	// Ha
	j1 = fmod(map[0]/(d_p/2),2.0);
	if(j1<=1)
		map[1] = j1;
	else map[1] = 2-j1;

	//Hb
	j2 = fmod((map[0]-d_p/4)/(d_p/2),2);
	if(j2<=1)
		map[2] = j2;
	else map[2] = 2-j2;

	return 0;
}

#endif // ENCODER_H_INCLUDED