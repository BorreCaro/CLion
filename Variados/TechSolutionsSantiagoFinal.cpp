#include<iostream>
#include<vector>
#include<windows.h>
#include<iomanip>
#include<cstdlib>
#include<sstream>
#include<limits>
using namespace std;

void registro(int N, vector<long>& identificaciones, vector<int>& edad, vector<int>& nivel_ac, vector<int>& exp_lab, vector<int>& puntaje_pt, vector<int>& puntaje_e, vector<string>& nombres);
int puntaje_aspi(int j, int N, const vector<int>& nivel_ac, const vector<int>& exp_lab, const vector<int>& puntaje_pt, const vector<int>& puntaje_e, int &pna, int &pae, int &ppt, int &pe, float &suma);
void reportes(int N, vector<long> identificaciones, vector<int> edad, vector<int> nivel_ac, vector<int> exp_lab, vector<int> puntaje_pt, vector<int> puntaje_e, vector<int> puntaje_max, vector<string> nombres, float suma, string nivel_academico[]);
void listado(int N, const vector<string>& nombres, const vector<long>& identificaciones, const vector<int>& edad, const vector<int>& nivel_ac, const vector<int>& exp_lab, const vector<int>& puntaje_pt, const vector<int>& puntaje_e, vector<int> puntaje_max, string nivel_academico[]);
void ordenado(int N, vector<string> nombres, vector<long> identificaciones, vector<int> edad, vector<int> nivel_ac, vector<int> exp_lab, vector<int> puntaje_pt, vector<int> puntaje_e, vector<int> puntaje_max, float suma, string nivel_academico[]);
void consulta(int N, vector<string> nombres, vector<long> identificaciones, vector<int> edad, vector<int> nivel_ac, vector<int> exp_lab, vector<int> puntaje_pt, vector<int> puntaje_e, vector<int> puntaje_max, string nivel_academico[]);

void gotoxy(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon,dwPos);
}

void printCentrado(string texto, int y) {
    // Obtener tamaño de la consola
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int ancho_consola = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    // Calcular posición x para centrar
    int x = (ancho_consola - texto.length()) / 2;

    // Mover cursor y imprimir
    gotoxy(x, y);
    cout << texto;
}

void limpiarLinea(int y) {
    gotoxy(0, y);
    cout << string(150, ' ');
    gotoxy(0, y);
}

