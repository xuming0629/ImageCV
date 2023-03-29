#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat src  = cv::imread("../data/lean.jpg", 0);
    if (src.empty())
    {
        std::cout << "Could not load iamge ..." << std::endl;
        return -1;
    }

    cv::namedWindow("opencv demo", cv::WINDOW_AUTOSIZE);
    cv::imshow("opencv demo", src);

    cv::waitKey(0);

    return 0;
    
}