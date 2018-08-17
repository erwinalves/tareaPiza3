#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int ConvierteANumero(string valor){   
	int n = atoi(valor.c_str()); 
    return n; 
}

bool esNumero(string valor){
	int aux = atoi(valor.c_str());
	if(aux==0){
		return false;
	}
	else{
		return true;
	}
}

void mostrarMatriz(int matriz[][9]){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<matriz[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(int argc, char* argv[]){
	int matriz[9][9];
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			matriz[i][j]=0;
	string pos_i=argv[1];
	string pos_j=argv[2];
	string num=argv[3];
	if(esNumero(pos_i) && esNumero(pos_j) && esNumero(num)){
		if(ConvierteANumero(pos_i)>=0 && ConvierteANumero(pos_i)<9){
			if(ConvierteANumero(pos_j)>=0 && ConvierteANumero(pos_j)<9){
				if(ConvierteANumero(num)>=1 && ConvierteANumero(num)<=9){
					matriz[ConvierteANumero(pos_i)][ConvierteANumero(pos_j)]=ConvierteANumero(num);
					mostrarMatriz(matriz);
				}
				else{
					cout<<"error de formato"<<endl;
				}
			}
			else{
				cout<<"error de formato"<<endl;
			}
		}
		else{
			cout<<"error de formato"<<endl;
		}
	}
	else{
		cout<<"error de formato"<<endl;
	}
}
