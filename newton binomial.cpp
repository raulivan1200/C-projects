#include<iostream>
#include<bits/stdc++.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

//Funcion para los coeficientes de la piramide de Pascal
long  potenciaf(int base,int potencia){
	long indice;
	for(indice=1;potencia>0;potencia--){
		indice=indice*base;
	}
	return indice;
}

//Funcion para los coeficientes de cada variable elevada a la potencia
int combinaciones(int n,int k){
	int kn=n-k,fn=1,fk=1,fkn=1,resultado;
	for (int i=0;i<n;i++){
		fn=fn*(i+1);
	}
	for(int j=0;j<k;j++){
		fk=fk*(j+1);
	}
	for(int l=0;l<kn;l++){
		fkn=fkn*(l+1);
	}
	resultado=fn/(fk*fkn);
	return resultado;
}

//Inicio del programa
int main(){
	int x,y,xp,yp,pot,i,comb[15],c=0;
	long c1,c2,c3;
	cout<<"Bienvenido al programa del binomio de Newton";
	cout<<"\n\nIngresa el coeficiente de x (incluye signo si es negativo) y luego separado por ENTER, el indice que tiene la variable\n";
	cin>>x;
	cin>>xp;
	cout<<"\n\nIngresa el coeficiente de y (incluye signo si es negativo) y luego separado por ENTER, el indice que tiene la variable\n";
	cin>>y;
	cin>>yp;
	cout<<"\n\nIngresa la potencia a la que quieres elevar el binomio\n";
	cin>>pot;
	cout<<"\n\nCalculando combinaciones";
	cout<<"\nGenerando polinomio\n\n";
	
	//Desarrollo de las combinaciones (piramide de pascal)
	for (i=0;i<=pot;i++){
		if (c==0){
			comb[i]=combinaciones(pot,i);
			comb[pot-i]=comb[i];
				if (comb[i]==comb[i-1] or comb[i]==comb[i-2]){
					c=1;
				}
		}
		
		
	//Desarrollo de las potencias
		int xpt=(pot-i)*xp,ypt=i*yp;
		
	//Calculo de cada cociente a la potencia
		c1=potenciaf(x,pot-i);
		c2=potenciaf(y,i);
		c3=c1*c2;
		if(c3>=0){
			cout<<"+";
		}
			cout<<c3*comb[i]<<"x^"<<xpt<<"y^"<<ypt<<" ";
		}	
	cout<<"\n\n";
	system("pause");
	return 0;
}
