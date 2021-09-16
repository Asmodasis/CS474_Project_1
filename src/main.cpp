#include <iostream>
#include <fstream>
#include <cstdlib>

//#include "../include/image.h"
#include "../include/image.h"
//#include "../include/ImageSampling.h"
#include "../include/ImageQuantization.h"


int main(int argc, char *argv[]){
   std::cout << "Main called..." << std::endl;

    int N = 256;
    int M = 256;
    int Q = 255;

    ImageType img(N,M,Q);

    //imageSampling("../images/peppers.pgm", img, 8);
    imageQuantization("../images/lenna.pgm", img, 240);
    return 0;

}
 
