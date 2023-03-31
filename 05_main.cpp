// c++ 读写图像，修改图像像素

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
    cv::namedWindow("test demo", cv::WINDOW_AUTOSIZE);
    cv::imshow("test demo", src);

    cv::Mat gray_src;
    cv::cvtColor(src, gray_src, cv::COLOR_BGR2GRAY);

    cv::namedWindow("test demo gray", cv::WINDOW_AUTOSIZE);
    cv::imshow("test demo gray", gray_src);


    int rows = gray_src.rows;
    int cols = gray_src.cols;

    for (int row=0; row<rows; row++)
    {
        for (int col=0; col<cols; col++)
        {
            int gray = gray_src.at<uchar>(row, col);
            gray_src.at<uchar>(row, col) = 255 - gray;

        }
    }

    cv::namedWindow("test demo gray_src", cv::WINDOW_AUTOSIZE);
    cv::imshow("test demo gray_src", gray_src);

    cv::waitKey(0);

    return 0;
}