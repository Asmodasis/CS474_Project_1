#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>                                           // to_string
#include <vector>
#include <cstring>                                          // strcat
/*
#include "../include/image.h"
#include "../src/image.cpp"
#include "../src/WriteImage.cpp"
*/
#include "../src/ReadImage.cpp"
#include "../src/ReadImageHeader.cpp"

int imageSampling(char fname[], ImageType& image, int subSample){

    int i, j; 
    int M, N, Q, M_sub, N_sub, Q_sub;                       // mxnxq in the image is rows x columns x levels,
    bool type;
    int valOfPixel;                                         // the returned value for the pixel
    int M_count = 0, N_count = 0;

    //ImageType replaceImage;                                 // a new image to replace the old image
    
    readImageHeader(fname, N, M, Q, type);                  // read image header
    
    //ImageType image(N, M, Q);                               // allocate memory for the image array

    readImage(fname, image);                                // read image

                                                            // The size of the image after subsampling will be the rows/subsample x columns/subsample
    M_sub = M / subSample;
    N_sub = N / subSample;
    Q_sub = Q / subSample;

    ImageType replaceImage(N_sub, M_sub, Q_sub);            // allocate memory for the new sub sampled image

                                                            //loop through the rows and columns by the factor of the subsample
    for(i=0; i<N; i = i + subSample)                        // rows
        for(j=0; j<M; j = j + subSample) {                  // columns

            image.getPixelVal(i, j, valOfPixel);                
            replaceImage.setPixelVal(N_count, M_count, valOfPixel);

            N_count++;                                      // increment the count, this corresponds to the location of the new image
            M_count++;
        }
                                                            // write image
    std::vector<const char*> returnVec;
    returnVec.push_back("SubSample_");
    returnVec.push_back((const char *) subSample);
    //returnVec.push_back(static_cast<char*>(subSample));
    //std::string returnString = "SubSample_"+subSample+ std::string(fname);
    //char returnFileName[] = returnString;
    //char tmp = (char) subSample;
    //char returnString[] =  "SubSample_" + tmp + fname);
    //writeImage(returnFileName, replaceImage);                               

 return (1);
}