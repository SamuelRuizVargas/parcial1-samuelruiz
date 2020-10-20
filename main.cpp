#include <iostream>
#include <math.h>

using namespace std;

float punt_dist(int, int, int, int);

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

    float anguO=50*pi/180, anguD=0;

    bool golpea=false;
    for (int VoO=0; VoO<=100;VoO+=1)
    {
        int VxO = VoO*cos(anguO);
        int VyO = VoO*sin(anguO);
        for (int t=0;t<=1000;t++)
        {
            int x=VxO*t;
            int y=yO + VyO*t-(0.5*g*t*t);
            if(punt_dist(d, hD, x, y)<=destO)
            {
                golpea=true;
                break;
            }
        }
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

