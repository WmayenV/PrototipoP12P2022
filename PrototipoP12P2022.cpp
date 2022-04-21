#include<iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <iomanip>
#include <math.h>
using namespace std;

class clientes{
public:
    void altas(){
        system("cls");
        fstream baseDatos;
        cout << "\n\t\t\tEntrando al menu --REGISTRAR EMPLEADOS--\n" << endl;
        cout << "\n\t¿Quires salir al --MENU MANTENIMIENTO--? [ si / no ] : "; cin >> desicion; //No se porque es el error de desicion no esta declarada//
        if (desicion=="si"){
            return menuMantenimiento();
        }
        else {

            cout << "\n\t\tIngrese el numero de documento de identificacion de la persona:"; cin >> identificacion;
            cout << "\t\tIngrese el nombre de la persona a registrar: "; cin >> nombre;
            cout << "\t\tIngrese la edad de la persona a registrar: "; cin >> edad;
            cout << "\t\tIngrese el correo de la persona a registrar: "; cin >> correo;
            cout << "\t\tIngrese el numero de telefono de la persona a registrar: "; cin >> telefono;
            cout << "\t\tIngrese la direccion de la persona a registrar: "; cin >> direccion;
            cout << "\t\tIngrese la situacion de alta"; cin >> situacion;
            cout << "\n\t--Registro completado--\n" << endl;
            baseDatos.open("persona.dat", ios::app | ios::out | ios::binary);
            baseDatos <<std::left<<std::setw(15)<< identificacion <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< situacion  <<"\n";
            baseDatos.close();
            cout << "\n\n\t\tPresione s para salir "; cin >>desicion;
                if (desicion=="s"){
                    cout <<"\t\t\nRegresando al --MENU MANTENIMIENTO--";
                    return menuMantenimiento();
                }
        }
    };
    void bajas(){
        system("cls");

            cout << "\n\t\tIngrese el numero de documento de identificacion de la persona:"; cin >> identificacion;
            cout << "\t\tIngrese el nombre de la persona a registrar: "; cin >> nombre;
            cout << "\t\tIngrese la edad de la persona a registrar: "; cin >> edad;
            cout << "\t\tIngrese el correo de la persona a registrar: "; cin >> correo;
            cout << "\t\tIngrese el numero de telefono de la persona a registrar: "; cin >> telefono;
            cout << "\t\tIngrese la direccion de la persona a registrar: "; cin >> direccion;
            cout << "\t\tIngrese la situacion de baja"; cin >> situacionbaja;
            cout << "\n\t--Registro completado--\n" << endl;
            baseDatos.open("persona.dat", ios::app | ios::out | ios::binary);
            baseDatos <<std::left<<std::setw(15)<< identificacion <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< situacionbaja  <<"\n";
            baseDatos.close();
            cout << "\n\n\t\tPresione s para salir "; cin >>desicion;
                if (desicion=="s"){
                    cout <<"\t\t\nRegresando al --MENU MANTENIMIENTO--";
                    return menuMantenimiento();
                }
        }
    };
    void modificar(){

        system("cls");
        fstream baseDatos, modBaseDatos;
        cout << "\n\t\t\tEntrando al menu --MODIFICAR--" << endl;
            baseDatos.open("persona.dat",ios::in|ios::binary);
            if(!baseDatos){
                cout << "\n\t\tNo se encontro el archivo" << endl;
                baseDatos.close();
                cout << "\n\t\tPresione s para salir "; cin >>desicion;
                if (desicion=="s"){
                    cout <<"\t\t\t\nRegresando al --MENU MANTENIMIENTO--";
                    return menuMantenimiento();
                }
            }
            else {
                cout << "\n\t\t\tIngrese el numero de Documento de Identificacion de la persona que busca: "; cin >> busquedaDatos;
                modBaseDatos.open("temporal.dat",ios::app|ios::out|ios::binary);
                baseDatos>>identificacion>>nombre>>edad>>correo>>telefono>>direccion>>situacion;
                while (!baseDatos.eof()){
                    if (busquedaDatos!=identificacion){
                        modBaseDatos <<std::left<<std::setw(15)<< documentoIdentificacion <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono << std::left<<std::setw(15)<< direccion << std::left<<std::setw(15)<< situacion  <<"\n";
                    }
                    else {
                        cout << "\n\t\tIngrese el numero de documento de identificacion de la persona: "; cin >> documentoIdentificacion;
                        cout << "\t\tIngrese el nombre de la persona a registrar: "; cin >> nombre;
                        cout << "\t\tIngrese la edad de la persona a registrar: "; cin >> edad;
                        cout << "\t\tIngrese el correo de la persona a registrar: "; cin >> correo;
                        cout << "\t\tIngrese el numero de telefono de la persona a registrar: "; cin >> telefono;
                        cout << "\t\tIngrese la direccion de la persona a registrar: "; cin >> direccion;
                        cout << "\t\tIngrese la situacion de alta"; cin >> situacion;
                        modBaseDatos <<std::left<<std::setw(15)<< identificacion <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono << std::left<<std::setw(15)<< direccion << std::left<<std::setw(15)<<situacion <<"\n";
                    }
                    baseDatos>>identificacion>>nombre>>edad>>correo>>telefono>>direccion>>situacion;
                }
                modBaseDatos.close();
                baseDatos.close();
                remove("persona.dat");
                rename("temporal.dat","persona.dat");
                cout << "\n\n\t\tPresione s para salir "; cin >>desicion;
                if (desicion=="s"){
                    cout <<"\t\t\nRegresando al --MENU MANTENIMIENTO--";
                    return menuMantenimiento();
                }
            }
    }

    void mostrarDatos(){

        system("cls");
        fstream baseDatos;
        cout << "\n\t\t\tEntrando al menu --MOSTRAR DATOS--";
        cout << "\n\n\t\t¿Quiere buscar a una persona en especifico? [ si / no ] : "; cin>>desicion;
        if (desicion=="si"){
            int datos=0;
            baseDatos.open("persona.dat",ios::in|ios::binary);
            if(!baseDatos)
            {
                cout<<"\n\t\tError";
                cout<<"\n\t\t\tNo se encontro el archivo, asegurese de que el archivo este en la misma carpeta que el programa";
            }
            else
            {
                cout << "\n\t\t\tEntrando en el menu --BUSCAR--"<<endl;
                cout << "\n\t\tIngrese el numero del Documento de Identificacion de la persona a buscar: "; cin >> busquedaDatos;
                baseDatos>>identificacion>>nombre>>edad>>correo>>telefono>>direccion>>situacion;
                while(!baseDatos.eof()){
                    if(busquedaDatos==identificacion){
                        cout<<"\n\t\tDocumento de Identificacion: "<< identificacion;
                        cout<<"\n\t\tNombre: " << nombre;
                        cout<<"\n\t\tEdad: "<< edad;
                        cout<<"\n\t\tCorreo Electronico: "<< correo;
                        cout<<"\n\t\tTelefono: "<< telefono;
                        cout<<"\n\t\tDireccion: "<< direccion;
                        cout<<"\n\t\tSituacion: "<< situacion;
                        datos++;
                    }
                    baseDatos>>dentificacion>>nombre>>edad>>correo>>telefono>>direccion>>situacion;
                }
                if(datos==0)
                {
                    cout<<"\n\t\t\tNo se encontro ninguna coincidencia, intentelo de nuevo";
                }
                cout << "\n\t\tPresione s para salir "; cin >>desicion;
                if (desicion=="s"){
                    cout <<"\t\t\t\nRegresando al --MENU MOSTRAR DATOS--";
                    return mostrarDatos();
                }
                baseDatos.close();
            }
        }
        else {
            fstream baseDatos;
            int total=0;
            cout<<"\n\t\t\tEntrando al --MENU MOSTRAR DATOS"<<endl;
            baseDatos.open("persona.dat",ios::in|ios::binary);
            if(!baseDatos){
                cout<<"\n\t\t\tError\n\t\t\tNo se encontro el archivo, asegurese de que el archivo se encuentre en la misma carpeta del programa";
                baseDatos.close();
                cout << "\n\t\tPresione s para salir "; cin >>desicion;
                if (desicion=="s"){
                    cout <<"\t\t\t\nRegresando al --MENU MANTENIMIENTO--";
                    return menuMantenimiento();
                }
            }
            else
            {
                baseDatos>>identificacion>>nombre>>edad>>correo>>telefono>>direccion>>situacion;
                while(!baseDatos.eof())
                {
                    total++;
                    cout<<"\n\n\t\tDocumento de Identificacion: "<< documentoIdentificacion;
                    cout<<"\n\t\tNombre: " << nombre;
                    cout<<"\n\t\tEdad: "<< edad;
                    cout<<"\n\t\tCorreo Electronico: "<< correo;
                    cout<<"\n\t\tTelefono: "<< telefono;
                    cout<<"\n\t\tDireccion: "<< direccion;
                    cout<<"\n\t\tSituacion: "<< situacion;
                    baseDatos>>dentificacion>>nombre>>edad>>correo>>telefono>>direccion>>situacion;
                }
                if(total==0){
                    cout<<"\n\t\t\tEl archivo se encuentra vacio...";
                }
                cout << "\n\n\t\tPresione s para salir "; cin >>desicion;
                if (desicion=="s"){
                    cout <<"\t\t\nRegresando al --MENU MANTENIMIENTO--";
                    return menuMantenimiento();
                }
            }
            baseDatos.close();
        }
    }
};
void menuPrincipal(){
        system ("cls");
        int menu;
        fstream bienvenida;
        string line;
        bienvenida.open("bienvenidos.txt");
        if(bienvenida.is_open()){
        while( getline(bienvenida, line))
        {
            cout << line << endl;
        }
        bienvenida.close();
        }
        cout << "\n\t\tPresione i para ingresar al --PROGRAMA-- : ";cin>>desicion;
        if (desicion=="i"){
            cout << "\n\t\t\tBienvenido al programa de ==PrototipoP12P2022  9959-21-1581 William Ottoniel Mayen Vasquez==";
            cout << "\n\n\t\tElija el numero del menu al que quiera ingresar\n"<< endl << "\t\t[1] Mantenimiento\n" << "\t\t[2] Catalogo\n" << "\t\t[3] Proceso\n" << "\t\t[4] Informe\n" << "\t\t[5] Salir del programa\n";cout<<"\n\t\t";cin >> menu;
            switch(menu){
            case 1:
                menuMantenimiento();
                break;
            case 2:
                menuCatalogo();
                break;
            case 3:
                menuProceso();
                break;
            case 4:
                menuInforme();
                break;
            case 5:
                cout << "\n\t\t¿Quiere salir del programa? [ si / no ] : "; cin>>desicion;
                if (desicion=="si"){
                    return exit (0);
                }
                else {
                    return menuPrincipal();
                break;
                }
            }
        }
    }
