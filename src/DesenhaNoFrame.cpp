#include "DesenhaNoFrame.h"

DesenhaNoFrame::DesenhaNoFrame(){
    flag = 0;   
    auxX = 0;
    auxY = 0;
    corB = 0;
    corG = 0;
    corR = 0;
    aleatorioX = 0;
    aleatorioY = 0;
 
}
DesenhaNoFrame::~DesenhaNoFrame(){

}

void DesenhaNoFrame::desenhaNoFrame(std::vector<cv::Rect> &faces, cv::Mat &frame, double escala){
    size_t i;
    
    //cv::Point  ponto;
    flag = 0;
    aleatorioX = rand() % 500;
    aleatorioY = rand() % 300;
 
    for(i = 0 ; i<faces.size(); i++){
        rectFace = faces[i];

        if( (!flag) || (auxX > (rectFace.x*escala) * 0.9) && (auxX + 50 < ((rectFace.x + rectFace.width-1)*escala) * 0.9) &&
            (auxY > (rectFace.y*escala) * 0.9) && (auxY + 50 < ((rectFace.y + rectFace.height-1)*escala) * 0.9))
        {
            auxX = aleatorioX;
            auxY = aleatorioY;
            flag++;
            corR = rand()%256;
            corG = rand()%256;
            corB = rand()%256;


        }
        cv::rectangle(frame, cv::Point(auxX, auxY), cv::Point(auxX + 50, auxY + 50), 
                        cv::Scalar(corB, corG, corR), 3, 8, 0);
 
    }

}
