#include <iostream>
#include <cmath>

int main(void) {

	double vector[] = { 1., 2., 3., 4., 5. };
	int n = sizeof(vector) / sizeof(vector[0]);
    double x = n, ArithmeticMean, HarmonicMean, GeometricMean = 1.0, RootMeanSquare;

    // Arithmetic
    for (int i = 0; i < n; i++) ArithmeticMean += vector[i];
    ArithmeticMean /= n;

    // Harmonic
    for (int i = 0; i < n; i++) HarmonicMean += 1 / vector[i];
    HarmonicMean = n / HarmonicMean;

    // Geometric
    for (int i = 0; i < n; i++) GeometricMean *= vector[i];
    GeometricMean = pow(GeometricMean, 1/x);

    // RootMean Square
    for (int i = 0; i < n; i++) RootMeanSquare += pow(vector[i], 2);
    RootMeanSquare = sqrt(RootMeanSquare / x);

	std::cout << "Arithmetic Mean = " << ArithmeticMean << std::endl;
	std::cout << "Harmonic Mean   = " << HarmonicMean   << std::endl;
	std::cout << "Geometric Mean  = " << GeometricMean  << std::endl;
	std::cout << "RootMean Square = " << RootMeanSquare << std::endl;

	std::cout << std::endl;
	return 0;
}