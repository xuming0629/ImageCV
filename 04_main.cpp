#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat src;
    src = cv::imread("../data/lena.jpg");
    if (src.empty())
    {
        std::cout << "Could not load image ... " << std::endl;
        return -1;
    }


    //



    return 0;
}
