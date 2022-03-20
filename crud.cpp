#include <iostream>
#include <string.h>
using namespace std;
const char *nombre_archivo = "archivo.dat";
struct Estudiante{
	int codigo;
	char nombres[50];
	char apellidos[50];
	char direccion[50];
	int telefono;
};
void crear();
void leer();
void actualizar();
void borrar();
main(){
	leer();
	crear();
	actualizar();
	borrar();
}
void crear(){
	char continuar;
	FILE* archivo = fopen(nombre_archivo,"ab");
	Estudiante estudiante;
	string nombre,apellido,direccion;
	do{
		fflush(stdin);
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese los Nombres:";
		getline(cin,nombre);
		strcpy(estudiante.nombres,nombre.c_str());
		cout<<"Ingrese los Apellidos:";
		getline(cin,apellido);
		strcpy(estudiante.apellidos,apellido.c_str());
		cout<<"Ingrese la direccion:";
		getline(cin,direccion;
		strcpy(estudiante.direccion,direccion.c_str());
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
cin.ignore();
fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"Dese Agregar otro Estudiante (s/n):";
		cin>>continuar;
	} while ( (continuar=='s') || (continuar=='S') );
	fclose(archivo);
}
void leer(){
		system("cls");
		FILE* archivo = fopen(nombre_archivo,"rb");	
		if (!archivo){
			archivo = fopen(nombre_archivo,"w+b");	
		}
		Estudiante estudiante;
		int id=0;	
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"____________________________________________"<<endl;
		cout<<"id"<<"|"<<"Codigo"<<"|"<<"Nombres"<<"|"<<"Apellidos"<<"|"<<"direccion"<<"|"<<"Telefono"<<endl;
		do{
		cout<<"____________________________________________"<<endl;
		cout<<id<<"|"<<estudiante.codigo<<"|"<<estudiante.nombres<<"|"<<estudiante.apellidos<<"|"<<estudiante.direccion<<"|"<<estudiante.telefono<<endl;	
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		id+=1;	
		}while(feof(archivo)==0);
		fclose(archivo);
		cout<<endl;
}
void actualizar(){
	FILE* archivo = fopen(nombre_archivo,"r+b");
	int id;
	Estudiante estudiante;
	string nombre,apellido,direccion;
	cout<<"Ingres el ID que desa Modificar:";
	cin>>id;
	fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
	cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese los Nombres:";
		getline(cin,nombre);
		strcpy(estudiante.nombres,nombre.c_str());
		cout<<"Ingrese los Apellidos:";
		getline(cin,apellido);
		strcpy(estudiante.apellidos,apellido.c_str());
		cout<<"Ingrese la direccion:";
		getline(cin,direccion);
		strcpy(estudiante.direccion,direccion.c_str());
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
	
	fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	fclose(archivo);
	leer();
}
void borrar(){
	FILE *archivo, *archivo_temporal;
	int codigo;
	Estudiante estudiante;
	
	archivo_temporal=fopen (nombre_archivo, "w+b");
	archivo=fopen(nombre_archivo,"rb");
	
	cout<<"ingrese el codigo de estudiante que desea eliminar: "<<endl;
	cin>>codigo;
	
	while(fread(&estudiante,sizeof(Estudiante),1,archivo)){
		if (estudiante.codigo !=codigo);
		fwrite(&estudiante,sizeof(Estudiante),1,archivo_temporal);
	}
	fclose(archivo_temporal);
	fclose(archivo);
	
	archivo_temporal=fopen(nombre_archivo, "rb");
	archivo=fopen(nombre_archivo,"wb");
	
	while (fread(&estudiante,sizeof(Estudiante),1,archivo_temporal)){
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		
	}
	fclose(archivo_temporal);
	fclose(archivo);
	leer();
}
