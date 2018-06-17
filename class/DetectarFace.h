#ifndef DETECTAR_FACE_H
#define DETECTAR_FACE_H
#include <string>
#include <list>

#include "JogoException.h"

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using cv::COLOR_BGR2GRAY;
using cv::CASCADE_SCALE_IMAGE;

class DetectarFace{
    private:
    cv::CascadeClassifier classificador;
    std::string diretorioClassificador;

    public:
    DetectarFace();
    virtual~DetectarFace();

    void carregaClassificador(std::string diretorio);
    std::vector<cv::Rect> getFaces(cv::Mat& frame);


};

#endif 