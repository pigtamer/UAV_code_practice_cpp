#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

// #include "utils.hpp" //it would be defined later.
using namespace std;
using namespace cv;


//This is an empty class, reserved for extracting st-cube in a video sequence.
//stCube-wise processes in VideoAPI should be deisgned for this class.
//unfinished
class SpatioTemporalCude{
    private:    
        std::vector<cv::Mat> cubeContainer;
        cv::Mat* cubeContainer_array;
    public:
        int getSize();
        int setCube();
        SpatioTemporalCude(){};
        ~SpatioTemporalCude(){};    
};


class VideoAPI{
    private:
        cv::VideoCapture capture;
        
        void (*framewise_process) (cv::Mat& frame_in, cv::Mat& frame_out);

        void (*stCube_process) (SpatioTemporalCude& stCube_in, cv::Rect targetArea);

        bool FLAG_CALLBACK;

        string NAME_WINDOW;
        
        int delay_between_frames;

        long frame_num_now;

        long end_at_frame_num;

        bool FLAG_END_PROCESS;

    public:
        bool isOpened();

        bool isTerminated();

        bool isProcessing();

        bool readNextFrame(cv::Mat& frame_in);

        void setPlaybackSpeed(int delay_time);

        void ifCallProcess(bool FLAG);

        void terminateProcess();

        void setFrameProcessFunctionAs(void (*frameProcessCallback)(cv::Mat&, cv::Mat&));

        bool setVideoInput_FromCamera();

        bool setVideoInput_FromFile(std::string input_filename);

        long getFrameNumber();
        
        double getFrameRate();

        void displayInput(std::string in_windowName = "Input Frames");

        void displayOutput(std::string out_windowName = "Output Frames");

        void run();

        //end class: VideoAPI.
};


#endif