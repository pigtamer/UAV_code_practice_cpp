#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
const string IM_PATH = "X:/cvImg/";

int main(){
    Mat im = cv::imread(IM_PATH + "cross.jpg", CV_8UC1);
    int rows = im.rows;
    int cols = im.cols;
    int chans = im.channels(); // channels is func

    cout << rows <<";" << cols << ";" << chans << endl;

    imshow("new", im);
    Mat roi(im, cv::Rect(100, 100, 110, 110)); // coord: x, y, delX, delY.
    imshow("roi", roi);

    roi.copyTo(im(Rect(0, 0, roi.rows, roi.cols)));

    imshow("new1", im);
    waitKey(0);
    destroyAllWindows();
}