#ifndef DECODER_H_INCLUDED
#define DECODER_H_INCLUDED
#include <math.h>
#include <iostream>
using namespace std;

// Retrieve Decimal value from 8bit
int B2D(int *v_8b);

// Decoder
int decode(int *L_8b,int *Ha_8b,int *Hb_8b,int w,int np)
{
	float d_w = w;
	float d_np = np;
	float d_p = d_np/d_w;

	float delta;
	float L0;
	int m_L;
	int d;
	int Lev,Haev,Hbev;
	float L,Ha,Hb;

	Lev = B2D(L_8b);
	L = float(Lev)/255;
	Haev = B2D(Ha_8b);
	Ha = float(Haev)/255;
	Hbev = B2D(Hb_8b);
	Hb = float(Hbev)/255;
	cout << endl <<"Decoder: " << endl << L << ' ' << Lev << endl;
	cout << Ha << ' ' << Haev << endl;
	cout << Hb << ' ' << Hbev << endl;

	// m(L)
	m_L = int(4*L/d_p-0.5)%4;
	//cout << "m_L = " << m_L << endl;

	// delta
	if(m_L==0)
		delta = d_p*Ha/2;
	else if(m_L==1)
		delta = d_p*Hb/2;
	else if(m_L==2)
		delta = d_p*(1-Ha)/2;
	else
		delta = d_p*(1-Hb)/2;
	//cout << "delta = " << delta << endl;
	
	// L0
	L0 = L-(fmod(L-d_p/8,d_p))+d_p*m_L/4-d_p/8;
	//cout << "L0 = " << L0 << endl;

	d = int(w*(L0+delta));
	return d;
}

int decode_BIT1(int *L_8b,int *Ha_8b,int *Hb_8b,int w,int np)
{
	int d16[16];

	d16[0] = L_8b[0];
	d16[6] = L_8b[1];
	d16[11] = L_8b[2];
	d16[1] = L_8b[3];
	d16[7] = L_8b[4];
	d16[12] = L_8b[5];

	d16[2] = Ha_8b[0];
	d16[8] = Ha_8b[1];
	d16[13] = Ha_8b[2];
	d16[3] = Ha_8b[3];
	d16[9] = Ha_8b[4];

	d16[14] = Hb_8b[0];
	d16[4] = Hb_8b[1];
	d16[10] = Hb_8b[2];
	d16[15] = Hb_8b[3];
	d16[5] = Hb_8b[4];
 
	return B2D16(d16);
}

int decode_BIT2(int *L_8b,int *Ha_8b,int *Hb_8b,int w,int np)
{
	int d16[16];

	d16[0] = L_8b[0];
	d16[1] = L_8b[1];
	d16[2] = L_8b[2];
	d16[3] = L_8b[3];
	d16[4] = L_8b[4];
	d16[5] = L_8b[5];

	d16[6] = Ha_8b[0];
	d16[7] = Ha_8b[1];
	d16[8] = Ha_8b[2];
	d16[9] = Ha_8b[3];
	d16[10] = Ha_8b[4];

	d16[11] = Hb_8b[0];
	d16[12] = Hb_8b[1];
	d16[13] = Hb_8b[2];
	d16[14] = Hb_8b[3];
	d16[15] = Hb_8b[4];
 
	return B2D16(d16);
}

int B2D(int *v_8b)
{
	int value = 0;
	int temp = 1;
	for(int i=0;i<8;i++)
	{
		if(v_8b[i]==1) value += temp;
		temp *= 2;
	}
	return value;
}
#endif // DECODER_H_INCLUDED