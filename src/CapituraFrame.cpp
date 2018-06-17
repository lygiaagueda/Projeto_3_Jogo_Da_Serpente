#include "CapituraFrame.h"

CapituraFrame::CapituraFrame(){

}

CapituraFrame::~CapituraFrame(){

}


void CapituraFrame::getFrame(int flag, cv::Mat& frame){
    capitura.open(0);
    
    while(1){
        if(!capitura.isOpened()){
            throw JogoException("Nao foi possivel capiturar o frame");    
        
        }else if(!flag){
            break;

        }else{
            capitura.read(frame);
        }
    }
 
}

