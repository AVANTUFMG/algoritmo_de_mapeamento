#ifndef MISSAOMAPEAMETO_H_INCLUDED
#define MISSAOMAPEAMENTO_H_INCLUDED

#pragma once
#include "Poligono.h"

class MissaoMapeamento
{
private:
	Poligono areaMapeada;
	vector<Point> rota;
	int numeroDePontosDaRota;
	int modoDeMapeamento;

public:
	//MissaoMapeamento() {};
	MissaoMapeamento(Poligono mapa);
	void mostrarRota();

	//funcoes do modoDeMapeamento 1:
	double acharYMaximo();
	void gerarRota();
	void automatizarMatplot();

	//funcoes do modoDeMapeamento 2:

	//funcoes do modoDeMapeamento 3:

};

#endif //MISSAOMAPEAMENTO_H_INCLUDED