#include "Encoder.h"
#include "Decoder.h"
#include <ctime>
#include <cstdlib>

int main()
{
	// initialize
	cout << "The test of video encoding/decoding" << endl;
	int resolution = 1000;
	int w = 65536;
	int np = 512;
	int *array_before = new int [resolution];
	int *array_after = new int [resolution];
	srand(time(NULL));
	int rightnum = 0;

	// test
	int i;
	for(i=0;i<resolution;i++)
	{
		int L_8b[8] = {0,0,0,0,0,0,0,0};
		int Ha_8b[8] = {0,0,0,0,0,0,0,0};
		int Hb_8b[8] = {0,0,0,0,0,0,0,0};
		cout << endl << endl << "Begin test: " << endl;
		array_before[i] = rand()%w;
		cout << array_before[i] << endl;
		encode(array_before[i],L_8b,Ha_8b,Hb_8b,w,np);
		array_after[i] = decode(L_8b,Ha_8b,Hb_8b,w,np);
		cout << "d = " << array_after[i] << endl;
		if(array_after[i]==array_before[i]) rightnum++;
	}
	cout << "The accuracy is " << float(rightnum)/resolution*100 << "%" << endl;
}