int main()
{

    SetConsoleOutputCP(65001);

    int N, opcion=0, puntaje_maximo=0, pna=0, pae=0, ppt=0, pe=0, x1=0, y1=0, q=0;
    float suma=0;
    bool valid=true;

    cout<<"Por favor antes de seguir con la ejecucion del programa, se agradeceria que lo colocara en pantalla completa"<<endl;
    system("pause");
    system("cls");

    printCentrado("Presione Enter para continuar", 25);
    gotoxy(100, 26); cin.get();
    system("cls");

    printCentrado("Bienvenido a TechSolutions", 5);
    printCentrado("Ingrese el numero de aspirante: ", 6);
    gotoxy(100, 7); cin>>N;

    while (N<=0)
    {
        limpiarLinea(7);
        printCentrado("Por favor ingrese un numero valido de aspirantes", 4);
        printCentrado("Bienvenido a TechSolutions", 5);
        printCentrado("Ingrese el numero de aspirante: ", 6);
        gotoxy(100, 7); cin>>N;
    }

    vector<string> nombres(N);
    vector<long> identificaciones(N);
    vector<int> edad(N);
    vector<int> nivel_ac(N);
    vector<int> exp_lab(N);
    vector<int> puntaje_pt(N);
    vector<int> puntaje_e(N);
    vector<int> puntaje_max(N);
    string nivel_academico[4]={"Tecnico", "Tecnologo", "Profesional", "Posgrado"};

    int *x=&nivel_ac[0];

    printCentrado("Gracias por la informacion :)", 15);
    printCentrado("Presione Enter para continuar", 16);
    cin.ignore();
    gotoxy(100, 17); cin.get();
    system("cls");

    do
    {
        printCentrado("TechSolutions S.A", 3);
        printCentrado("1. Registro de datos aspirantes",4);
        printCentrado("2. Calculo del puntaje total",5);
        printCentrado("3. Reportes y Consultas",6);
        printCentrado("4. Salir",7);
        gotoxy(100, 9); cin>>opcion;

        if ((q==0)&&(opcion==2 || opcion==3)) valid=false;

        //Validacion del menu
        while (((opcion<1)||(opcion>4))||(!valid))
        {
            system("cls");
            if (!valid) printCentrado("Para acceder a los reportes y puntaje de los aspirantes primero tiene que registrar los datos", 2);
            else printCentrado("Por favor ingrese una opcion valida", 2);
            valid=true;
            printCentrado("TechSolutions S.A", 3);
            printCentrado("1. Registro de datos aspirantes",4);
            printCentrado("2. Calculo del puntaje total",5);
            printCentrado("3. Reportes y Consultas",6);
            printCentrado("4. Salir",7);
            gotoxy(100, 9); cin>>opcion;
            if ((q==0)&&(opcion==2 || opcion==3)) valid=false;
        }



        printCentrado("Presione Enter para continuar", 20);
        gotoxy(100, 26); cin.get();
        system("cls");

        switch (opcion)
        {
        case 1: registro(N, identificaciones, edad, nivel_ac, exp_lab, puntaje_pt, puntaje_e, nombres); break;
        case 2:
            {
                stringstream ss;
                printCentrado("Puntaje total por aspirante", 3);
                printCentrado("Aqui se va a mostrar el puntaje en cada area y el total", 4);

                x=&nivel_ac[0];

                x1=20;
                y1=10;

                gotoxy(x1, y1++); cout<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<endl;
                gotoxy(x1, y1++); cout<<"| "<<left<<setw(19)<<"Aspirante"<<"| "<<setw(19)<<"Nombre"<<"| "<<setw(19)<<"Nivel Academico"<<"| "<<setw(19)<<"Años de Experiencia"<<"| "<<setw(19)<<"Prueba Tecnica"<<"| "<<setw(19)<<"Entrevista"<<"| "<<setw(19)<< "Total"<<"|"<<endl;
                gotoxy(x1, y1++); cout<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<endl;

                for (int j=0;x<=&nivel_ac[N-1]; x++, j++)
                {
                    puntaje_maximo=puntaje_aspi(j, N, nivel_ac, exp_lab, puntaje_pt, puntaje_e, pna, pae, ppt, pe, suma);
                    puntaje_max[j]=puntaje_maximo;
                    gotoxy(x1, y1++); cout<<"| "<<left<<setw(19)<<j+1<<"| "<<left<<setw(19)<<nombres[j]<<"| "<<setw(19)<<pna<<"| "<<setw(19)<<pae<<"| "<<setw(19)<<ppt<<"| "<<setw(19)<<pe<<"| "<<setw(19)<<puntaje_max[j]<<"| "<<endl;
                    printCentrado("Se calculo el puntaje con exito", 40);
                    printCentrado("Presiona enter para continuar", 41);
                    gotoxy(100, 42); cin.get();
                }

                gotoxy(x1, y1++); cout<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<endl;

                printCentrado("Presione Enter para continuar", 41);
                gotoxy(100, 42); cin.get();
                system("cls");
            }
            break;

        case 3: reportes(N, identificaciones, edad, nivel_ac, exp_lab, puntaje_pt, puntaje_e, puntaje_max, nombres, suma, nivel_academico); break;

        }

        q++;

    }while (opcion!=4);

    system("pause");

}

