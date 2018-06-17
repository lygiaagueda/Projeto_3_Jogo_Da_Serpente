#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <exception>
#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <ctime>
 
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
                capture >> frame;
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
    vector<Rect> faces;
    Scalar color = Scalar(255,0,0);
    Mat gray, smallImg;
    static int auxX = 0;
    static int auxY = 0;
    int color1 = 255;
    int color2 = 255;
    int color3 = 255;
    static int flag = 0;
    int aleatorioX = rand() % 500;
    int aleatorioY = rand() % 300;
 
    cvtColor( img, gray, COLOR_BGR2GRAY );
    double fx = 1 / scale;
    resize( gray, smallImg, Size(), fx, fx, INTER_LINEAR );
    equalizeHist( smallImg, smallImg );
 
    cascade.detectMultiScale( smallImg, faces,
        1.1, 2, 0
        //|CASCADE_FIND_BIGGEST_OBJECT
        //|CASCADE_DO_ROUGH_SEARCH
        |CASCADE_SCALE_IMAGE,
        Size(30, 30) );
 
    for ( size_t i = 0; i < faces.size(); i++ )
    {
        Rect r = faces[i];
        Point center;
 
        printf("xy face = %d x %d\n", r.x, r.y);
 
        // rectangle( img, cvPoint(cvRound(r.x*scale), cvRound(r.y*scale)),
        //            cvPoint(cvRound((r.x + r.width-1)*scale), cvRound((r.y + r.height-1)*scale)),
        //            color, 3, 8, 0);

        if( (!flag) ||
            (auxX > (r.x*scale) * 0.9) &&
            (auxX + 50 < ((r.x + r.width-1)*scale) * 0.9) &&
            (auxY > (r.y*scale) * 0.9) &&
            (auxY + 50 < ((r.y + r.height-1)*scale) * 0.9)
        ){
            auxX = aleatorioX;
            auxY = aleatorioY;
            flag++;
            color1 = rand()%256;
            color2 = rand()%256;
            color3 = rand()%256;
        }
 
    }

    
    cv::rectangle( img, cv::Point(auxX, auxY), cv::Point(auxX + 50, auxY + 50), Scalar(color1, color2, color3), 3, 8, 0);
    imshow( "Jogo da Serpente", img );
}