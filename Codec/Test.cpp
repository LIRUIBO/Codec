#include "Encoder.h"
#include "Decoder.h"
#include <ctime>
#include <cstdlib>

int main()
{
	// initialize
	cout << "The test of video encoding/decoding" << endl;
	int resolution = 640*480;
	int w = 65536;
	int np = 512;
	double *map = new double[3];
	int *array_before = new int [resolution];
	int *array_after = new int [resolution];
	srand(time(NULL));
	int rightnum = 0;

	// test
	int i;
	for(i=0;i<resolution;i++)
	{
		array_before[i] = rand()%w;
		//cout << array_before[i] << endl;
		encode(array_before[i],map,w,np);
//		for(int j=0;j<3;j++)
//			cout << map[j] << ' ';
//		cout << endl;
		array_after[i] = decode(map,w,np);
		//cout << "d = " << array_after[i] << endl;
		if(array_after[i]==array_before[i])
			rightnum++;
	}
	cout << "The accuracy is " << rightnum/resolution*100 << "%" << endl;
}