void registro(const int N, vector<long>& identificaciones, vector<int>& edad, vector<int>& nivel_ac, vector<int>& exp_lab, vector<int>& puntaje_pt, vector<int>& puntaje_e, vector<string>& nombres)
{

    int *p=&edad[0];
    long aux=0;

    printCentrado("Bienvenido al registro de datos", 3);
    for (int i=0; p<=&edad[N-1]; p++, i++)
    {
        stringstream ss;
        ss<<"Aspirante #"<<i+1<<": ";
        printCentrado(ss.str(),4);

        if (i>0)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        printCentrado("Nombre: ",6);
        gotoxy(100, 7); getline(cin, nombres[i]);

        printCentrado("Identificacion: ", 10);
        gotoxy(100, 11); cin>>aux;

        while (aux<0)
        {
            limpiarLinea(11);
            printCentrado("Identificacion invalida", 9);
            printCentrado("Identificacion: ", 10);
            gotoxy(100, 11); cin>>aux;
        }
        if (i>0)
        {
            bool duplicado=true;

            while (duplicado)
            {
                duplicado=false;

                long *q=&identificaciones[i-1];

                for (; q>=&identificaciones[0]; q--)
                {
                    if (*q==aux)
                    {
                        duplicado=true;
                        limpiarLinea(11);
                        printCentrado("La identificacion registrada es igual a la de otro aspirante, por favor verifique e ingrese nuevamente la identificacion: ", 9);
                        gotoxy(100, 11); cin>>aux;
                        break;
                    }
                }
            }
        }

        identificaciones[i]=aux;

        printCentrado("Edad: ", 14);
        gotoxy(100, 15); cin>>edad[i];

        while ((edad[i]<18)||(edad[i]>70))
        {
            limpiarLinea(15);
            printCentrado("Ingresa una edad entre 18 y 70: ", 13);
            printCentrado("Edad: ", 14);
            gotoxy(100, 15); cin>>edad[i];
        }

        printCentrado("Nivel Academico: ", 18);
        printCentrado("1. Tecnico -- 2. Tecnologo -- 3. Profesional -- 4. Posgrado", 19);
        gotoxy(100, 20); cin>>nivel_ac[i];

        while ((nivel_ac[i]<1)||(nivel_ac[i]>4))
        {
            limpiarLinea(20);
            printCentrado("Ingrese un nivel academico valido", 17);
            printCentrado("Nivel Academico: ", 18);
            printCentrado("1. Tecnico -- 2. Tecnologo -- 3. Profesional -- 4. Posgrado", 19);
            gotoxy(100, 20); cin>>nivel_ac[i];
        }

        printCentrado("Años de experiencia laboral", 23);
        gotoxy(100, 24); cin>>exp_lab[i];

        while ((exp_lab[i]>edad[i])||(exp_lab[i]>(edad[i]-18))||(exp_lab[i]<0))
        {
            limpiarLinea(24);
            printCentrado("La experiencia laboral no coincide con la edad", 22);
            printCentrado("Años de experiencia laboral", 23);
            gotoxy(100, 24); cin>>exp_lab[i];
        }

        while ((exp_lab[i]<0)||(exp_lab[i]>70))
        {
            limpiarLinea(24);
            printCentrado("La experiencia tiene que ser mayor o igual a 0 y menor a 70", 22);
            printCentrado("Años de experiencia laboral", 23);
            gotoxy(100, 24); cin>>exp_lab[i];
        }

        printCentrado("Puntaje en pruebas tecnicas: ", 27);
        gotoxy(100, 28); cin>>puntaje_pt[i];

        while ((puntaje_pt[i]<0)||(puntaje_pt[i]>100))
        {
            limpiarLinea(28);
            printCentrado("El puntaje tiene que estar entre 0 y 100", 26);
            printCentrado("Puntaje en pruebas tecnicas: ", 27);
            gotoxy(100, 28); cin>>puntaje_pt[i];
        }

        printCentrado("Puntaje en entrevista: ", 31);
        gotoxy(100, 32); cin>>puntaje_e[i];

        while ((puntaje_e[i]<0)||(puntaje_e[i]>100))
        {
            limpiarLinea(32);
            printCentrado("El puntaje tiene que estar entre 0 y 100", 30);
            printCentrado("Puntaje en entrevista: ", 31);
            gotoxy(100, 32); cin>>puntaje_e[i];
        }

        system("cls");

    }
}

