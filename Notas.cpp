//
// Created by ASUS on 3/5/2018.
//

#include "Notas.h"
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

void Notas::registrarAlumnos() {
    ofstream archivoAlumnos("alumnos.dat", ios::app);
    if(!archivoAlumnos){
        cout<<"Error al intentar abrir archivo alumnos.dat\n";
        return;
    }

    int cuenta,edad, cant;
    char nombre[50];

    cout<<"\n\n *** I N G R E S O  D E  A L U M N O S ***\n\n";
    cout<<"Cantidad de alumnos a ingresar: ";
    cin>> cant;

    for(int i=0; i< cant; i++){
        cout<< " Ingrese numero de cuenta: ";
        cin>> cuenta;
        cout<<"Ingrese nombre de alumnos: ";
        cin>> nombre;
        cout<<"Ingrese edad: ";
        cin>>edad;

        archivoAlumnos<<cuenta<<' '<<nombre<< ' '<<edad<<"\n";

    }

    archivoAlumnos.close();
}

void Notas::consultarAlumnos() {
    ifstream archivoAlumnosIn("alumnos.dat",ios::app);
    if(!archivoAlumnosIn){
        cout<<"Error al intentar abrir el archivo alumnos.dat";
        return;
    }

    int cuenta, edad;
    char nombre[50];

    cout<<"\n\n *** C O N S U L T A  D E  A L U M N O S ***\n\n";
    while(archivoAlumnosIn>>cuenta>>nombre>>edad){
        cout<<cuenta << ' '<<nombre<< ' '<<edad<<"\n";

    }
}

void Notas::registrarMaterias() {
    ofstream archivoMateriaOut("materias.dat",ios::app);
    if(!archivoMateriaOut) {
        cout << "Error al intentar abrir el archivo materias.dat";
        return;
    }
    int cantidad,codigoM;
    char nombreM[30];

    cout<< "\n\n *** I N G R E S O  D E  M A T E R I A S ***\n\n";
    cout<<"Ingrese cantidad de materias: ";
    cin>>cantidad;

    for (int i =0;i<cantidad;i++){
        cout<<"Ingrese codigo: ";
        cin>>codigoM;
        cout<<"Ingrese materia: ";
        cin>>nombreM;

        archivoMateriaOut<<codigoM<<' '<<nombreM<<"\n";

    }
    archivoMateriaOut.close();

    }

void Notas::consultarMaterias() {
    ifstream MateriasIn("materias.dat",ios::in);
    if(!MateriasIn){
        cout<<"Error al intentar abrir el archivo alumnos.dat";
        return;
    }
    int codigoM;
    char nombreM[30];

    MateriasIn.seekg(0,ios::beg);
    cout<<"\n\n *** C O N S U L T A  D E  M A T E R I A S ***\n\n";
    while(MateriasIn>>codigoM>>nombreM){
        cout<<codigoM<< ' '<<nombreM<<"\n";

    }
    MateriasIn.close();
    }

void Notas::registrarNotas() {
    ofstream archivoNotasOut("notas.dat",ios::app);
    if(!archivoNotasOut){
        cout<<"Error al intentar abrir el archivo notas.dat";
        return;
    }
    int opc=0;
    cout<<"\n\n *** I N G R E S E  D E  N O T A S *** \n\n";
    do{
        char nombreM[30];
        char nombreA[50];
        int nota,codigoM, codigoA;
        do{
            cout<<"Ingrese Materia: ";
            cin>>nombreM;
            codigoM=obtenerCodigoMateria(nombreM);
        }while(codigoM==-1);
        do{
            cout<<"Ingrese Alumno: ";
            cin>>nombreA;
            codigoA=obtenerCodigoAlumnos(nombreA);
        }while(codigoA==-1);
        cout<<"Ingrese Nota: ";
        cin>>nota;
        archivoNotasOut<<codigoM<<' '<<codigoA<<' '<<nota<<"\n";
        cout<<"Desea ingresar una nota nota? -1 para salir ";
        cin>>opc;
    }while(opc!=-1);
    archivoNotasOut.close();
}

