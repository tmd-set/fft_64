//============================================================================
// Name        : fft64p_s.cpp
// Author      : Duc
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <complex>
using namespace std;

#define pi 3.14159265

typedef complex<double> dcmplx;

int main() {
	dcmplx 	x[64], //Day can bien doi
			F[64], //Ket qua bien doi
			G[64], //Bien doi cac phan tu chan
			H[64], //Bien doi cac phan tu le
			W[64], //He so
			j(0.,1.); //Don vi j = 0 + j
	int i,k,r,n,
			N = 64; //so diem can bien doi
	double t;

	cout << "FFT 64 point - Simple Algorithm" << endl;
	for (k = 0; k < N; k++) //Tao day x[] = [0:63]
	{
		x[k] = k;
	}
	for (k = 0; k < N; k++)
	{
		for (r = 0; r < N/2; r++)
		{
			G[k] += x[2*r]*exp(-2.0*j*pi*double(r)*double(k)/double(N/2));
			H[k] += x[2*r+1]*exp(-2.0*j*pi*double(r)*double(k)/double(N/2));
		}
		W[k] = exp(-j*2.0*pi*double(k)/double(N));
		//W[k].real() = cos(-2*pi*k/N);
		//W[k].imag() = sin(-2*pi*k/N);
		F[k] = G[k] + W[k] * H[k];
		cout << "F[" << k << "] = " << F[k] << endl;
	}
	return 0;
}