int puntaje_aspi(int j,int N, const vector<int>& nivel_ac, const vector<int>& exp_lab, const vector<int>& puntaje_pt, const vector<int>& puntaje_e, int &pna, int &pae, int &ppt, int &pe, float &suma)
{

    int total=0;

    switch (nivel_ac[j])
    {
        case 1: pna=15; break;
        case 2: pna=20; break;
        case 3: pna=25; break;
        case 4: pna=30; break;
    }

    if (exp_lab[j]<1) pae=5;
    else if (exp_lab[j]<4) pae=10;
    else if (exp_lab[j]<7) pae=15;
    else pae=20;

    if (puntaje_pt[j]<60) ppt=10;
    else if (puntaje_pt[j]<80) ppt=20;
    else if (puntaje_pt[j]<90) ppt=25;
    else ppt=30;

    if (puntaje_e[j]<60) pe=5;
    else if (puntaje_e[j]<80) pe=10;
    else if (puntaje_e[j]<90) pe=15;
    else pe=20;

    total=pna+ppt+pae+pe;

    suma+=total;

    return total;

}

void reportes(int N, const vector<long> identificaciones, const vector<int> edad, const vector<int> nivel_ac, const vector<int> exp_lab, const vector<int> puntaje_pt, const vector<int> puntaje_e, const vector<int> puntaje_max, const vector<string> nombres, float suma, string nivel_academico[])
{

    char opcion;

    printCentrado("Reportes y consultas", 4);
    printCentrado("a. Listado general de aspirante registrados", 5);
    printCentrado("b. Reporte ordenado ascendentemente por puntaje total", 6);
    printCentrado("c. Consulta de aspirante destacado", 7);
    gotoxy(100, 8); cin>>opcion;
    opcion=toupper(opcion);

    while (!((opcion=='A')||(opcion=='B')||(opcion=='C')))
    {
        limpiarLinea(8);
        printCentrado("Ingrese una opcion valida", 3);
        printCentrado("Reportes y consultas", 4);
        printCentrado("a. Listado general de aspirante registrados", 5);
        printCentrado("b. Reporte ordenado ascendentemente por puntaje total", 6);
        printCentrado("c. Consulta de aspirante destacado", 7);
        gotoxy(100, 8); cin>>opcion;
        opcion=toupper(opcion);
    }

    printCentrado("Presione Enter para continuar", 15);
    cin.ignore();
    gotoxy(100, 16); cin.get();
    system("cls");

    switch (opcion)
    {
        case 'A': listado(N, nombres, identificaciones, edad, nivel_ac, exp_lab, puntaje_pt, puntaje_e, puntaje_max, nivel_academico); break;
        case 'B': ordenado(N, nombres, identificaciones, edad, nivel_ac, exp_lab, puntaje_pt, puntaje_e, puntaje_max, suma, nivel_academico); break;
        case 'C': consulta(N, nombres, identificaciones, edad, nivel_ac, exp_lab, puntaje_pt, puntaje_e, puntaje_max, nivel_academico); break;
    }

}

void listado(int N, const vector<string>& nombres, const vector<long>& identificaciones, const vector<int>& edad, const vector<int>& nivel_ac, const vector<int>& exp_lab, const vector<int>& puntaje_pt, const vector<int>& puntaje_e, vector<int> puntaje_max, string nivel_academico[])
{
    int *p=&puntaje_max[0], i=0, max=0, mx=0, k=0;

    printCentrado("Listado general de aspirantes", 3);

    int y=10, x=10;

    gotoxy(x, y++); cout<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+";
    gotoxy(x, y++); cout<<"| "<<left<<setw(19)<<"Aspirante"<<"| "<<setw(19)<<"Nombre"<<"| "<<setw(19)<<"Identificacion"<<"| "<<setw(19)<<"Edad"<<"| "<<setw(19)<<"Nivel Academico"<<"| "<<setw(19)<<"Años de experiencia"<<"| "<<setw(19)<< "Pruebas Tecnicas"<<"| "<<setw(19)<<"Entrevista"<<"| "<<setw(19)<<"Puntaje Total"<<"| "<<endl;
    gotoxy(x, y++); cout<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<endl;
    for (; p<=&puntaje_max[N-1]; p++, i++)
    {
        if (puntaje_max[i]>max)
        {
            max=puntaje_max[i];
            mx=i;
        }

        k=nivel_ac[i]-1;

        gotoxy(x, y++); cout<<"| "<<left<<setw(19)<<i+1<<"| "<<left<<setw(19)<<nombres[i]<<"| "<<setw(19)<<identificaciones[i]<<"| "<<setw(19)<<edad[i]<<"| "<<setw(19)<<nivel_academico[k]<<"| "<<setw(19)<<exp_lab[i]<<"| "<<setw(19)<<puntaje_pt[i]<<"| "<<setw(19)<<puntaje_e[i]<<"| "<<setw(19)<<puntaje_max[i]<<"| "<<endl;
    }
    gotoxy(x, y++); cout<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+";

    y+=3;

    printCentrado("Aspirante con el mayor puntaje", y++);

    x=75;
    y+=3;

    gotoxy(x, y++); cout<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<endl;
    gotoxy(x, y++); cout<<"| "<<left<<setw(19)<<"Aspirante"<<"| "<<setw(19)<<"Nombre"<<"| "<<setw(19)<<"Identificacion"<<"| "<<endl;
    gotoxy(x, y++); cout<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<endl;
    gotoxy(x, y++); cout<<"| "<<left<<setw(19)<<mx+1<<"| "<<left<<setw(19)<<nombres[mx]<<"| "<<setw(19)<<identificaciones[mx]<<"| "<<endl;
    gotoxy(x, y++); cout<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<endl;

    y+=3;

    printCentrado("Presione enter para continuar", y++);
    cin.ignore();
    gotoxy(100, y); cin.get();
    system("cls");

}

