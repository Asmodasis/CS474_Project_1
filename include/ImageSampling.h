#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>                                           // to_string
#include <vector>
#include <cstring>                                          // strcat
/*
#include "../include/image.h"
#include "../src/image.cpp"
*/
#include "../include/WriteImage.h"
#include "../include/ReadImage.h"
#include "../include/ReadImageHeader.h"

int imageSampling(char fname[], ImageType& image, int subSample){

    int i, j; 
    int M, N, Q, M_sub, N_sub, Q_sub;                       // mxnxq in the image is rows x columns x levels,
    bool type;
    int valOfPixel;                                         // the returned value for the pixel
    int M_count = 0, N_count = 0;
std::cout << "1" << std::endl;
    //ImageType replaceImage;                                 // a new image to replace the old image
    
    readImageHeader(fname, N, M, Q, type);                  // read image header
    
    //ImageType image(N, M, Q);                               // allocate memory for the image array

    readImage(fname, image);                                // read image

                                                            // The size of the image after subsampling will be the rows/subsample x columns/subsample
    M_sub = M / subSample;
    N_sub = N / subSample;
    Q_sub = Q / subSample;
    std::cout << "M_sub == " << M<< std::endl;
    std::cout << "N_sub == " << N_sub<< std::endl;
    std::cout << "Q_sub == " << Q_sub<< std::endl;
    //std::cout << "2" << std::endl;
    ImageType replaceImage(N_sub, M_sub, Q_sub);            // allocate memory for the new sub sampled image
    int r, c, nel;
    replaceImage.getImageInfo(r,c,nel);
    std::cout << "REPLACEMENT IMAGE INFO" <<r<< " " <<c<< " " << nel  << std::endl;
    image.getImageInfo(r,c,nel);
    std::cout << "IMAGE INFO" <<r<< " " <<c<< " " << nel  << std::endl;
                                                            //loop through the rows and columns by the factor of the subsample
    for(i=0; i<N; i++)                                  // rows
        for(j=0; j<M; j++) {                                // columns
//std::cout << "4" << std::endl;
            image.getPixelVal(i, j, valOfPixel);                
                if( (N_count == 0) || (N_count == 1) ){
                replaceImage.setPixelVal(N_count, M_count, valOfPixel);
                std::cout << "value of pixel == " << valOfPixel  << std::endl;
                std::cout << "N_count == " <<N_count  << std::endl;
                std::cout << "M_count == " <<M_count  << std::endl;
                N_count++;                                      // increment the count, this corresponds to the location of the new image
                M_count++;
                } else if( (N_count % subSample == 0) ) {
                    replaceImage.setPixelVal(N_count, M_count, valOfPixel);
                    std::cout << "value of pixel == " << valOfPixel  << std::endl;
                    std::cout << "N_count == " <<N_count  << std::endl;
                    std::cout << "M_count == " <<M_count  << std::endl;
                    N_count++;                                      // increment the count, this corresponds to the location of the new image
                    M_count++;
                }
        }
                                                            // write image

    /*
    int sizeOfNewArray = 12 + sizeof(fname);                // Subsample_x_<fname>
    

    std::string s = "Subsample_" + std::to_string(subSample) + "_";
    char returnArray[sizeOfNewArray];
    std::strcpy(returnArray,s.c_str());

    for(int i = 13; i < sizeOfNewArray; i++){
        returnArray[i] = fname[i - 13];
       
    }
    */
    //returnVec.push_back(static_cast<char*>(subSample));
    //std::string returnString = "SubSample_"+subSample+ std::string(fname);
    //char returnFileName[] = returnString;
    //char tmp = (char) subSample;
    //char returnString[] =  "SubSample_" + tmp + fname);
    writeImage("../images/Subsample_2_lenna.pgm", replaceImage); 
    std::cout << "5" << std::endl;                              

 return (1);
}