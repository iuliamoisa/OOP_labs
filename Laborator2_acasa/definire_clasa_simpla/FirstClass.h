#pragma once
class FirstClass
{
/*
identificatori de acces :
	public: poate fi accesat de oriunde 
	private:nu poate fi apelat decat din interiorul clasei 
	protected: nu poate fi apelat din exterior, dar poate fi 
			apelat dintr-o clasa derivata


*/
private:
	int nota;
	char nume[20];
public: // settere si gettere 
	//setter pt nota:
	void setNota(int input);
	//getter pt nota:
//vedem de ce tip e atributul nota -> acesta va fi tipul functiei
	int getNota();
	void setNume(char* nume); //sau char nume[20]
	char* getNume();

};