void menuMantenimiento(){
        system("cls");
        int menu;
        cout << "\n\t\tBienvenido al --MENU CRUD--" << endl;
        cout << "\n\t\tElija el numero del menu al que quiere ingresar\n" << endl << "\t\t[1] Alta\n" << "\t\t[2] Baja\n" << "\t\t[3] Modificar\n" << "\t\t[4] Mostrar Datos\n" << "\t\t[5] Salir al --MENU PRINCIPAL--\n";cout<<"\n\t\t"; cin >> menu;
        switch (menu){
        case 1:
            altas();
            break;
        case 2:
            bajas();
            break;
        case 3:
            modificar();
            break;
        case 4:
            mostrarDatos();
            break;
        case 5:
            cout << "\tSaliendo al --MENU PRINCIPAL--" << endl;
            return menuPrincipal();
            break;
            }
    }
  }
void menuCatalogo(){
        system("cls");
        int menu;
        cout << "\n\t\tBienvenido al --MENU CRUD--" << endl;
        cout << "\n\t\tElija el numero del menu al que quiere ingresar\n" << endl << "\t\t[1] Alta\n" << "\t\t[2] Baja\n" << "\t\t[3] Modificar\n" << "\t\t[4] Mostrar Datos\n" << "\t\t[5] Salir al --MENU PRINCIPAL--\n";cout<<"\n\t\t"; cin >> menu;
        switch (menu){
        case 1:
            altas();
            break;
        case 2:
            bajas();
            break;
        case 3:
            modificar();
            break;
        case 4:
            mostrarDatos();
            break;
        case 5:
            cout << "\tSaliendo al --MENU PRINCIPAL--" << endl;
            return menuPrincipal();
            break;
            }
    }
  }
  void menuInforme(){
        system("cls");
        int menu;
        cout << "\n\t\tBienvenido al --MENU CRUD--" << endl;
        cout << "\n\t\tElija el numero del menu al que quiere ingresar\n" << endl << "\t\t[1] Alta\n" << "\t\t[2] Baja\n" << "\t\t[3] Modificar\n" << "\t\t[4] Mostrar Datos\n" << "\t\t[5] Salir al --MENU PRINCIPAL--\n";cout<<"\n\t\t"; cin >> menu;
        switch (menu){
        case 1:
            altas();
            break;
        case 2:
            bajas();
            break;
        case 3:
            modificar();
            break;
        case 4:
            mostrarDatos();
            break;
        case 5:
            cout << "\tSaliendo al --MENU PRINCIPAL--" << endl;
            return menuPrincipal();
            break;
            }
    }
  }
