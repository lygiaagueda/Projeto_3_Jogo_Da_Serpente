#include "JogoException.h"

JogoException::JogoException(){
    mensagem = "ERROR!";

}
JogoException::JogoException(std::string mensagem){
    this->mensagem = "ERROR: "+ mensagem;

}
JogoException::~JogoException(){

}


const char* JogoException::what(){
    return mensagem.c_str();
}