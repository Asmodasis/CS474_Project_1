#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>								// to_string
#include <cstring>								// strcat
#include <cmath>								// round
#include <numeric>								// accumulate

#include "image.h"
#include "WriteImage.h"
#include "ReadImage.h"
#include "ReadImageHeader.h"

void Correlation(char fname[], ImageType& image, ImageType& mask);