private:

    string identificacion, nombre, direccion, edad, correo, telefono, dituacion, desicion, busquedaDatos;;

class informe : public clientes{
private:
    string identificacion, nombre, direccion, edad, correo, telefono, situacion, desicion, busquedaDatos;;
    void altas(){
        system("cls");

            cout << "\n\t\tIngrese el numero de documento de identificacion de la persona:"; cin >> identificacion;
            cout << "\t\tIngrese el nombre de la persona a registrar: "; cin >> nombre;
            cout << "\t\tIngrese la edad de la persona a registrar: "; cin >> edad;
            cout << "\t\tIngrese el correo de la persona a registrar: "; cin >> correo;
            cout << "\t\tIngrese el numero de telefono de la persona a registrar: "; cin >> telefono;
            cout << "\t\tIngrese la direccion de la persona a registrar: "; cin >> direccion;
            cout << "\t\tIngrese la situacion de alta"; cin >> situacion;
            cout << "\n\t--Registro completado--\n" << endl;
            baseDatos.open("persona.dat", ios::app | ios::out | ios::binary);
            baseDatos <<std::left<<std::setw(15)<< identificacion <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< situacion  <<"\n";
            baseDatos.close();
            cout << "\n\n\t\tPresione s para salir "; cin >>desicion;
                if (desicion=="s"){
                    cout <<"\t\t\nRegresando al --MENU MANTENIMIENTO--";
                    return menuMantenimiento();
                }
        }
    };
    void bajas(){
        system("cls");

            cout << "\n\t\tIngrese el numero de documento de identificacion de la persona:"; cin >> identificacion;
            cout << "\t\tIngrese el nombre de la persona a registrar: "; cin >> nombre;
            cout << "\t\tIngrese la edad de la persona a registrar: "; cin >> edad;
            cout << "\t\tIngrese el correo de la persona a registrar: "; cin >> correo;
            cout << "\t\tIngrese el numero de telefono de la persona a registrar: "; cin >> telefono;
            cout << "\t\tIngrese la direccion de la persona a registrar: "; cin >> direccion;
            cout << "\t\tIngrese la situacion de baja"; cin >> situacionbaja;
            cout << "\n\t--Registro completado--\n" << endl;
            baseDatos.open("persona.dat", ios::app | ios::out | ios::binary);
            baseDatos <<std::left<<std::setw(15)<< identificacion <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< situacionbaja  <<"\n";
            baseDatos.close();
            cout << "\n\n\t\tPresione s para salir "; cin >>desicion;
                if (desicion=="s"){
                    cout <<"\t\t\nRegresando al --MENU MANTENIMIENTO--";
                    return menuMantenimiento();
                }
        }
    }
    void modificar(){

        system("cls");
        fstream baseDatos, modBaseDatos;
        cout << "\n\t\t\tEntrando al menu --MODIFICAR--" << endl;
            baseDatos.open("persona.dat",ios::in|ios::binary);
            if(!baseDatos){
                cout << "\n\t\tNo se encontro el archivo" << endl;
                baseDatos.close();
                cout << "\n\t\tPresione s para salir "; cin >>desicion;
                if (desicion=="s"){
                    cout <<"\t\t\t\nRegresando al --MENU MANTENIMIENTO--";
                    return menuMantenimiento();
                }
            }
            else {
                cout << "\n\t\t\tIngrese el numero de Documento de Identificacion de la persona que busca: "; cin >> busquedaDatos;
                modBaseDatos.open("temporal.dat",ios::app|ios::out|ios::binary);
                baseDatos>>identificacion>>nombre>>edad>>correo>>telefono>>direccion>>situacion;
                while (!baseDatos.eof()){
                    if (busquedaDatos!=identificacion){
                        modBaseDatos <<std::left<<std::setw(15)<< documentoIdentificacion <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono << std::left<<std::setw(15)<< direccion << std::left<<std::setw(15)<< situacion  <<"\n";
                    }
                    else {
                        cout << "\n\t\tIngrese el numero de documento de identificacion de la persona: "; cin >> documentoIdentificacion;
                        cout << "\t\tIngrese el nombre de la persona a registrar: "; cin >> nombre;
                        cout << "\t\tIngrese la edad de la persona a registrar: "; cin >> edad;
                        cout << "\t\tIngrese el correo de la persona a registrar: "; cin >> correo;
                        cout << "\t\tIngrese el numero de telefono de la persona a registrar: "; cin >> telefono;
                        cout << "\t\tIngrese la direccion de la persona a registrar: "; cin >> direccion;
                        cout << "\t\tIngrese la situacion de alta"; cin >> situacion;
                        modBaseDatos <<std::left<<std::setw(15)<< identificacion <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono << std::left<<std::setw(15)<< direccion << std::left<<std::setw(15)<<situacion <<"\n";
                    }
                    baseDatos>>identificacion>>nombre>>edad>>correo>>telefono>>direccion>>situacion;
                }
                modBaseDatos.close();
                baseDatos.close();
                remove("persona.dat");
                rename("temporal.dat","persona.dat");
                cout << "\n\n\t\tPresione s para salir "; cin >>desicion;
                if (desicion=="s"){
                    cout <<"\t\t\nRegresando al --MENU MANTENIMIENTO--";
                    return menuMantenimiento();
                }
            }
    }

    void mostrarDatos(){

        system("cls");
        fstream baseDatos;
        cout << "\n\t\t\tEntrando al menu --MOSTRAR DATOS--";
        cout << "\n\n\t\t¿Quiere buscar a una persona en especifico? [ si / no ] : "; cin>>desicion;
        if (desicion=="si"){
            int datos=0;
            baseDatos.open("persona.dat",ios::in|ios::binary);
            if(!baseDatos)
            {
                cout<<"\n\t\tError";
                cout<<"\n\t\t\tNo se encontro el archivo, asegurese de que el archivo este en la misma carpeta que el programa";
            }
            else
            {
                cout << "\n\t\t\tEntrando en el menu --BUSCAR--"<<endl;
                cout << "\n\t\tIngrese el numero del Documento de Identificacion de la persona a buscar: "; cin >> busquedaDatos;
                baseDatos>>identificacion>>nombre>>edad>>correo>>telefono>>direccion>>situacion;
                while(!baseDatos.eof()){
                    if(busquedaDatos==identificacion){
                        cout<<"\n\t\tDocumento de Identificacion: "<< identificacion;
                        cout<<"\n\t\tNombre: " << nombre;
                        cout<<"\n\t\tEdad: "<< edad;
                        cout<<"\n\t\tCorreo Electronico: "<< correo;
                        cout<<"\n\t\tTelefono: "<< telefono;
                        cout<<"\n\t\tDireccion: "<< direccion;
                        cout<<"\n\t\tSituacion: "<< situacion;
                        datos++;
                    }
                    baseDatos>>dentificacion>>nombre>>edad>>correo>>telefono>>direccion>>situacion;
                }
                if(datos==0)
                {
                    cout<<"\n\t\t\tNo se encontro ninguna coincidencia, intentelo de nuevo";
                }
                cout << "\n\t\tPresione s para salir "; cin >>desicion;
                if (desicion=="s"){
                    cout <<"\t\t\t\nRegresando al --MENU MOSTRAR DATOS--";
                    return mostrarDatos();
                }
                baseDatos.close();
            }
        }
        else {
            fstream baseDatos;
            int total=0;
            cout<<"\n\t\t\tEntrando al --MENU MOSTRAR DATOS"<<endl;
            baseDatos.open("persona.dat",ios::in|ios::binary);
            if(!baseDatos){
                cout<<"\n\t\t\tError\n\t\t\tNo se encontro el archivo, asegurese de que el archivo se encuentre en la misma carpeta del programa";
                baseDatos.close();
                cout << "\n\t\tPresione s para salir "; cin >>desicion;
                if (desicion=="s"){
                    cout <<"\t\t\t\nRegresando al --MENU MANTENIMIENTO--";
                    return menuMantenimiento();
                }
            }
            else
            {
                baseDatos>>identificacion>>nombre>>edad>>correo>>telefono>>direccion>>situacion;
                while(!baseDatos.eof())
                {
                    total++;
                    cout<<"\n\n\t\tDocumento de Identificacion: "<< documentoIdentificacion;
                    cout<<"\n\t\tNombre: " << nombre;
                    cout<<"\n\t\tEdad: "<< edad;
                    cout<<"\n\t\tCorreo Electronico: "<< correo;
                    cout<<"\n\t\tTelefono: "<< telefono;
                    cout<<"\n\t\tDireccion: "<< direccion;
                    cout<<"\n\t\tSituacion: "<< situacion;
                    baseDatos>>dentificacion>>nombre>>edad>>correo>>telefono>>direccion>>situacion;
                }
                if(total==0){
                    cout<<"\n\t\t\tEl archivo se encuentra vacio...";
                }
                cout << "\n\n\t\tPresione s para salir "; cin >>desicion;
                if (desicion=="s"){
                    cout <<"\t\t\nRegresando al --MENU MANTENIMIENTO--";
                    return menuMantenimiento();
                }
            }
            baseDatos.close();
        }
    }
};
int main(){
    system ("cls");
    string usuario, contrasena, config1, config2;
    fstream usuariosContrasenas;
    usuariosContrasenas.open("seguridad.dat",ios::app|ios::in|ios::binary);
    if(!usuariosContrasenas){
        cout<<"\n\t\tError";
        cout<<"\n\t\tNo se encontro el archivo, asegurese de que el archivo este en la misma carpeta que el programa";
    }
    else{
        cout << "\n\t\t\tBIENVENIDO A MI PROTOTIPOP12P2022 9959-21-1581 WILLIAM OTTONIEL MAYEN VASQUEZ\n" << endl;
        cout << "\n\t\tIngrese su usuario: "; cin >> usuario;
        cout << "\n\t\tIngrese su contrasena: "; cin >> contrasena;
        usuariosContrasenas>>config1>>config2;
            if (usuario=="william" && contrasena =="9959211581"){
                empleado prueba;
                prueba.menuPrincipal();
            }
            else{
                cout << "\n\t\t\tPermiso denegado\a";
                exit(0);
            }
      }
};
