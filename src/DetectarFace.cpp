#include "DetectarFace.h"
    
DetectarFace::DetectarFace(){
    this->diretorioClassificador = "classificador/haarcascade_frontalface_alt.xml";
    
}

DetectarFace::DetectarFace(std::string diretorio){
    this->diretorioClassificador = diretorio;
}
    
DetectarFace::~DetectarFace(){

}

//Metodos    

std::vector<cv::Rect> DetectarFace::getFaces(cv::Mat& frame){
    std::vector<cv::Rect> faces;
    cv::Mat frameGray;
    
    if(!classificador.load(diretorioClassificador)){
        throw JogoException("Diretorio Nao encontrado: "+diretorioClassificador);
    
    }else{
        
        cv::cvtColor(frame, frameGray, COLOR_BGR2GRAY);
        cv::equalizeHist(frameGray, frameGray);

        classificador.detectMultiScale(frameGray, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, cv::Size(30, 30));
        
        //|CASCADE_FIND_BIGGEST_OBJECT
        //|CASCADE_DO_ROUGH_SEARCH
        
    }

    return faces;
}

    
