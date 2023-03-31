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


    // 

    // Mat 对象
    #if 0
    //--------------------------------------------------
    cv::Mat dst;
    dst = cv::Mat(src.size(), src.type());
    dst = cv::Scalar(127, 0, 255);

    cv::namedWindow("test demo Mat1", cv::WINDOW_AUTOSIZE);
    cv::imshow("test demo Mat1", dst);

    //--------------------------------------------------
    #endif 

    #if 0

    // Mat copyTo()
    cv::Mat dst;
    src.copyTo(dst);

    cv::namedWindow("test demo copyTo", cv::WINDOW_AUTOSIZE);
    cv::imshow("test demo copyTo", dst);
    #endif
    //----------------------------------------------------
    cv::Mat dst;
    cv::cvtColor(src, dst, cv::COLOR_BGR2GRAY);
    std::cout << "input image channels : " << src.channels() << std::endl; 
    std::cout << "output image channels : " << dst.channels() << std::endl;


    int cols = src.cols;
    int rows = src.cols;

    std::cout << "rows = " << rows << "," << "cols = " << cols << std::endl;
 
    const uchar * firstRow = dst.ptr<uchar>(0);
    std::cout << "firist pixel value : " << (int)*firstRow << std::endl;


    cv::namedWindow("output", cv::WINDOW_AUTOSIZE);
    cv::imshow("output", dst);

    cv::Mat M(10, 10, CV_8UC3, cv::Scalar(0, 255, 127));

    std::cout << "M = " << std::endl <<  M << std::endl;

    // Mat 的复制 Mat B(A)
    // 完全复制 clone 和 cpoyTo

    // CV_8UC3 中的 8 表示每个通道占 8 位，U 表示无符号 C 表示 char 类型，3 表示通道数目是 3， 第 四个参数表示像素的的大小

    // 创建多维数组
    cv::Mat m1;
    m1.create(src.size(), src.type());
    m1 = cv::Scalar(0, 255, 0);


    cv::namedWindow("output m1", cv::WINDOW_AUTOSIZE);
    cv::imshow("output m1", m1);

    // 定义小数组

    cv::Mat kernel = (cv::Mat_<double>(3, 3)<<0, -1, 0, -1, 5, -1, 0, -1, 0);
    std::cout << "kernel = " << std::endl << kernel << std::endl;

    
    cv::Mat csrc;
    cv::filter2D(src, csrc, -1, kernel);
     cv::namedWindow("output csrc", cv::WINDOW_AUTOSIZE);
    cv::imshow("output csrc", csrc);

    cv::Mat m2 = cv::Mat::eye(2, 2, CV_8UC1);
    std::cout << "m2 = " <<std::endl << m2 << std::endl;


    cv::waitKey(0);



    return 0;
}
