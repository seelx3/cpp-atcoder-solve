#include <stdio.h>
#include <iostream>
#include <vector>
#include <complex>
using namespace std;
const double PI = acos(-1);

/**
 * @param coefs the sequence of coefficients
 * @param n the value for defining zeta
 * @param sgn the value for inv_FFT
 * 
 * @param zeta the n-th root of 1
 * @return the sequence of coefficients after FFT
 */
vector<complex<double>> FFT(vector<complex<double>> coefs, int n, int sgn = 1){
    if(n == 1) return coefs;

    vector<complex<double>> f0, f1;
    for(int i = 0; i < (n/2); i++) {
        f0.push_back(coefs[i*2 + 0]);
        f1.push_back(coefs[i*2 + 1]);
    }
    f0 = FFT(f0, n/2, sgn);
    f1 = FFT(f1, n/2, sgn);

    complex<double> zeta = complex<double>(cos(2.0*PI/n), sin(2.0*PI/n)*sgn);
    complex<double> pow_zeta = 1;

    for(int i = 0; i < n; i++) {
        coefs[i] = f0[i%(n/2)] + pow_zeta*f1[i%(n/2)];
        pow_zeta *= zeta;
    }

    return coefs;
}

/**
 * @param coefs the sequence of coefficients after FFT
 * @param n the value for defining zeta in FFT
 * 
 * @return the sequence of coefficients after inv_FFT
 */
vector<complex<double>> inv_FFT(vector<complex<double>> coefs, int n) {
	auto ret = FFT(coefs, n, -1);
	for (int i = 0; i < n; i++) {
		ret[i] /= n;
	}
	return ret;
}

/**
 * @brief Calculate the product of polynomials
 *
 * @param P1 the coefficients of the first polynomial
 * @param P2 the coefficients of the second polynomial
 */
vector<complex<double>> multiply(vector<complex<double>> &P1, vector<complex<double>> &P2) {
	int n = 1;
	while (n < (P1.size() + P2.size() + 1)) n *= 2;

	vector<complex<double>> ret;

	P1.resize(n), P2.resize(n);
	P1 = FFT(P1, n, 1);
	P2 = FFT(P2, n, 1);

	for (int i = 0; i < n; i++) {
		ret.push_back(P1[i] * P2[i]);
	}
	return inv_FFT(ret, n);
}

/**
 * @brief 
 *  input: sz_f0, sz_f1, f0, f1 
 *  (sz_f0, sz_f1: the size of f0, f1)
 *  (f0, f1: the coefficients of the polynomial)
 *  output: the product of f0 and f1
 */
int main(int argc, char const *argv[]){
    time_t clock_start, clock_end;
    clock_start = clock();
    int sz_f0, sz_f1;
    // cin >> sz_f0 >> sz_f1;
    sz_f0 = atoi(argv[1]);
    sz_f1 = atoi(argv[1]);
    vector<complex<double>> f0(sz_f0), f1(sz_f1);
    for(int i = 0; i < sz_f0; i++) {
        // int input; cin >> input;

        f0[i] = complex<double>(rand());
    }
    for(int i = 0; i < sz_f1; i++) {
        // double input; cin >> input;
        f1[i] = complex<double>(rand());
    }

    vector<complex<double>> multiply_ab = multiply(f0, f1);
    int sz_multi_ab = (sz_f0-1)+(sz_f1-1);
    for(int i = 0; i <= sz_multi_ab; i++){
        // cout << multiply_ab[i].real() << " \n"[i==sz_multi_ab];
    }
    clock_end = clock();
    cout << "time: " << (double)(clock_end-clock_start)/(double)(CLOCKS_PER_SEC) << endl;
}