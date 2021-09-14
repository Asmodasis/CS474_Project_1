#include <iostream>
#include <fstream>
#include <cstdlib>

//#include "../include/image.h"
#include "../include/image.h"
#include "../include/ImageSampling.h"
/*
#include "../include/WriteImage.h"
int readImage(char fname[], ImageType& image);
int readImageHeader(char fname[], int& N, int& M, int& Q, bool& type);
int writeImage(char fname[], ImageType& image);
*/
int main(int argc, char *argv[]){

    std::cout << "Main called..." << std::endl;

    int N = 256;
    int M = 256;
    int Q = 255;

    ImageType img(N,M,Q);

    imageSampling("../images/peppers.pgm", img, 8);

}