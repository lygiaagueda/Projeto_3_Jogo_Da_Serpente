#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"


#include <iostream>
#include <exception>
#include <unistd.h>
#include <list>
#include <time.h>

#include "DetectarFace.h"
#include "DesenhaNoFrame.h"
#include "Placar.h"


using namespace std;
using namespace cv;



int main( int argc, const char** argv )
{
    // 
    char c = '0', op='0';
    float inst1=0, inst2=0;
    std::string jogador, placar;
    Mat flipped;
    Placar placarDeJogadores;
    std::vector<cv::Rect> faces;
    cv::VideoCapture capture;
    cv::Mat frame, frameDeSaida;


    //std::string textoJanela;

    DetectarFace detectar;
    DesenhaNoFrame desenhar;

    //placarDeJogadores.salvarJogador("asdsadsadsa");

   //carrega 
    try{
        detectar.carregaClassificador("classificador/haarcascade_frontalface_alt.xml");

    }catch(JogoException &jogo){
        std::cout<<jogo.what()<<endl;
        return -1;
    }
    
    // Inicia capitura do frame

    if(!capture.open(0)){
        cout << "Errror ao abrir a Camera!" << endl;
    }
    
    if(capture.isOpened())
    {
    
    while(1){
         // Jogo
        
        //bugado
        getchar();
        std::cout<<"Qual o seu Nome?"<<endl;
        std::getline(cin,jogador);

        std::cout<<"JOGAR OU VER PLACAR? j = jogar | p = Placar"<<std::endl;
        op=getchar(); 
       
        switch(op){ // swhitch do menu
        
            case 'j':
                
                desenhar.zeraPontuacao();

                inst1 = (float)clock()/(float)CLOCKS_PER_SEC;//marcacao inicial
                
                while(1){
                    inst2 = (float)clock()/(float)CLOCKS_PER_SEC;//marcacao final (sempre mudando)
                    
                    capture.read(frame);
                    flip(frame, flipped, 1);
                    
                    if((inst2-inst1>61)){
                        break;
                    }

                    if(frame.empty()){
                        break;
                    }

                    std::string tempo = "Tempo: " + to_string((int)(inst2-inst1));
                    
                    faces = detectar.getFaces(flipped);
                    desenhar.desenhaNoFrame(faces, flipped, 1, tempo);  
    
                    
                    cv::imshow("COBRINHA GAME", flipped);
                    //cv::putText(frame, teste, cv::Point(80, 50), FONT_HERSHEY_COMPLEX, 1, cv::Scalar(200, 50, 100), 1, LINE_AA);

                    ///cv::putText();
                    
                    c = (char)cv::waitKey(10);
                    if( c == 27 || c == 'q' || c == 'Q' ){
                        try{
                            placarDeJogadores.salvarJogador("NOME: "+jogador+"           |Pontuacao: "+desenhar.getPontuacao());

                        }catch(JogoException &jogo){
                            std::cout<<jogo.what()<<endl;
                        }

                        break;
                    }
                        
                }// fim do while

                //salva recorde do jogador
            

                    
                break;
            
            case 'p': // mostra o placar

                std::cout<<"NOME                    RECORDES"<<std::endl<<std::endl;
                
                try{
                    std::cout<<placarDeJogadores.recuperarJogadores();
                
                }catch(JogoException &jogo){
                    std::cout<<jogo.what()<<std::endl;

                }
            
                break;
            
            default:
            std::cout<<"Oopcao Invalida!"<<endl;
        }    
            


    }//loop menu

    //fim do jogo
    


    }

    return 0;
}

/*float inst1=0, inst2=0;

   inst1 = (float)clock()/(float)CLOCKS_PER_SEC;

   while (inst2-inst1<delay1) {
   		inst2 = (float)clock()/(float)CLOCKS_PER_SEC;
   		cout<<delay1-(inst2-inst1)<<endl;
   }
*/