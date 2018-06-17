#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <exception>
#include <unistd.h>

using namespace std;
using namespace cv;

void detectAndDraw( Mat& img, CascadeClassifier& cascade, double scale );

string cascadeName;

int main( int argc, const char** argv )
{
    VideoCapture capture;
    Mat frame;
    CascadeClassifier cascade;
    double scale;

    cascadeName       = "haarcascade_frontalface_alt.xml";
    scale = 1;

    if( !cascade.load( cascadeName ) )
    {
        cerr << "ERROR: Could not load classifier cascade" << endl;
        return -1;
    }
	
	try {
		if(!capture.open(0))
		    cout << "Capture from camera #0 didn't work" << endl;
    }
	catch(std::exception& e)
	{
		std::cout << " Excecao capturada open: " << e.what() << std::endl;
	}

    if( capture.isOpened() )
    {
        cout << "Video capturing has been started ..." << endl;

        for(;;)
        {
			try {
	            capture.read(frame);
			}
			catch (cv::Exception& e)
			{
				std::cout << " Excecao2 capturada frame: " << e.what() << std::endl;
				usleep(1000000);
				continue;
			}
			catch (std::exception& e)
			{
				std::cout << " Excecao3 capturada frame: " << e.what() << std::endl;
				usleep(1000000);
				continue;
			}

            if( frame.empty() )
                break;


		/*for (int m=0 ; m<400 ; m++) {
			//unsigned char * p = frame.ptr(m, m);
			p[0] = 255;
			p[1] = 0;
			p[2] = 0;
		}*/

            detectAndDraw( frame, cascade, scale );

            char c = (char)waitKey(10);
            if( c == 27 || c == 'q' || c == 'Q' )
                break;
        }
    }

    return 0;
}

void detectAndDraw( Mat& img, CascadeClassifier& cascade, double scale)
{
    vector<Rect> faces; // cia um vector de faces 
    Scalar color = Scalar(255,0,0); // cor azul
    Mat gray, smallImg; // duas matrizes que podem conter imagens

    cvtColor( img, gray, COLOR_BGR2GRAY ); // converte a imagem lida no frame para uma imagem em escala de cinza
    double fx = 1 / scale; // cordenada x
    resize( gray, smallImg, Size(), fx, fx, INTER_LINEAR ); // não sei o que sta funcao faz
    equalizeHist( smallImg, smallImg ); // nao sei o que esta função faz

    cascade.detectMultiScale( smallImg, faces,
        1.1, 2, 0
        //|CASCADE_FIND_BIGGEST_OBJECT
        //|CASCADE_DO_ROUGH_SEARCH
        |CASCADE_SCALE_IMAGE,
        Size(30, 30) ); // tecnica Haas cascade para dectar rostos na imagem (frame)

    for ( size_t i = 0; i < faces.size(); i++ )
    {
        Rect r = faces[i]; //paga as afaces que foram passadas para face e atribui umaa uma  em r
        Point center; // nao sei para que serve

		printf("xy face = %d x %d\n", r.x, r.y); // imprime as cordenadas x e y da imagem

        rectangle( img, cvPoint(cvRound(r.x*scale), cvRound(r.y*scale)),
                   cvPoint(cvRound((r.x + r.width-1)*scale), cvRound((r.y + r.height-1)*scale)),
                   color, 3, 8, 0);

    }
    imshow( "Jogo da Serpente", img );
}

