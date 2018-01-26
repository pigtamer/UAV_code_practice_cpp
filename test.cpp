#include "utils.hpp"
// this is an example for canning a frame from file

// an example function., canny video frames.
void cannyit(cv::Mat& frame_in, cv::Mat& frame_out){
    size_t chans = frame_in.channels();
    cv::Mat im_in = frame_in;
    if (chans > 1){
        cv::cvtColor(frame_in, im_in, CV_BGR2GRAY);
    }
    Canny(frame_in, frame_out, 100, 200);
}


int main(){
    std::string DATASET_PATH = "D:/Proj/UAV/dataset/drones/Video_";
    std::string VIDEO_FORMAT = ".avi";
    std::string VIDEO_NUMBER = "11";

    // using video processor type
    VideoAPI vidProcessor;

    vidProcessor.setVideoInput_FromCamera(); // from camera

    // vidProcessor.setVideoInput_FromFile(DATASET_PATH + VIDEO_NUMBER + VIDEO_FORMAT);
    // vidProcessor.setPlaybackSpeed(1000./vidProcessor.getFrameRate()); // "1000." eqs to double(1000.0). FPS is measured in ms. FPS VALUE CAN ONLY BE USED ON PROCESSING FILES READ IN !!!!!!

    // vidProcessor.displayInput("in"); // cannnot show in two windows. still debugging.
    vidProcessor.displayOutput("out");    
    vidProcessor.ifCallProcess(true); // call framewise_process for each frame.
    vidProcessor.setFrameProcessFunctionAs(cannyit);
    vidProcessor.run();

    
}