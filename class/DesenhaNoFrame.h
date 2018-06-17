#ifndef DESENHA_NO_FRAME_H
#define DESENHA_NO_FRAME_H
#include <list>

#include "opencv2/highgui.hpp" //
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"


class DesenhaNoFrame{
    private:
    
    public:
    DesenhaNoFrame();
    virtual~DesenhaNoFrame();

    void desenhaNoFrame(std::vector<cv::Rect>& faces, cv::Mat& frame, double escala);

};

#endif