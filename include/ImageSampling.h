#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>                                           // to_string
#include <vector>
#include <cstring>                                          // strcat

#include "../include/WriteImage.h"
#include "../include/ReadImage.h"
#include "../include/ReadImageHeader.h"

int imageSampling(char fname[], ImageType& image, int subSample){

    int i, j; 
    int M, N, Q, M_sub, N_sub, Q_sub;                       // mxnxq in the image is rows x columns x levels,
    bool type;
    int valOfPixel;                                         // the returned value for the pixel
    int M_count = 0, N_count = 0;

    readImageHeader(fname, N, M, Q, type);                  // read image header
    
    readImage(fname, image);                                // read image

                                                            // The size of the image after subsampling will be the rows/subsample x columns/subsample
    M_sub = M / subSample;
    N_sub = N / subSample;
    Q_sub = Q / subSample;

    ImageType replaceImage(N_sub, M_sub, Q_sub);            // allocate memory for the new sub sampled image

                                                            //loop through the rows and columns by the factor of the subsample
    for(i=0; i<N; i=i+subSample){                           // rows

        M_count=0;

        for(j=0; j<M; j=j+subSample) {                      // columns

            image.getPixelVal(i, j, valOfPixel);            // get the pixel value at the location jumped by subSample
             
                if( (i == 0) || (j == 0) ){                 // if it is the first element, count it since zero mod subsample is subsample

                replaceImage.setPixelVal(N_count, M_count, valOfPixel);
                    //TODO: This if statement may not be needed.                    
                M_count++;
                } else {                                    // else 
                    replaceImage.setPixelVal(N_count, M_count, valOfPixel);
                    M_count++;
                }
                
        }
      N_count++;
    }
                                                            // write image

    writeImage("../images/Subsample_8_peppers.pgm", replaceImage);                            

 return (1);
}