void ordenado(int N, vector<string> nombres, vector<long> identificaciones, vector<int> edad, vector<int> nivel_ac, vector<int> exp_lab, vector<int> puntaje_pt, vector<int> puntaje_e, vector<int> puntaje_max, float suma, string nivel_academico[])
{
    string *a=&nombres[0], aux;
    long *b=&identificaciones[0], aux2=0;
    int *c=&edad[0], aux3=0, aux4=0, aux5=0, aux6=0, aux7=0, mayor=0;
    int *d=&nivel_ac[0];
    int *e=&exp_lab[0];
    int *f=&puntaje_pt[0];
    int *g=&puntaje_e[0];
    int *h=&puntaje_max[0], *x=&puntaje_max[0];

    int *limite=&puntaje_max[N-1];

    for (h=&puntaje_max[0]; h<&puntaje_max[N-1]; h++)
    {
        for (x=&puntaje_max[0], b=&identificaciones[0], a=&nombres[0], c=&edad[0], d=&nivel_ac[0], e=&exp_lab[0], f=&puntaje_pt[0], g=&puntaje_e[0]; x<limite; x++, a++, b++, c++, d++, e++, f++, g++)
        {
            if (*x>*(x+1))
            {

                aux7=*x;
                *x=*(x+1);
                *(x+1)=aux7;

                aux=*a;
                *a=*(a+1);
                *(a+1)=aux;

                aux2=*b;
                *b=*(b+1);
                *(b+1)=aux2;

                aux3=*c;
                *c=*(c+1);
                *(c+1)=aux3;

                aux4=*d;
                *d=*(d+1);
                *(d+1)=aux4;

                aux5=*e;
                *e=*(e+1);
                *(e+1)=aux5;

                aux6=*f;
                *f=*(f+1);
                *(f+1)=aux6;

                aux7=*g;
                *g=*(g+1);
                *(g+1)=aux7;
            }
        }
        limite--;
    }


    x=&puntaje_max[0];

    for (; x<=&puntaje_max[N-1]; x++)
    {
        if (static_cast<float>(*x)>suma/static_cast<float>(N)) mayor++;
    }

    x=&puntaje_max[0];

    int y=10, x1=10, i=0, k=0;

    printCentrado("Reporte ordenado ascendentemente por el puntaje total", y);

    y+=5;

    gotoxy(x1, y++); cout<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+";
    gotoxy(x1, y++); cout<<"| "<<left<<setw(19)<<"Aspirante"<<"| "<<setw(19)<<"Nombre"<<"| "<<setw(19)<<"Identificacion"<<"| "<<setw(19)<<"Edad"<<"| "<<setw(19)<<"Nivel Academico"<<"| "<<setw(19)<<"Años de experiencia"<<"| "<<setw(19)<< "Pruebas Tecnicas"<<"| "<<setw(19)<<"Entrevista"<<"| "<<setw(19)<<"Puntaje Total"<<"| "<<endl;
    gotoxy(x1, y++); cout<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<endl;
    for (; x<=&puntaje_max[N-1]; i++, x++)
    {
        k=nivel_ac[i]-1;
        gotoxy(x1, y++); cout<<"| "<<left<<setw(19)<<i+1<<"| "<<left<<setw(19)<<nombres[i]<<"| "<<setw(19)<<identificaciones[i]<<"| "<<setw(19)<<edad[i]<<"| "<<setw(19)<<nivel_academico[k]<<"| "<<setw(19)<<exp_lab[i]<<"| "<<setw(19)<<puntaje_pt[i]<<"| "<<setw(19)<<puntaje_e[i]<<"| "<<setw(19)<<puntaje_max[i]<<"| "<<endl;
    }
    gotoxy(x1, y++); cout<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<endl;

    y+=5;
    x1=65;

    gotoxy(x1, y++); cout<<"+"<<string(20, '-')<<"+"<<string(45, '-')<<"+"<<endl;
    gotoxy(x1, y++); cout<<"| "<<left<<setw(19)<<"Puntaje promedio"<<"| "<<setw(44)<<"(%) de aspirantes por encima del promedio"<<"| "<<endl;
    gotoxy(x1, y++); cout<<"+"<<string(20, '-')<<"+"<<string(45, '-')<<"+"<<endl;
    gotoxy(x1, y++); cout<<"| "<<left<<setw(19)<<(suma/static_cast<float>(N))<<"| "<<left<<setw(44)<<(mayor*100)/N<<"| "<<endl;
    gotoxy(x1, y++); cout<<"+"<<string(20, '-')<<"+"<<string(45, '-')<<"+"<<endl;

    printCentrado("Presione enter para continuar", y++);
    cin.ignore();
    gotoxy(100, y); cin.get();
    system("cls");
}

