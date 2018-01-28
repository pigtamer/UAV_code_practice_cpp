#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int  main(){

    int WINDOW_SIZE[2]{768, 1024}; // size of windows: (rows, cols) aka (height, width)

    cv::Mat im; // frame
    cv::Mat im_s; // resized frame

    cv::VideoCapture cap(0); // cap from cam
    cv::Size scaled_size; 

    double scale_ratio; // scaling ratio. 
    int delay = 24; // --- set delaying time here

    while (1){

        cap >> im;
        scale_ratio = std::min( double(WINDOW_SIZE[0]) / double(im.rows) , double(WINDOW_SIZE[1] / double(im.cols)) );
        
        scaled_size = cv::Size(scale_ratio * im.cols, scale_ratio * im.rows);
        
        cv::resize(im, im_s, scaled_size);
        
        cv::imshow("fuck img", im);
    
        cv::imshow("fuck resized img", im_s);

        if (cv::waitKey(delay) >= 0)            
            break;
    }

    cv::destroyAllWindows();
    
    std::cout << "Original Size: " << im.size() << "\nMat.cols, the width of image: " << im.cols << "\nMat.rows, the height of image: " << im.rows << "\nMat.channels: " << im.channels() << endl;

    cout << "Scaling Ratio: " << scale_ratio << "\nOriginal Size: " << im.size() << "\nNew Size: " << im_s.size() << "\nScaled size. Should be the same as New Size: " << scaled_size << endl;

    cv::waitKey(0);
    
}