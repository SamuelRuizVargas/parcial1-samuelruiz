#include <iostream>
#include <math.h>

using namespace std;

float punt_dist(int, int, int, int);

int tiempo(int,int,int,float,float,float);

bool golpea(int,int,int,float,float,float);

int veloci(int,int,int,float,float,float);

int tiempoD(int,int, int,float,float,float);

bool golpeaD(int,int,int,float,float,float);

int velociD(int,int,int,float,float,float);

int tiempo3(int,int,float,float,float,float);

bool golpea3(int,int,float,float,float,float);

int veloci3(int,int,float,float,float,float);

int main()
{
    char continuar=0;
    cout<<"Prueba de defensa"<<endl<<"Luego de que responda la siguiente informacion se le dira si el disparo va a acertar o no, luego de eso si el se le mostraran pruebas de distintos escenarios cambiando esas variables."<<endl;
    cout<<"NOTA: El programa tiene limites, por ejemplo no puede poner una distancia demasiado alta dispara de un angulo casi recto, intente que los datos sean parecidos a la realidad"<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    int d;
    cout<<"Ingrese la distancia en metros entre ambos canhones: ";cin>>d;
    while (d<0)
    {
        cout<<"La distancia debe ser mayor a 0"<<endl;
        cout<<"Ingrese la distancia en metros entre ambos canhones: ";cin>>d;
    }
    float g=9.8, pi=3.14159;
    //para la ofensiva
    int hO=0, xO=0, yO=hO;
    float destO=0.05*d;
    //para la defensiva
    int hD=0, xD=d, yD= hD;
    float destD=0.025*d;
    //caracteristicas y cuialidades cuando golpea
    float anguO, anguD=0;

    //datos para la simulacion inicial
    cout<<"ingrese el angulo desde el que se disparo el canhon ofensivo en grados (entre 1 y 89): ";cin>>anguO;
    while (anguO<1 or anguO>89)
    {
        cout<<"ingrese el angulo desde el que se disparo el canhon ofensivo en grados (entre 1 y 89): ";cin>>anguO;
    }
    anguO=anguO*pi/180;
    cout<<"Ingrese la altura a la que encuentra el canhon ofensivo en metros: ";cin>>hO;
    while (hO<0)
    {
        cout<<"Ingrese la altura a la que encuentra el canhon ofensivo en metros: ";cin>>hO;
    }
    cout<<"(el canhon defensivo siempre esta a la altura del suelo) "<<endl;
    cout<<"----------------------------------------------------------------"<<endl;

    int tiempo_g= tiempo(yO,d, hD, anguO, destO, g);
    int velocidad_g= veloci(yO,d, hD, anguO, destO, g);
    int golpe= golpea(yO,d, hD, anguO, destO, g);
    //se imprime el primer golpe con los datos
    if (golpe!=NULL)
    {
        cout<<"El canhon golpea al enemigo? "<<endl;
        if (golpe==true)
            cout<<"Si"<<endl;
        if (tiempo_g!=-1)
        cout<<"El tiempo en el que golpea es: "<<tiempo_g<<" s"<<endl;
        if (velocidad_g!=-1)
        cout<<"La velocidad con la que debe ir para golpear es: "<<velocidad_g<<" m/s"<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
    }
    else
    {
        cout<<"No es posible realizar un tiro desde ese angulo"<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
    }

    cout<<"Ingrese cualquier caracter para continuar: ";cin>>continuar;
    cout<<"----------------------------------------------------------------"<<endl;

    //punto 1). 3 o 4 ejemplos de tiros que pueden dar en el objetivo.
    {
    if (anguO!=55*pi/180)
    {
        for (int i=0;i<=50;i++)
        {
            cout<<endl;
        }
        cout<<"Punto #1 - Cambiando los angulos se pueden conseguir mas tiros que serian certeros: "<<endl;
        cout<<endl;
        cout<<"Con 55 grados: "<<endl;
        anguO=55*pi/180;
        tiempo_g= tiempo(yO,d, hD, anguO, destO, g);
        velocidad_g= veloci(yO,d, hD, anguO, destO, g);
        golpe= golpea(yO,d, hD, anguO, destO, g);
        if (golpe!=NULL)
        {
            cout<<"El canhon golpea al enemigo? "<<endl;
            if (golpe==true)
                cout<<"Si"<<endl;
            if (tiempo_g!=-1)
            cout<<"El tiempo en el que golpea es: "<<tiempo_g<<" s"<<endl;
            if (velocidad_g!=-1)
            cout<<"La velocidad con la que debe ir para golpear es: "<<velocidad_g<<" m/s"<<endl;
            cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
        }
        else
        {
            cout<<"No es posible realizar un tiro desde ese angulo"<<endl;
            cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
        }
    }
    if (anguO!=35*pi/180)
    {
        cout<<"Con 35 grados: "<<endl;
        anguO=35*pi/180;
        tiempo_g= tiempo(yO,d, hD, anguO, destO, g);
        velocidad_g= veloci(yO,d, hD, anguO, destO, g);
        golpe= golpea(yO,d, hD, anguO, destO, g);
        if (golpe!=NULL)
        {
            cout<<"El canhon golpea al enemigo? "<<endl;
            if (golpe==true)
                cout<<"Si"<<endl;
            if (tiempo_g!=-1)
            cout<<"El tiempo en el que golpea es: "<<tiempo_g<<" s"<<endl;
            if (velocidad_g!=-1)
            cout<<"La velocidad con la que debe ir para golpear es: "<<velocidad_g<<" m/s"<<endl;
            cout<<"----------------------------------------------------------------"<<endl;
        }
        else
        {
            cout<<"No es posible realizar un tiro desde ese angulo"<<endl;
            cout<<"----------------------------------------------------------------"<<endl;
        }
    }
    if (anguO!=45*pi/180)
    {
        cout<<"Con 45 grados: "<<endl;
        anguO=45*pi/180;
        tiempo_g= tiempo(yO,d, hD, anguO, destO, g);
        velocidad_g= veloci(yO,d, hD, anguO, destO, g);
        golpe= golpea(yO,d, hD, anguO, destO, g);
        if (golpe!=NULL)
        {
            cout<<"El canhon golpea al enemigo? "<<endl;
            if (golpe==true)
                cout<<"Si"<<endl;
            if (tiempo_g!=-1)
            cout<<"El tiempo en el que golpea es: "<<tiempo_g<<" s"<<endl;
            if (velocidad_g!=-1)
            cout<<"La velocidad con la que debe ir para golpear es: "<<velocidad_g<<" m/s"<<endl;
            cout<<"----------------------------------------------------------------"<<endl;
        }
        else
        {
            cout<<"No es posible realizar un tiro desde ese angulo"<<endl;
            cout<<"----------------------------------------------------------------"<<endl;
        }
    }
    if (anguO!=60*pi/180)
    {
        cout<<"Con 60 grados: "<<endl;
        anguO=60*pi/180;
        tiempo_g= tiempo(yO,d, hD, anguO, destO, g);
        velocidad_g= veloci(yO,d, hD, anguO, destO, g);
        golpe= golpea(yO,d, hD, anguO, destO, g);
        if (golpe!=NULL)
        {
            cout<<"El canhon golpea al enemigo? "<<endl;
            if (golpe==true)
                cout<<"Si"<<endl;
            if (tiempo_g!=-1)
            cout<<"El tiempo en el que golpea es: "<<tiempo_g<<" s"<<endl;
            if (velocidad_g!=-1)
            cout<<"La velocidad con la que debe ir para golpear es: "<<velocidad_g<<" m/s"<<endl;
            cout<<"----------------------------------------------------------------"<<endl;
        }
        else
        {
            cout<<"No es posible realizar un tiro desde ese angulo"<<endl;
            cout<<"----------------------------------------------------------------"<<endl;
        }
    }
    }
    cout<<"Ingrese cualquier caracter para continuar: ";cin>>continuar;
    cout<<"----------------------------------------------------------------"<<endl;
    //punto 2). 3 o 4 disparos que puedan dañar al ofensivo
    {
       for (int i=0;i<=50;i++)
            {
                cout<<endl;
            }
        cout<<"Punto #2 - Ahora se mostraran los 3 o 4 posibles disparos defensivos que dejen danhado al ofensivo"<<endl;
        if (anguD!=95*pi/180)
        {
            cout<<endl;
            cout<<"Con 95 grados: "<<endl;
            anguD=95*pi/180;
            tiempo_g= tiempoD(yD,hO, d,anguD, destD, g);
            velocidad_g= velociD(yD,hO, d,anguD, destD, g);
            golpe= golpeaD(yD,hO, d,anguD, destD, g);
            if (golpe!=NULL)
            {
                cout<<"El canhon golpea al enemigo? "<<endl;
                if (golpe==true)
                    cout<<"Si"<<endl;
                if (tiempo_g!=-1)
                cout<<"El tiempo en el que golpea es: "<<tiempo_g<<" s"<<endl;
                if (velocidad_g!=-1)
                cout<<"La velocidad con la que debe ir para golpear es: "<<velocidad_g<<" m/s"<<endl;
                cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
            }
            else
            {
                cout<<"No es posible realizar un tiro desde ese angulo"<<endl;
                cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
            }
        }
        if (anguD!=93*pi/180)
        {
            cout<<endl;
            cout<<"Con 93 grados: "<<endl;
            anguD=93*pi/180;
            tiempo_g= tiempoD(yD,hO, d,anguD, destD, g);
            velocidad_g= velociD(yD,hO, d,anguD, destD, g);
            golpe= golpeaD(yD,hO, d,anguD, destD, g);
            if (golpe!=NULL)
            {
                cout<<"El canhon golpea al enemigo? "<<endl;
                if (golpe==true)
                    cout<<"Si"<<endl;
                if (tiempo_g!=-1)
                cout<<"El tiempo en el que golpea es: "<<tiempo_g<<" s"<<endl;
                if (velocidad_g!=-1)
                cout<<"La velocidad con la que debe ir para golpear es: "<<velocidad_g<<" m/s"<<endl;
                cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
            }
            else
            {
                cout<<"No es posible realizar un tiro desde ese angulo"<<endl;
                cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
            }
        }
        if (anguD!=98*pi/180)
        {
            cout<<endl;
            cout<<"Con 98 grados: "<<endl;
            anguD=98*pi/180;
            tiempo_g= tiempoD(yD,hO, d,anguD, destD, g);
            velocidad_g= velociD(yD,hO, d,anguD, destD, g);
            golpe= golpeaD(yD,hO, d,anguD, destD, g);
            if (golpe!=NULL)
            {
                cout<<"El canhon golpea al enemigo? "<<endl;
                if (golpe==true)
                    cout<<"Si"<<endl;
                if (tiempo_g!=-1)
                cout<<"El tiempo en el que golpea es: "<<tiempo_g<<" s"<<endl;
                if (velocidad_g!=-1)
                cout<<"La velocidad con la que debe ir para golpear es: "<<velocidad_g<<" m/s"<<endl;
                cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
            }
            else
            {
                cout<<"No es posible realizar un tiro desde ese angulo"<<endl;
                cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
            }
        }
        if (anguD!=97*pi/180)
        {
            cout<<endl;
            cout<<"Con 97 grados: "<<endl;
            anguD=97*pi/180;
            tiempo_g= tiempoD(yD,hO, d,anguD, destD, g);
            velocidad_g= velociD(yD,hO, d,anguD, destD, g);
            golpe= golpeaD(yD,hO, d,anguD, destD, g);
            if (golpe!=NULL)
            {
                cout<<"El canhon golpea al enemigo? "<<endl;
                if (golpe==true)
                    cout<<"Si"<<endl;
                if (tiempo_g!=-1)
                cout<<"El tiempo en el que golpea es: "<<tiempo_g<<" s"<<endl;
                if (velocidad_g!=-1)
                cout<<"La velocidad con la que debe ir para golpear es: "<<velocidad_g<<" m/s"<<endl;
                cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
            }
            else
            {
                cout<<"No es posible realizar un tiro desde ese angulo"<<endl;
                cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
            }
        }
    }
    cout<<"Ingrese cualquier caracter para continuar: ";cin>>continuar;
    cout<<"----------------------------------------------------------------"<<endl;
    //punto 3). 3 o 4 disparos que defiendan sin importar el cañon ofensivo
    {
        for (int i=0;i<=50;i++)
            {
                cout<<endl;
            }
        cout<<"Punto #3 - Ahora se mostraran los 3 o 4 posibles disparos defensivos que destruyan el disparo ofensivo sin importar si lo daña"<<endl;
        cout<<endl;
        cout<<"Con 45 grados: "<<endl;
        anguO=45*pi/180;
        anguD=(180-90)*pi/180;
        tiempo_g= tiempo3(yD, d, anguD, destD, g, anguO);
        velocidad_g= veloci3(yD, d, anguD, destD, g, anguO);
        golpe= golpea3(yD, d, anguD, destD, g, anguO);
        if (golpe!=NULL)
        {
            cout<<"Las balas chocan? "<<endl;
            if (golpe==true)
                cout<<"Si"<<endl;
            if (tiempo_g!=-1)
            cout<<"El tiempo en el que se golpean es: "<<tiempo_g<<" s"<<endl;
            if (velocidad_g!=-1)
            cout<<"La velocidad con la que debe ir para golpear a la otra es: "<<velocidad_g<<" m/s"<<endl;
            cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
        }
        else
        {
            cout<<"No es posible realizar un tiro desde ese angulo"<<endl;
            cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
        }
    }
    cout<<"Ingrese cualquier caracter para continuar: ";cin>>continuar;
    cout<<"----------------------------------------------------------------"<<endl;

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

int tiempoD(int yD, int hO, int d, float anguD, float destD, float g)
{
    bool golpea=false;
    for (int VoO=0; VoO<=1000;VoO+=1)
    {
        int tiempo_g;
        float VxO = VoO*cos(anguD);
        float VyO = VoO*sin(anguD);
        for (int t=0;t<=10000;t++)
        {
            float x=d+VxO*t;
            float y=yD + VyO*t-(0.5*g*t*t);
            if(abs(punt_dist(0, hO, x, y))<=destD)
            {
                golpea=true;
                tiempo_g=t;
                return tiempo_g;
            }
        }
    }
    return -1;
}

bool golpeaD(int yD, int hO, int d, float anguD, float destD, float g)
{
    bool golpea=false;
    for (int VoO=0; VoO<=1000;VoO+=1)
    {
        float VxO = VoO*cos(anguD);
        float VyO = VoO*sin(anguD);
        for (int t=0;t<=10000;t++)
        {
            float x=d+VxO*t;
            float y=yD + VyO*t-(0.5*g*t*t);
            if(abs(punt_dist(0, hO, x, y))<=destD)
            {
                golpea=true;
                return golpea;
            }
        }
    }
    return NULL;
}

int velociD(int yD, int hO, int d, float anguD, float destD, float g)
{
    bool golpea=false;
    for (int VoO=0; VoO<=1000;VoO+=1)
    {
        int velocidad_g;
        float VxO = VoO*cos(anguD);
        float VyO = VoO*sin(anguD);
        for (int t=0;t<=10000;t++)
        {
            float x=d+VxO*t;
            float y=yD + VyO*t-(0.5*g*t*t);
            if(abs(punt_dist(0, hO, x, y))<=destD)
            {
                golpea=true;
                velocidad_g=VoO;
                return velocidad_g;
            }
        }
    }
    return -1;
}

int tiempo3(int yd, int d, float anguD, float destD, float g,float anguO)
{
    bool golpea=false;
    for (int VoO=1; VoO<=1000;VoO+=1)
    {
        int tiempo_g;
        float VxO = VoO*cos(anguO);
        float VyO = VoO*sin(anguO);
        float VxD = VoO*cos(anguD);
        float VyD = VoO*sin(anguD);
        for (int t=1;t<=10000;t++)
        {
            float xD=0;
             float yD=0;
            if (t>2)
            {
            float xD=d+VxD*t;
            float yD=VyD*t-(0.5*g*t*t);
            }
            float xO=VxO*t;
            float yO=yD+VyO*t-(0.5*g*t*t);
            if(abs(punt_dist(xD, yD, xO, yO))<=destD)
            {
                golpea=true;
                tiempo_g=t;
                return tiempo_g;
            }
        }
    }
    return  -1;
}

bool golpea3(int yd, int d, float anguD, float destD, float g,float anguO)
{
    bool golpea=false;
    for (int VoO=1; VoO<=1000;VoO+=1)
    {
        float VxO = VoO*cos(anguO);
        float VyO = VoO*sin(anguO);
        float VxD = VoO*cos(anguD);
        float VyD = VoO*sin(anguD);
        for (int t=1;t<=10000;t++)
        {
            float xD=0;
             float yD=0;
            if (t>2)
            {
            float xD=d+VxD*t;
            float yD=yd+VyD*t-(0.5*g*t*t);
            }
            float xO=VxO*t;
            float yO=yD+VyO*t-(0.5*g*t*t);
            if(abs(punt_dist(xD, yD, xO, yO))<=destD)
            {
                golpea=true;
                return golpea;
            }
        }
    }
    return  NULL;
}

int veloci3(int yd, int d, float anguD, float destD, float g,float anguO)
{
    bool golpea=false;
    for (int VoO=1; VoO<=1000;VoO+=1)
    {
        int velocidad_g;
        float VxO = VoO*cos(anguO);
        float VyO = VoO*sin(anguO);
        float VxD = VoO*cos(anguD);
        float VyD = VoO*sin(anguD);
        for (int t=1;t<=10000;t++)
        {
            float xD=0;
             float yD=0;
            if (t>2)
            {
            float xD=d+VxD*t;
            float yD=yd+VyD*t-(0.5*g*t*t);
            }
            float xO=VxO*t;
            float yO=yD+VyO*t-(0.5*g*t*t);
            if(abs(punt_dist(xD, yD, xO, yO))<=destD)
            {
                golpea=true;
                velocidad_g=t;
                return velocidad_g;
            }
        }
    }
    return  -1;
}
