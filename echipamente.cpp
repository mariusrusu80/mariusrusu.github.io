/* 
Rusu Marius 2018
Aplicatie care permite gestionarea unor echipamente:

Abstract Factory ne oferă o modalitate de a încapsula un grup de fabrici/ateliere individuale care au elemente comune

Participanti:
1. Produs Abstract – Echipament
2. ProdusConcret - Smartphone, Tableta, Laptop, PC
3. FabricaAbstractă – FabricaEchipament
4. FabricaConcretă – FabricaEchipamenteTactile, FabricaEchipamenteNetactile

*/

#include <iostream>
using namespace std;

//ProdusAbstract - clasa abstracta sau interfata care defineşte comportamentul general al resursei (obiectelor) ce va fi folosita de aplicatie.
class Echipament{
	public:
		Echipament(){
			id_=total_++;
		}
		virtual void verifica()=0;
	protected:
		int id_;
		static int total_;
};

//nr obiecte create
int Echipament::total_=0;

//ProdusConcret - clasă derivată din ProdusAbstract; corespunde celor tactile
class Smartphone : public Echipament{
	public:
		//furnizeaza implementarea pentru resursa specifică 
		void verifica(){
			cout<<"Smartphone : verificat"<<endl;
		}
};

//ProdusConcret - clasă derivată din ProdusAbstract; corespunde celor tactile
class Tableta : public Echipament{
	public:
		//furnizeaza implementarea pentru resursa specifică 
		void verifica(){
			cout<<"Tableta : verificat"<<endl;
		}

};

//ProdusConcret - clasă derivată din ProdusAbstract; corespunde celor netactile
class Laptop : public Echipament{
	public:
		//furnizeaza implementarea pentru resursa specifică 
		void verifica(){			
			cout<<"Laptop : verificat"<<endl;
		}

};

//ProdusConcret - clasă derivată din ProdusAbstract; corespunde celor netactile
class Pc : public Echipament{
	public:
		//furnizeaza implementarea pentru resursa specifică 
		void verifica(){
			cout<<"Pc : verificat"<<endl;
		}
};

//clasa abstractă definită pentru a oferi posibilitatea de a crea instanţe ale altor clase concrete
class FabricaEchipament{
	public:
		//declară o interfaţă pentru operaţiile de creare a obiectelor produs abstracte
		virtual Echipament* CreareEchipamentMic()=0;
		virtual Echipament* CreareEchipamentMare()=0;
};

//FabricaConcretă - clasa derivata din fabrica abstracta. 
class FabricaEchipamenteTactile : public FabricaEchipament{
	public:
		//Implementează operaţiile de creare a obiectelor concrete
		Echipament* CreareEchipamentMic(){
			return new Smartphone;
		}
		Echipament* CreareEchipamentMare(){
			return new Tableta;
		}
};

//FabricaConcretă - clasa derivata din fabrica abstracta. 
class FabricaEchipamenteNetactile : public FabricaEchipament{
	public:
		//Implementează operaţiile de creare a obiectelor concrete
		Echipament* CreareEchipamentMic(){
			return new Laptop;
		}
		Echipament* CreareEchipamentMare(){
			return new Pc;
		}
};


//ultimul participant, clientul , adica programul, functia main
int main(int argc, char** argv) {
	/*clientul foloseşte doar interfaţa declarată de clasele FabricaAbstracta şi ProdusAbstract, 
	adica FabricaEchipament si Echipament */

	//Avantaje:
	//Este posibilă schimbarea familiilor de produse - intre tactile si netactile
	//Consistenţa – şablonul discutat asigură ca aplicaţia să utilizeze la un moment dat obiecte dintr-o singură familie
	//Izolarea claselor concrete -> clientul manipulează instanţele prin interfeţe abstracte. Numele claselor produs_concret sunt izolate în implementarea clasei FabricaConcreta, astfel, acestea nu apar în codul clientului (ascunse de client).
	//Dezavantaje:
	//Dificultate în privinţa extinderii fabricilor abstracte în scopul producerii de noi tipuri de produse!
	//astfel, pt extindere trebuie modificata clasa abstracta dar şi subclaselor derivate (ex. CreareEchipamentFMare...).

	//FabricaEchipament* t=new FabricaEchipamenteNetactile;
	FabricaEchipament* t=new FabricaEchipamenteTactile;
	Echipament* echipament[3];
	echipament[1]=t->CreareEchipamentMic();
	echipament[2]=t->CreareEchipamentMare();
	echipament[3]=t->CreareEchipamentMic();
	//au fost create 3 obiecte, mic, mare, mic
	//daca sunt tactile: smartphone, tableta, smartphone
	//daca sunt netactile: laptop, pc, laptop
	//verificam:
	for(int i=1;i<=3;i++)
	{
		echipament[i]->verifica();
	}
	return 0;
}

