//
// Created by ASUS on 3/5/2018.
//

#ifndef EJERCICIOSARCHIVOS_NOTAS_H
#define EJERCICIOSARCHIVOS_NOTAS_H
class Notas{
public:
    static void registrarAlumnos();
    static void consultarAlumnos();
    static void registrarMaterias();
    static void consultarMaterias();
    static void registrarNotas();
    static void consultarNotas();
    static int obtenerCodigoAlumnos(char*);
    static int obtenerCodigoMateria(char*);
    static char * obtenerNombreAlumno(const int);
    static char * obtenerNombreMaterias(const int);

    static int promedioNotaAlumno(char*);
    static int promedioNotaMateria(char*);

};

#endif //EJERCICIOSARCHIVOS_NOTAS_H
