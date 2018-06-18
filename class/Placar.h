#ifndef PLACAR_H
#define PLACAR_H

#include <fstream>
#include <string>

class Placar{
	private:
		std::ofstream salvarPlacar;
		std::ifStream recuperarPalcar;

	public:
		Placar();
		virtual~Placar();
	
		void salvarPlacar(std::string placar);	
		std::string recuperarPlacar(void);

};


#endif
