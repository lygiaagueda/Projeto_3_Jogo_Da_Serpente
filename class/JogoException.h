#ifndef JOGO_EXCEPCION_H
#define JOGO_EXCEPCION_H
#include <exception>
#include <string>

class JogoException : public std::exception{
    private:
    std::string mensagem;

    public:
    JogoException();
    JogoException(std::string mensagem);
    virtual~JogoException() throw();
    
    const char* what();


};

#endif
