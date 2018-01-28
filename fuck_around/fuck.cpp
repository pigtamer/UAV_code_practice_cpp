#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int  main(){

    int WINDOW_SIZE[2]{480, 720}; // size of windows

    cv::Mat im = cv::imread("X:/cvImg/kobi.png");
    cv::Mat im_s;

    std::cout << "Original Size: " << im.size() << "\nMat.cols, the width of image: " << im.cols << "\nMat.rows, the height of image: " << im.rows << "\nMat.channels: " << im.channels() << endl;

    double scale_ratio = std::min(double(WINDOW_SIZE[0]) / double(im.rows) , double(WINDOW_SIZE[1] / double(im.cols)));

    cv::Size scaled_size = cv::Size(scale_ratio * im.cols, scale_ratio * im.rows);

    cv::resize(im, im_s, scaled_size);

    cv::imshow("fuck img", im);
    
    cv::imshow("fuck small img", im_s);


    cout << "Scaling Ratio: " << scale_ratio << "\nOriginal Size: " << im.size() << "\nNew Size: " << im_s.size() << "\nScaled size. Should be the same as New Size: " << scaled_size << endl;

    cv::waitKey(0);
    cv::destroyAllWindows();
    
}