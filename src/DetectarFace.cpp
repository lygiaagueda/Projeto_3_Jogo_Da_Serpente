#include "DetectarFace.h"
    
DetectarFace::DetectarFace(){
    this->diretorioClassificador = "classificador/haarcascade_frontalface_alt.xml";
    
}
 
DetectarFace::~DetectarFace(){

}

//Metodos 
void DetectarFace::carregaClassificador(std::string diretorio){
    int flag;
    if(!diretorio.compare("0")){

        flag = classificador.load(diretorioClassificador);
        if(!flag){
                throw JogoException("Diretorio Nao encontrado: "+diretorioClassificador);
            }

    }else{
        
        flag=classificador.load(diretorio);
        if(!flag){
            throw JogoException("Diretorio Nao encontrado: "+diretorio);
        }
    }
}

std::vector<cv::Rect> DetectarFace::getFaces(cv::Mat& frame){
    std::vector<cv::Rect> faces;
    cv::Mat frameGray;
            
    cv::cvtColor(frame, frameGray, COLOR_BGR2GRAY);
    cv::equalizeHist(frameGray, frameGray);

    classificador.detectMultiScale(frameGray, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, cv::Size(30, 30));
    
    //|CASCADE_FIND_BIGGEST_OBJECT
    //|CASCADE_DO_ROUGH_SEARCH
    

    return faces;
}

    
