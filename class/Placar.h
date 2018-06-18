#ifndef PLACAR_H
#define PLACAR_H

#include <fstream>
#include <string>
#include "JogoException.h"

class Placar{
	private:
		std::string placar;
		std::ofstream salvarPlacar;
		std::ifstream recuperarPalcar;

	public:
		Placar();
		virtual~Placar();
	
	void salvarJogador(std::string jogador);
	std::string recuperarJogadores(void);

};


#endif
