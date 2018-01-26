#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

// #include "utils.hpp" //it would be defined later.
using namespace std;
using namespace cv;

//This is an empty class, reserved for extracting st-cube in a video sequence.
//stCube-wise processes in VideoAPI should be deisgned for this class.
class SpatioTemporalCude{
    private:
        bool foo;
    public:
        void bar();
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
        bool isOpened(){
            return capture.isOpened();
        }

        bool isTerminated(){
            return FLAG_END_PROCESS;
        }

        bool isProcessing(){
            return FLAG_CALLBACK;
        }

        bool readNextFrame(cv::Mat& frame_in){
            return capture.read(frame_in);
        }

        void setPlaybackSpeed(int delay_time){
            delay_between_frames = delay_time;
        }

        void ifCallProcess(bool FLAG){
            FLAG_CALLBACK = FLAG;
        }

        void terminateProcess(){
            FLAG_END_PROCESS = true;
        }

        void setFrameProcessFunctionAs(void (*frameProcessCallback)(cv::Mat&, cv::Mat&)){
                framewise_process = frameProcessCallback;
        }

        bool setVideoInput_FromCamera(){
            frame_num_now = 0;
            delay_between_frames = 0;
            capture.release();
            capture =  cv::VideoCapture(0);
            return capture.isOpened();
        }

        bool setVideoInput_FromFile(std::string input_filename){
            frame_num_now = 0;

            capture.release(); // release all existing capture objs.

            return capture.open(input_filename);
        }

        long getFrameNumber(){
            return frame_num_now;
        }

        double getFrameRate(){
            return capture.get(CV_CAP_PROP_FPS);
        }

        void displayInput(std::string in_windowName = "Input Frames"){
            VideoAPI::NAME_WINDOW = in_windowName; // set private var "NAME_..._WINDOW"
            cv::namedWindow(NAME_WINDOW);
        }

        void displayOutput(std::string out_windowName = "Output Frames"){
            VideoAPI::NAME_WINDOW = out_windowName;
            cv::namedWindow(NAME_WINDOW);
        }

        void run(){
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

        //end class: VideoAPI.
};


// an example function., canny video frames.
void cannyit(cv::Mat& frame_in, cv::Mat& frame_out){
    size_t chans = frame_in.channels();
    cv::Mat im_in = frame_in;
    if (chans > 1){
        cv::cvtColor(frame_in, im_in, CV_BGR2GRAY);
    }
    Canny(frame_in, frame_out, 100, 200);
}


// this is an example for canning a frame from file
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