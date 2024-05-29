#include <iostream>

#include "opencv2/opencv.hpp"
#include "libraw/libraw.h"

using namespace std;
using namespace cv;

int main() {

    string raw_path = "../test/test.dng";

    // step1. create image processor
    LibRaw myRawProcessor;

    // step2. open raw image file
    if (myRawProcessor.open_file(raw_path.c_str()) != LIBRAW_SUCCESS) {
        std::cout << "Open file fail" << std::endl;
    }

    // step3. unpack the raw data
    myRawProcessor.unpack();

    // step4. convert imgdata.rawdata to imgdata.image
    myRawProcessor.raw2image();

    // step5. get bayer pattern image
    cv::Mat bayer_image(myRawProcessor.imgdata.sizes.iheight,
                        myRawProcessor.imgdata.sizes.iwidth, CV_16UC1,
                        myRawProcessor.imgdata.rawdata.raw_image);

    // step6. convert to grayscale
    cv::Mat color_image, gray_image;
    cvtColor(bayer_image, color_image, cv::COLOR_BayerGB2BGR);
    cvtColor(color_image, gray_image, cv::COLOR_BGR2GRAY);

    // step7. output 
    imwrite("color_image.jpg", color_image);
    imwrite("gray_image.jpg", gray_image);
    return 0;
}