int Notas::obtenerCodigoMateria(char *nombreM) {
    ifstream archivoMateria("materias.dat",ios::in);
    if(!archivoMateria){
        cout<<"Error al intentar abrir el archivo materias.dat";
        return -1;
    }
    archivoMateria.seekg(0,ios::beg);
    int codigo;
    char nombre[30];

    while(archivoMateria>>codigo>>nombre){
        if(strcmp(nombre,nombreM)==0)
            return codigo;
         }
    return -1;
}

int Notas::obtenerCodigoAlumnos(char *nombreA) {
    ifstream archivoAlumnos("alumnos.dat",ios::in);
    if(!archivoAlumnos){
        cout<<"Error al intentar abrir el archivo alumnos.dat";
        return -1;
    }
    archivoAlumnos.seekg(0,ios::beg);
    int codigo,edad;
    char nombre[30];

    while(archivoAlumnos>>codigo>>nombre>>edad){
        if(strcmp(nombre,nombreA)==0)
            return codigo;
    }
    return -1;
}

char * Notas::obtenerNombreAlumno(const int codigoAlumno){
    ifstream archivoAlumno("alumnos.dat",ios::in);
    if(!archivoAlumno){
        cout<<"Error al intentar abrir el archivo alumnos.dat";
        return NULL;
    }
    int codigo,edad;
    char nombre[50];

    archivoAlumno.seekg(0,ios::beg);
    while(archivoAlumno>>codigo>>nombre>>edad){
        if(codigoAlumno==codigo)
        {
            char *retorno=new char[strlen(nombre)];
            strcpy(retorno,nombre);
            retorno[strlen(nombre)]='\0';
            archivoAlumno.close();
            return retorno;
        }
    }

    archivoAlumno.close();
    return NULL;
}

char * Notas::obtenerNombreMaterias(const int codigoMaterias) {
    ifstream archivoMaterias("materias.dat",ios::in);
    if(!archivoMaterias){
        cout<<"Error al intentar abrir el archivo materias.dat";
        return NULL; //nullptr,0
    }
    int codigo;
    char nombre[30];

    archivoMaterias.seekg(0,ios::beg);
    while(archivoMaterias>>codigo>>nombre){
        if(codigoMaterias==codigo)
        {
            char *retorno=new char[strlen(nombre)];
            strcpy(retorno,nombre);
            retorno[strlen(nombre)]='\0';
            archivoMaterias.close();
            return retorno;
        }
    }
    archivoMaterias.close();
    return NULL;
}

void Notas::consultarNotas() {
    ifstream archivoNotas("notas.dat",ios::in);
    if(!archivoNotas){
        cout<<"Error al intentar abir el archivo notas.dat";
        return;
    }

    cout<<"\n\n *** C O N S U L T A R  D E  N O T A S *** \n\n";
    int codigoM,codigoA,nota;
    archivoNotas.seekg(0, ios::beg);
    while(archivoNotas>>codigoM>>codigoA>>nota){
        cout<<obtenerNombreMaterias(codigoM)<<' '<<obtenerNombreAlumno(codigoA)<<' '<< nota<<"\n";
    }
    archivoNotas.close();
}

int Notas::promedioNotaAlumno(char *nombreA) {
    ifstream archivoNotasA("notas.dat",ios::in);
    if(!archivoNotasA){
        cout<<"Error al intentar abir el archivo notas.dat";
        return -1;
    }
    int codigoA , promedio=0, materias=0;
    int codM,codA,notas;

    cout<<"Ingrese codigo del alumno: "<<endl;
    cin>>codA;
    codigoA=obtenerCodigoAlumnos(nombreA);
        while(archivoNotasA>>codM>>codA>>notas) {
            if (codigoA == codA) {
                promedio += notas;
                materias++;
            }
        }
    return (promedio/materias);
}

int Notas::promedioNotaMateria(char *nombreM) {
        ifstream archivoNotasA("notas.dat",ios::in);
        if(!archivoNotasA){
            cout<<"Error al intentar abrir el archivo notas.dat";
            return -1;
        }
        int codigoM , promedio=0, alumnos=0;
        int codM,codA,notas;
        cout<<"Ingrese codigo de la materia: "<<endl;
        cin>>codM;
        codigoM=obtenerCodigoMateria(nombreM);
        while(archivoNotasA>>codM>>codA>>notas) {
            if (codigoM == codM) {
                promedio += notas;
                alumnos++;
            }
        }
        return (promedio/alumnos);
    }
