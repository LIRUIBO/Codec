#ifndef ENCODER_H_INCLUDED
#define ENCODER_H_INCLUDED
#include <math.h>
#include <iostream>
using namespace std;

// Decimal value to 8bit
void D2B(int *v_8b,int value);

// Encoder
int encode(int before, int *L_8b, int *Ha_8b, int *Hb_8b, int w,int np)
{
	float d_b = before;
	float d_w = w;
	float d_np = np;
	float d_p = d_np/d_w;
	float L, Ha, Hb;
	int Lev, Haev, Hbev;

	float j1,j2;
	// L
	L = (d_b+0.5)/d_w;
	Lev = int(255*L+0.5);
	D2B(L_8b,Lev);
	
	// Ha
	j1 = fmod(L/(d_p/2),2);
	if(j1<=1)
		Ha = j1;
	else Ha = 2-j1;
	Haev = int(255*Ha+0.5);
	D2B(Ha_8b,Haev);

	//Hb
	j2 = fmod((L-d_p/4)/(d_p/2),2);
	if(j2<=1)
		Hb = j2;
	else Hb = 2-j2;
	Hbev = int(255*Hb+0.5);
	D2B(Hb_8b,Hbev);

	return 0;
}

void D2B(int *v_8b,int value)
{
	for(int i=0;i<8;i++)
	{
		v_8b[i] = value%2;
		if(value/2==0) break;
		value /= 2;
	}
}

#endif // ENCODER_H_INCLUDED