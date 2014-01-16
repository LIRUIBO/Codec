#ifndef DECODER_H_INCLUDED
#define DECODER_H_INCLUDED
#include <math.h>
#include <iostream>
using namespace std;

int decode(double *map,int w,int np)
{
	double d_w = w;
	double d_np = np;
	double d_p = d_np/d_w;

	double delta;
	double L0;
	int m_L;
	int d;

	// m(L)
	m_L = int(4*map[0]/d_p-0.5)%4;
	//cout << "m_L = " << m_L << endl;

	// delta
	if(m_L==0)
		delta = d_p*map[1]/2;
	else if(m_L==1)
		delta = d_p*map[2]/2;
	else if(m_L==2)
		delta = d_p*(1-map[1])/2;
	else
		delta = d_p*(1-map[2])/2;
	//cout << "delta = " << delta << endl;
	
	// L0
	L0 = map[0]-(fmod(map[0]-d_p/8,d_p))+d_p*m_L/4-d_p/8;
	//cout << "L0 = " << L0 << endl;

	d = int(w*(L0+delta));
	return d;
}

#endif // DECODER_H_INCLUDED