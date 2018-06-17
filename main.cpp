#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <iostream>
#include <exception>
#include <unistd.h>
#include <list>

#include "DetectarFace.h"
#include "DesenhaNoFrame.h"

using namespace std;
using namespace cv;


int main( int argc, const char** argv )
{
    std::vector<cv::Rect> faces;
    cv::VideoCapture capture;
    cv::Mat frame, frameDeSaida;
    
    DetectarFace detectar;
    DesenhaNoFrame desenhar;
   
   //carrega 
    try{
        detectar.carregaClassificador("classificador/haarcascade_frontalface_alt.xml");

    }catch(JogoException &jogo){
        std::cout<<jogo.what()<<endl;
        return -1;
    }
    
    // Inicia capitura do frame

    if(!capture.open(0)){
        cout << "Capture from camera #0 didn't work" << endl;
    }
    
    if( capture.isOpened() )
    {
        while(1){
			capture.read(frame);
            if(frame.empty()){
                break;
            }

            faces = detectar.getFaces(frame);
            desenhar.desenhaNoFrame(faces, frame, 1);            
            cv::imshow("COBRINHA GAME", frame);

            char c = (char)cv::waitKey(10);
            if( c == 27 || c == 'q' || c == 'Q' )
                break;
        }
    }

    return 0;
}

