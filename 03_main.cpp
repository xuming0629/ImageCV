#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>


int main()
{   
    std::cout << "+++++++++++" << std::endl;

    cv::Mat src, dst;

    src = cv::imread("../data/lena.jpg");
    if (src.empty())
    {
        std::cout << "Could not load iamge ... "<< std::endl;
        return -1;
    }
    cv::namedWindow("opencv demo", cv::WINDOW_AUTOSIZE);
    cv::imshow("opencv demo", src);

    int cols = (src.cols - 1) * src.channels(); // 列数

    int rows = src.rows;                  // 行数
    int offsetx = src.channels();         // 开始
    
    dst = cv::Mat::zeros(src.size(), src.type());

    for (int row=1; row<(rows-1); row++)
    {
        const uchar * current = src.ptr<uchar>(row);        // 当前行，中间行
        const uchar * previous = src.ptr<uchar>(row - 1);   // 上一行
        const uchar * next = src.ptr<uchar>(row + 1);       // 下一行
        
        uchar * output = dst.ptr<uchar>(row);
        for (int col=offsetx; col<cols; col++)
        {
            output[col] = cv::saturate_cast<uchar>(5 * current[col] - (current[col-offsetx] + current[col + offsetx] + previous[col] + next[col]));
        }
    }

    cv::namedWindow("opencv demo contrast", cv::WINDOW_AUTOSIZE);
    cv::imshow("opencv demo contrast", dst);

    cv::Mat kernel = (cv::Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    cv::filter2D(src, dst, src.depth(), kernel);

    cv::namedWindow("opencv demo filter2D", cv::WINDOW_AUTOSIZE);
    cv::imshow("opencv demo filter2D", dst);

    cv::waitKey(0);

    return 0;

}
