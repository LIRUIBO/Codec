#ifndef ENCODER_H_INCLUDED
#define ENCODER_H_INCLUDED
#include <math.h>
#include <iostream>
using namespace std;

// Decimal value to 8bit
void D2B(int *v_8b,int value);
int B2D16(int *b);

// Encoder
int encode(int *before, int *L_8b, int *Ha_8b, int *Hb_8b, int w,int np)
{
	float d_b = B2D16(before);
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
//	cout << L << ' ' << Lev << endl;
//	for(int j=0;j<8;j++)
//		cout << L_8b[j] << ' ';
//	cout << endl;
	
	// Ha
	j1 = fmod(L/(d_p/2),2);
	if(j1<=1)
		Ha = j1;
	else Ha = 2-j1;
	Haev = int(255*Ha+0.5);
	D2B(Ha_8b,Haev);
//	cout << Ha << ' ' << Haev << endl;
//	for(int j=0;j<8;j++)
//		cout << Ha_8b[j] << ' ';
//	cout << endl;

	//Hb
	j2 = fmod((L-d_p/4)/(d_p/2),2);
	if(j2<=1)
		Hb = j2;
	else Hb = 2-j2;
	Hbev = int(255*Hb+0.5);
	D2B(Hb_8b,Hbev);
//	cout << Hb << ' ' << Hbev << endl;
//	for(int j=0;j<8;j++)
//		cout << Hb_8b[j] << ' ';
//	cout << endl;

	return 0;
}

int encode_BIT1(int *before, int *L_8b, int *Ha_8b, int *Hb_8b, int w,int np)
{
	L_8b[0] = before[0];
	L_8b[1] = before[6];
	L_8b[2] = before[11];
	L_8b[3] = before[1];
	L_8b[4] = before[7];
	L_8b[5] = before[12];

	Ha_8b[0] = before[2];
	Ha_8b[1] = before[8];
	Ha_8b[2] = before[13];
	Ha_8b[3] = before[3];
	Ha_8b[4] = before[9];

	Hb_8b[0] = before[14];
	Hb_8b[1] = before[4];
	Hb_8b[2] = before[10];
	Hb_8b[3] = before[15];
	Hb_8b[4] = before[5];

	return 0;
}

int encode_BIT2(int *before, int *L_8b, int *Ha_8b, int *Hb_8b, int w,int np)
{
	L_8b[0] = before[0];
	L_8b[1] = before[1];
	L_8b[2] = before[2];
	L_8b[3] = before[3];
	L_8b[4] = before[4];
	L_8b[5] = before[5];

	Ha_8b[0] = before[6];
	Ha_8b[1] = before[7];
	Ha_8b[2] = before[8];
	Ha_8b[3] = before[9];
	Ha_8b[4] = before[10];

	Hb_8b[0] = before[11];
	Hb_8b[1] = before[12];
	Hb_8b[2] = before[13];
	Hb_8b[3] = before[14];
	Hb_8b[4] = before[15];

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

int B2D16(int *b)
{
	int res = 0;
	int temp = 1;
	for(int i=0;i<16;i++)
	{
		res += temp*b[i];
		temp *= 2;
	}
	return res;
}

#endif // ENCODER_H_INCLUDED