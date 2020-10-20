#include <iostream>
#include <math.h>

using namespace std;

float punt_dist(int, int, int, int);

int tiempo(int,int,int,float,float,float);

bool golpea(int,int,int,float,float,float);

int veloci(int,int,int,float,float,float);

int main()
{
    int d=600;
    float g=9.8, pi=3.14159;
    //para la ofensiva
    int hO=100, xO=0, yO=hO;
    float destO=0.05*d;
    //para la defensiva
    int hD=100, xD=d, yD= hD;
    float destD=0.025*d;
    //caracteristicas y cuialidades cuando golpea
    float anguO=50*pi/180, anguD=0;

    int tiempo_g= tiempo(yO,d, hD, anguO, destO, g);
    int velocidad_g= veloci(yO,d, hD, anguO, destO, g);
    int golpe= golpea(yO,d, hD, anguO, destO, g);
    if (golpe!=NULL)
    {
        cout<<"El canhon golpea al enemigo? "<<endl;
        if (golpe==true)
            cout<<"Si"<<endl;
        if (tiempo_g!=-1)
        cout<<"El tiempo en el que golpea es: "<<tiempo_g<<" s"<<endl;
        if (velocidad_g!=-1)
        cout<<"La velocidad con la que debe ir para golpear es: "<<velocidad_g<<" m/s"<<endl;
    }


    return 0;
}

float punt_dist(int x1, int y1, int x2, int y2)
{
    int resta1=x2-x1;
    int resta2=y2-y1;
    int resta1cuadrada=resta1*resta1;
    int resta2cuadrada=resta2*resta2;
    float result=sqrt(resta1cuadrada+resta2cuadrada);
    return result;
}

int tiempo(int yO, int d, int hD, float anguO, float destO, float g)
{
    bool golpea=false;
    int tiempo_g;
    for (int VoO=0; VoO<=100;VoO+=1)
    {
        float VxO = VoO*cos(anguO);
        float VyO = VoO*sin(anguO);
        for (int t=0;t<=1000;t++)
        {
            float x=VxO*t;
            float y=yO + VyO*t-(0.5*g*t*t);
            if(punt_dist(d, hD, x, y)<=destO)
            {
                golpea=true;
                tiempo_g=t;
                return tiempo_g;
            }
        }
    }
    return -1;
}

bool golpea(int yO, int d, int hD, float anguO, float destO, float g)
{
    bool golpea=false;
    for (int VoO=0; VoO<=100;VoO+=1)
    {
        float VxO = VoO*cos(anguO);
        float VyO = VoO*sin(anguO);
        for (int t=0;t<=1000;t++)
        {
            float x=VxO*t;
            float y=yO + VyO*t-(0.5*g*t*t);
            if(punt_dist(d, hD, x, y)<=destO)
            {
                golpea=true;
                return golpea;
            }
        }
    }
    return NULL;
}

int veloci(int yO, int d, int hD, float anguO, float destO, float g)
{
    bool golpea=false;
    for (int VoO=0; VoO<=100;VoO+=1)
    {
        int velocidad_g;
        float VxO = VoO*cos(anguO);
        float VyO = VoO*sin(anguO);
        for (int t=0;t<=1000;t++)
        {
            float x=VxO*t;
            float y=yO + VyO*t-(0.5*g*t*t);
            if(punt_dist(d, hD, x, y)<=destO)
            {
                golpea=true;
                velocidad_g=VoO;
                return velocidad_g;
            }
        }
    }
    return -1;
}
