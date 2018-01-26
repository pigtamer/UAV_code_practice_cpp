#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

#include "utils.hpp" //it would be defined later.
using namespace std;    
using namespace cv;

bool VideoAPI::isOpened(){
    return capture.isOpened();
}

bool VideoAPI::isTerminated(){
    return FLAG_END_PROCESS;
}

bool VideoAPI::isProcessing(){
    return FLAG_CALLBACK;
}

bool VideoAPI::readNextFrame(cv::Mat& frame_in){
    return capture.read(frame_in);
}

void VideoAPI::setPlaybackSpeed(int delay_time){
    delay_between_frames = delay_time;
}

void VideoAPI::ifCallProcess(bool FLAG){
    FLAG_CALLBACK = FLAG;
}

void VideoAPI::terminateProcess(){
    FLAG_END_PROCESS = true;
}

void VideoAPI::setFrameProcessFunctionAs(void (*frameProcessCallback)(cv::Mat&, cv::Mat&)){
        framewise_process = frameProcessCallback;
}

bool VideoAPI::setVideoInput_FromCamera(){
    frame_num_now = 0;
    delay_between_frames = 1000/24;
    capture.release();
    capture =  cv::VideoCapture(0);
    return capture.isOpened();
}

bool VideoAPI::setVideoInput_FromFile(std::string input_filename){
    frame_num_now = 0;

    capture.release(); // release all existing capture objs.

    return capture.open(input_filename);
}

long VideoAPI::getFrameNumber(){
    return frame_num_now;
}

double VideoAPI::getFrameRate(){
    return capture.get(CV_CAP_PROP_FPS);
}

void VideoAPI::displayInput(std::string in_windowName){
    VideoAPI::NAME_WINDOW = in_windowName; // set private var "NAME_..._WINDOW"
    cv::namedWindow(NAME_WINDOW);
}

void VideoAPI::displayOutput(std::string out_windowName){
    VideoAPI::NAME_WINDOW = out_windowName;
    cv::namedWindow(NAME_WINDOW);
}

void VideoAPI::run(){
    cv::Mat frame_now;
    cv::Mat frame_out;

    if(!capture.isOpened()){return;}

    FLAG_END_PROCESS = false;

    while (!FLAG_END_PROCESS){
        if(!capture.read(frame_now))
            break;
        
        if (NAME_WINDOW.length() != 0)
            cv::imshow(NAME_WINDOW, frame_now);

        if (FLAG_CALLBACK){
            framewise_process(frame_now, frame_out);
            frame_num_now ++;
        }else{
            frame_out = frame_now;
        }

        if(NAME_WINDOW.length() != 0)
            cv::imshow(NAME_WINDOW, frame_out);
        
        if (delay_between_frames >= 0 && cv::waitKey(delay_between_frames) >= 0)
            terminateProcess();

        if (end_at_frame_num >= 0 && getFrameNumber() == end_at_frame_num)
            terminateProcess();
    }  
    
}





