#include "DesenhaNoFrame.h"

DesenhaNoFrame::DesenhaNoFrame(){

}
DesenhaNoFrame::~DesenhaNoFrame(){

}

void DesenhaNoFrame::desenhaNoFrame(std::vector<cv::Rect>& faces, cv::Mat& frame, double escala){
    size_t i;
    cv::Rect rectFace;
    //cv::Point  ponto;
    
    static int auxX = 0;
    static int auxY = 0;
    int color1 = 255;
    int color2 = 255;
    int color3 = 255;
    static int flag = 0;
    int aleatorioX = rand() % 500;
    int aleatorioY = rand() % 300;
 

    for(i = 0 ; i<faces.size(); i++){
        rectFace = faces[i];

        if( (!flag) || (auxX > (rectFace.x*escala) * 0.9) && (auxX + 50 < ((rectFace.x + rectFace.width-1)*escala) * 0.9) &&
            (auxY > (rectFace.y*escala) * 0.9) && (auxY + 50 < ((rectFace.y + rectFace.height-1)*escala) * 0.9))
        {
            auxX = aleatorioX;
            auxY = aleatorioY;
            flag++;
            color1 = rand()%256;
            color2 = rand()%256;
            color3 = rand()%256;
        }

    cv::rectangle(frame, cv::Point(auxX, auxY), cv::Point(auxX + 50, auxY + 50), 
                    cv::Scalar(color1, color2, color3), 3, 8, 0);

    }

}
