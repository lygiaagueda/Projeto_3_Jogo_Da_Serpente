#ifndef CAPITURA_FRAME_H
#define CAPITURA_FRAME_H

#include "opencv2/highgui.hpp" //
#include "opencv2/imgproc.hpp"

#include "JogoException.h"

class CapituraFrame{
    private:
    cv::VideoCapture capitura;
    //cv::Mat frame;

    public:
    CapituraFrame();
    virtual~CapituraFrame();

    void getFrame(int flag, cv::Mat& frame);

};

#endif