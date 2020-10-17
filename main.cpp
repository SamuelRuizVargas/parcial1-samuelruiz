#include <iostream>

using namespace std;

int main()
{
    //Variables para el DD
    int XoD, VxD, YoD, VyD, VoD, alpha, rD, diaD, periD, AcirD, XD,YD;
    //Variables para el DO
    int XoO, VxO, YoO, VyO, VoO, beta, rO, diaO, periO, AcirO, XO,YO;
    //Variables generales
    float g=9.8, T;


    cout<<"A continuacion ingrese las variables del canhon D."<<endl;
    cout<<"Ingrese la posicion inicial en X del canhon D: ";cin>>XoD;
    cout<<"Ingrese la posicion inicial en Y del canhon D: ";cin>>YoD;
    cout<<"Ingrese la velocidad inicial canhon D: ";cin>>VoD;
    cout<<"Ingrese el angulo desde el que se disparo el cañon canhon D: ";cin>>alpha;


    cout<<"A continuacion ingrese las variables del canhon O."<<endl;
    cout<<"Ingrese la posicion inicial en X del canhon O: ";cin>>XoO;
    cout<<"Ingrese la posicion inicial en Y del canhon O: ";cin>>YoO;
    cout<<"Ingrese la velocidad inicial canhon O: ";cin>>VoO;
    cout<<"Ingrese el angulo desde el cual el canhon O disparo: ";cin>>beta;
    cout<<"Ingrese el tiempo en el que dispararon: ";cin>>T;

    //Definicion de magnitudes fisicas
    VxD=VoD*cos()


    XD=XoD+VxD*(T-2);
    YD=YoD+VyD*(T-2)-1/2*g*((T-2)*(T-2));

    XO=XoO+VxO*T;
    YO=YoO+VyO*T-1/2*g*(T*T);

    //Definicion de los centros
    int centroD[2]={XD, YD}, centroO[2]={XO, YO};

    return 0;
}
