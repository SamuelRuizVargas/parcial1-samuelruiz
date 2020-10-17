#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    //Variables para el DD
    int XoD, VxD, YoD, VyD, VoD, alpha, XD,YD;
    //Variables para el DO
    int XoO, VxO, YoO, VyO, VoO, beta,  XO,YO;
    //Variables generales
    float g=9.8, T=0, rD, diaD, periD, AcirD, rO, diaO, periO, AcirO;

    //Pidiendo datos
    cout<<"A continuacion ingrese las variables del canhon O."<<endl;
    cout<<"Ingrese la posicion inicial en X del canhon O: ";cin>>XoO;
    cout<<"Ingrese la posicion inicial en Y del canhon O: ";cin>>YoO;
    cout<<"Ingrese la velocidad inicial canhon O: ";cin>>VoO;
    cout<<"Ingrese el angulo desde el cual el canhon O disparo: ";cin>>beta;

    cout<<"A continuacion ingrese las variables del canhon D."<<endl;
    cout<<"Ingrese la posicion inicial en X del canhon D (tiene que ser mayor al del canhon O): ";cin>>XoD;
    while(XoD<XoO)
    {
        cout<<"Ingrese la posicion inicial en X del canhon D (tiene que ser menor al del canhon O): ";cin>>XoD;
    }
    cout<<"Ingrese la posicion inicial en Y del canhon D (tiene que ser mayor al del canhon O): ";cin>>YoD;
    while(YoD<YoO)
    {
        cout<<"Ingrese la posicion inicial en Y del canhon D (tiene que ser mayor al del canhon O): ";cin>>YoD;
    }
    cout<<"Ingrese la velocidad inicial canhon D: ";cin>>VoD;

    //Definicion de magnitudes fisicas
    VxO=VoO*cos(beta);
    VyO=VoO*sin(beta)-g*T;

    XO=XoO+VxO*T;
    YO=YoO+VyO*T-1/2*g*(T*T);

    int centroO[2]={XO, YO};

    rO=0.05;
    diaO=rO*2;
    periO=2*3.14159*rO;
    AcirO=3.14159*(rO*rO);

    while(YO>=YoD && XO>=XoD)
    {
        T++;
        XO=XoO+VxO*T;
        YO=YoO+VyO*T-1/2*g*(T*T);
    }
    if(YO==YoD && XO==XoD)
    {

    }





    //--------------------------------------------------------------
    VxD=VoD*cos(alpha);
    VyD=VoD*sin(alpha)-g*T;

    XD=XoD+VxD*(T-2);
    YD=YoD+VyD*(T-2)-1/2*g*((T-2)*(T-2));

    int centroD[2]={XD, YD};

    rD=0.025;
    diaD=rD*2;
    periD=2*3.14159*rD;
    AcirD=3.14159*(rD*rD);


    return 0;
}