void consulta(int N, vector<string> nombres, vector<long> identificaciones, vector<int> edad, vector<int> nivel_ac, vector<int> exp_lab, vector<int> puntaje_pt, vector<int> puntaje_e, vector<int> puntaje_max, string nivel_academico[])
{

    long aux=0, *p=&identificaciones[0], i=0;
    bool centi;
    int x1=10, y=10, k=0;

    printCentrado("Consulte la informacion de cualquier aspirante ingresando su identificacion", 4);
    gotoxy(100, 5); cin>>aux;

    for (; p<=&identificaciones[N-1]; p++, i++)
    {
        if (*p==aux)
        {
            y+=3;
            k=nivel_ac[i]-1;

            gotoxy(x1, y++); cout<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+";
            gotoxy(x1, y++); cout<<"| "<<left<<setw(19)<<"Aspirante"<<"| "<<setw(19)<<"Nombre"<<"| "<<setw(19)<<"Identificacion"<<"| "<<setw(19)<<"Edad"<<"| "<<setw(19)<<"Nivel Academico"<<"| "<<setw(19)<<"Años de experiencia"<<"| "<<setw(19)<< "Pruebas Tecnicas"<<"| "<<setw(19)<<"Entrevista"<<"| "<<setw(19)<<"Puntaje Total"<<"| "<<endl;
            gotoxy(x1, y++); cout<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<endl;
            gotoxy(x1, y++); cout<<"| "<<left<<setw(19)<<i+1<<"| "<<left<<setw(19)<<nombres[i]<<"| "<<setw(19)<<identificaciones[i]<<"| "<<setw(19)<<edad[i]<<"| "<<setw(19)<<nivel_academico[k]<<"| "<<setw(19)<<exp_lab[i]<<"| "<<setw(19)<<puntaje_pt[i]<<"| "<<setw(19)<<puntaje_e[i]<<"| "<<setw(19)<<puntaje_max[i]<<"| "<<endl;
            gotoxy(x1, y++); cout<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<string(20, '-')<<"+"<<endl;
            centi=true;

            break;
        }
        else
        {
            centi=false;
        }
    }

    if (centi==false)
    {
        y+=5;
        printCentrado("No se encontro informacion sobre la identificacion digitada", y++);
        printCentrado("Por favor vuelva al menu e intente nuevamente", y++);
    }

    y+=3;

    printCentrado("Presione enter para continuar", y++);
    cin.ignore();
    gotoxy(100, y); cin.get();
    system("cls");

}