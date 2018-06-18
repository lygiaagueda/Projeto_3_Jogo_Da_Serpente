#include "DesenhaNoFrame.h"

DesenhaNoFrame::DesenhaNoFrame(){
    //flag = 0;   
    auxX = 0;
    auxY = 0;
    corB = rand() % 256;
    corG = rand() % 256;
    corR = rand() % 256;
    aleatorioX = rand() % 500;
    aleatorioY = rand() % 500;
    pontuacao = 0;
 
}
DesenhaNoFrame::~DesenhaNoFrame(){

}
std::string DesenhaNoFrame::getPontuacao(void){
    return std::to_string(pontuacao);
}


void DesenhaNoFrame::desenhaNoFrame(std::vector<cv::Rect> &faces, cv::Mat &frame, double escala){
    size_t i;
    
    //cv::Point  ponto;
    //flag = 0;
 
    for(i = 0 ; i<faces.size(); i++){
        rectFace = faces[i];

         rectangle( frame, cvPoint(cvRound(rectFace.x*escala), cvRound(rectFace.y*escala)),
                    cvPoint(cvRound((rectFace.x + rectFace.width-1)*escala), 
                    cvRound((rectFace.y + rectFace.height-1)*escala)),
                    cv::Scalar(156, 200, 56), 3, 8, 0);

        if( (!flag) || (auxX > (rectFace.x*escala) * 0.9) && (auxX + 50 < ((rectFace.x + rectFace.width-1)*escala) * 0.9) &&
            (auxY > (rectFace.y*escala) * 0.9) && (auxY + 50 < ((rectFace.y + rectFace.height-1)*escala) * 0.9))
        {
            auxX=aleatorioX = rand() % 500;
            auxY=aleatorioY = rand() % 300;
            
            corR = rand()%256;
            corG = rand()%256;
            corB = rand()%256;
            flag++;
            
            pontuacao++;
            //std::cout<<"PONTUAÇOA :" << pontuacao << std::endl;
            //auxX = aleatorioX;
            //auxY = aleatorioY;

        }
 
    }

    cv::rectangle(frame, cv::Point(auxX, auxY), cv::Point(auxX + 50, auxY + 50), 
                cv::Scalar(corB, corG, corR), 3, 8, 0);

    std::string teste = "Pontos: " + std::to_string(pontuacao);
    cv::putText(frame, teste, cv::Point(20, 50), FONT_HERSHEY_COMPLEX, 1, cv::Scalar(200, 50, 100), 1, LINE_AA);

}
