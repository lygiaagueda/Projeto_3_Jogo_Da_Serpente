#include "Placar.h"

Placar::Placar(){

}
Placar::~Placar(){

}

void Placar::salvarJogador(std::string jogador){
    salvarPlacar.open("dados/jogadores.dat", std::ios::out | std::ios::app);

    if(salvarPlacar.is_open()){
        throw JogoException("Não foi possivel abrir o arquivo para escrita!");
    }else{
       salvarPlacar << jogador << std::endl;
    }

    salvarPlacar.close();
}
std::string Placar::recuperarJogadores(void){
    std::string jogadorLido;
    placar.erase();

    recuperarPalcar.open("dados/jogadores.dat", std::ios::in);
    if(!recuperarPalcar.is_open()){
        throw JogoException("Não foi possivel abrir o Arquivo para leitura!");
    }

    while(!recuperarPalcar.eof()){
        
        std::getline(recuperarPalcar, jogadorLido);
        this->placar.append(jogadorLido);
        
    }
    
    recuperarPalcar.close();

    return placar;
}

