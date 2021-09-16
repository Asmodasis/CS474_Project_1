#include <iostream>
#include <fstream>
#include <cstdlib>

#include "../include/WriteImage.h"
#include "../include/ReadImage.h"
#include "../include/ReadImageHeader.h"

int imageQuantization(char fname[], ImageType& image, int L){
    
    int i, j; 
    int M, N, Q;                                            // mxnxq in the image is rows x columns x levels,
    int valOfPixel;                                         // the returned value for the pixel
    bool type;

    readImageHeader(fname, N, M, Q, type);                  // read image header
    
    readImage(fname, image);                                // read image

                                                            // The size of the image after subsampling will be the rows/subsample x columns/subsample
    

    ImageType replaceImage(N, M, L);                        // allocate memory for the new sub sampled image

                                                            //loop through the rows and columns by the factor of the subsample
    for(i=0; i<N; i++){                                     // rows


        for(j=0; j<M; j++) {                                // columns

            image.getPixelVal(i, j, valOfPixel);            // get the pixel value at the location jumped by subSample

            replaceImage.setPixelVal(i, j, valOfPixel);

        }
    }
                                                            // write image

    writeImage("../images/Quantization_240_lenna.pgm", replaceImage);                            

 return (1);

}