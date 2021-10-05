#include "Correlation.h"


/**
 * This function equalizes a source image, prints histogram values in comma-delimited
 * format, and writes another image after equalization.
 * @param: fname character array to write image, image ImageType reference,
 * existing pr double array to access the probabilities of each gray level
 * @return: none
 */
void Correlation(char fname[], ImageType& image, ImageType& mask) {
	
	// Step 1: Find the center of the filter 
	// Step 2: Locate the offset, a 3x3 filter will have an offset of 1 (from 0) for example
	// Step 3: add padding equal to the offset of all sides of the image
	// Step 4: align center of filter to the edge of the origal image (newimage[0+offset][0+offset])
	// Step 5: shift the filter along the new image and compute the correlation
	// Step 6: Spatial filtering turns every pixel into a function of it's values and it's neigbors
	//			The weights will be input into the program, 
	
	
	
	// orignal image properties
	int N, M, Q, value;
	int maskRow, maskCol, maskLevel, maskValue, rowOffset, colOffset;
	bool type, maskType;


	std::string oldfname = "../images/" + std::string(fname) + ".pgm";
	char oldImageFile[oldfname.length() + 1];
	std::strcpy(oldImageFile, oldfname.c_str());

	std::string oldMaskName = "../images/Pattern.pgm";
	char maskName[oldMaskName.length() + 1];
	std::strcpy(maskName, oldMaskName.c_str());

	readImageHeader(oldImageFile, N, M, Q, type);
	readImageHeader(maskName, maskRow, maskCol, maskLevel, maskType);


	//image.setImageInfo(N, M, Q);

	//mask.getImageInfo(maskRow, maskCol, maskLevel);					// the mask is an image to which spatial filtering is applied

	
	readImage(oldImageFile, image);

	//readImageHeader(maskName, maskRow, maskCol, maskValue, maskType);
	//readImage(maskName, mask);

	// the rows and the cols of the mask don't have to be equal (the mask is an image), so the testing is done independently 
	/*if(maskRow % 2 == 0){
		rowOffset = (maskRow) / 2;									// even
	}else{
		rowOffset = (maskRow - 1) / 2;								// odd
	}
	if(maskCol % 2 == 0){
		colOffset = (maskCol) / 2;									// even
	}else{
		colOffset = (maskCol - 1) / 2;								// odd
	}
	rowOffset = (maskRow - 1) / 2;	// The filters are always odd? TODO: Confirm this.
	colOffset = (maskCol - 1) / 2;
	
	int padSizeRow = N+(rowOffset*2);
	int padSizeCol = M+(colOffset*2);
	ImageType paddedImage(padSizeRow, padSizeCol, Q);				// The size of the new image is padded with the offset of the filter on all (borders) sides 
std::cout << "Test 1" << std::endl;
	for(int i = 0; i <padSizeRow; ++i){
		for(int j = 0; j < padSizeCol; ++j){
			paddedImage.setPixelVal(i, j, 0);						// initialize the whole image with padding 
		}
	}
std::cout << "Test 2" << std::endl;
	for(int i = rowOffset+1; i < N; ++i){
		for(int j = colOffset+1; j < M; ++j){
			image.getPixelVal(i, j, value);
			paddedImage.setPixelVal(i, j, value);					// add the values from the original image into the padded image					
		}
	}
std::cout << "Test 3" << std::endl;
	ImageType correlatedImage(N, M, Q);								// the resulting image after correlation is computed
	int correlatedSum = 0;

	for(int i = 0; i < N; ++i){										// loop through the original image
		for(int j = 0; j < M; ++j){
			for(int k = 0; k < (rowOffset*2)+1; ++k){				// loop through the mask
				for(int l = 0; l < (colOffset*2)+1; ++l){
					paddedImage.getPixelVal(k, l, value);
					mask.getPixelVal(k, l, maskValue);
					correlatedSum += (int) std::pow( 2.0 , (value - maskValue));
																	// sum up the differences of squares to match the mask with the image. 
				}
			}
			//correlatedImage.setPixelVal(i, j, correlatedSum);
			//correlatedSum = 0;
		}
	}
std::cout << "Test 4" << std::endl;
	// equalized file names and writing
	std::string newfname = "../images/" + std::string(fname) + "_correlated.pgm";
	char newImageFile[newfname.length() + 1];
	strcpy(newImageFile, newfname.c_str());
	writeImage(newImageFile, correlatedImage); */
}
