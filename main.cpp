#include <iostream>
#include "conio.h"
#include "Notas.h"
using namespace std;

int main() {
    int opc=0;
    do{
    cout<< "*** M E N U ***"<<endl;
    cout<<"1. Registrar Alumnos"<<endl;
    cout<<"2. Registrar Materias"<<endl;
    cout<<"3. Consultar Alumnos" <<endl;
    cout<<"4. Consultar Materias" <<endl;
    cout<<"5. Registrar Notas"<<endl;
    cout<<"6. Consultar Notas" <<endl;
    cout<<"7. Promedio por nota del alumno"<<endl;
    cout<<"8. Promedio por nota la materia"<<endl;
    cout<<"Ingrese una opcion, -1 para salir:";
    cin>>opc;

switch(opc){
    case 1:
    Notas::registrarAlumnos();
        break;
    case 2:
        Notas::registrarMaterias();
        break;
    case 3:
        Notas::consultarAlumnos();
        break;
    case 4:
        Notas::consultarMaterias();
        break;
    case 5:
        Notas::registrarNotas();
        break;
    case 6:
        Notas::consultarNotas();
        break;
    case 7:
        char nombre[50];
        int cod;
        cout<<"Ingrese el nombre: "<<endl;
        cin>>nombre;
        cout<<"\n *** P R O M E D I O  D E  N O T A S  A L U M N O S *** \n";
        cout<<"El promedio de "<<nombre<<" es:"<<endl;
        cout<<Notas::promedioNotaAlumno(nombre)<<endl;
        break;
    case 8:
        char materia[30];
        cout<<"Ingrese el materia: "<<endl;
        cin>>materia;
        cout<<"\n *** P R O M E D I O  D E  N O T A S  M A T E R I A *** \n";
        cout<<"El promedio de la materia "<<materia<<" es:"<<endl;
        cout<<Notas::promedioNotaMateria(materia)<<endl;
        break;
}
}while(opc!=-1);
    getch();
}