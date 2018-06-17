#ifndef DESENHA_NO_FRAME_H
#define DESENHA_NO_FRAME_H
#include <list>
#include <unistd.h>

#include "opencv2/highgui.hpp" //
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"

class DesenhaNoFrame{
    private:
    cv::Rect rectFace;
    int flag;   
    int auxX, auxY;
    int corB, corG, corR;
    int aleatorioX, aleatorioY;
    int pontuacao;
 
    public:
 
    DesenhaNoFrame();
    virtual~DesenhaNoFrame();
    std::string getPontuacao(void);

    void desenhaNoFrame(std::vector<cv::Rect> &faces, cv::Mat &frame, double escala);

};

#endif