#include <iostream>
#include <fstream>
#include <cstdlib>

#include "image.h"
#include "Correlation.h"

int main(int argc, char *argv[]) {

	std::cout << "Main called..." << std::endl;

	int N = 442;
	int M = 288;
	int Q = 255;

	// instantiate image objects
	ImageType image(N, M, Q);
	ImageType mask(83, 55, Q);

	char c1[] = "../images/Image.pgm";
	//char c1[f1.length() + 1];
	char c2[] = "../images/Pattern.pgm";
	//char c2[f2.length() + 1];
	char fileName[] = "Image";

	//readImage(c1, image);
	//readImage(c2, mask);
	//std::cout << "Test" << std::endl;
	Correlation(fileName, image, mask);

	return 0;
}
