#include<iostream>  //Fernando Guzmán Díaz-M1948627
#include<cstdlib>   
#include<conio.h>
#include<string.h>
#include<fstream>
#include<ctime>
#include<cmath>
using namespace std;
struct cliente
{
	char nombre[30];  //No se logro guardar el getline.
	int edad;
	int tratamiento;
	double codigo;
	int costo;
	cliente* next;
};
cliente* first = NULL;
cliente* last = NULL;
cliente* auxiliar = NULL;
int accion, day, week, month, back;
char semanas[7][15] = { " Lunes", " Martes", " Miercoles" ," Jueves", " Viernes", " Sabado", " Domingo" };
char meses[12][15] = { " Enero", " Febrero", " Marzo", " Abril", " Mayo", " Junio", " Julio", " Agosto", " Septiembre", " Octubre", " Noviembre", " Diciembre" };
void agendar();  //Para redactar una cita.
void fecha();    //Fecha de la cita.
void mostrar();  //Mostrar la agenda de las citas.
void eliminar();  //Eliminar lo ya guardado de las citas.
void modificar(); //Modificar una cita redactada.
void guardar();  //Base de datos para el guardado.
void monton();  //Un calculo total.
int main()
{
	while (true)
	{
		//Manual de Usuario
		cout << "Oprima cualquier boton" << endl;
		system("pause");
		system("cls");
		
		do
		{
			system("pause");
			system("cls");
			cout << "------------------------0-------0-----------------------------I" << endl;
			cout << "-------------------------WWWWWWW------------------------------I" << endl;
			cout << "!Bienvenido al Menu!" << endl;
			cout << "--------------------------------------------------------------I" << endl;
			cout << "--------------------------------------------------------------I" << endl;
			cout << "Donde podra introducir o crear una cita dental y visualizar a un mejor detalle el pedido con sus datos." << endl;
			cout << "" << endl;
			cout << "Aqui podra leer las opciones enfrente de usted en la cual podra elegir las diferentes herramientas del sistema." << endl;
			cout << "I-------------------------------------------------------------I" << endl;
			cout << "1-Agendar Cita" << endl;
			cout << "" << endl;
			cout << "2-Ver Cita" << endl;
			cout << "" << endl;
			cout << "3-Modificar Cita" << endl;
			cout << "" << endl;
			cout << "4-Cancelar Cita" << endl;
			cout << "" << endl;
			cout << "5-Guardar Clientes" << endl;
			cout << "" << endl;
			cout << "6-Salir" << endl;
			cout << "I-------------------------------------------------------------I" << endl;
			cin >> accion;
			switch (accion)
			{
			case 1:
			{
				system("cls");
				agendar();
				system("pause");
				system("cls");
				cout << "Volveral menu\n1-Si  2-No" << endl;
				cin >> back;
			}break;
			case 2:
			{
				system("cls");
				mostrar();
				system("pause");
				system("cls");
				cout << "Volveral menu\n1-Si  2-No" << endl;
				cin >> back;
			}
			break;
			case 3:
			{
				system("cls");
				modificar();
				system("pause");
				system("cls");
				cout << "Volveral menu\n1-Si  2-No" << endl;
				cin >> back;

			}
			break;
			case 4:
			{
				system("cls");
				eliminar();
				system("pause");
				system("cls");
				cout << "Volveral menu\n1-Si  2-No" << endl;
				cin >> back;
			}
			break;
			case 5:
			{
				system("cls");
				guardar();
				system("pause");
				system("cls");
				cout << "Volveral menu\n1-Si  2-No" << endl;
				cin >> back;
			}
			break;
			case 6:
			{
				return 0;
			}
			break;
			default:
				break;
			}
		} while (back == 1);


	}
	system("pause");
	return 0;
}

void agendar()
{
	if (first != NULL) {
		last->next = new cliente;   
		last = last->next;            
	}
	else {
		first = new cliente;           
		last = first;					 
	}
	cout << "\nNombre (No se logro el guardado en Getline): ";
	cin >> last->nombre;
	cout << "\nEdad:" << endl;
	cin >> last->edad;
	cout << "\nTratamiento:" << endl;
	cout << "-Limpieza Dental(1).\n-Brackets (acomodamiento de los dientes).(2)" << endl;
	cout << "-Endodoncia.(3)\n-Implantes dentales.(4)" << endl;
	cout << "-Extraccion de muelas del juicio(5)\n-Empastes-Dentales(6)" << endl;
	cin >> last->tratamiento;
	monton();
	cout << "\nGenerando codigo de busqueda:" << endl;
	srand(time(NULL));
	printf("%d", rand());
	cout << "\nIngrese el codigo generado:";
	cin >> last->codigo;
	fecha();
	last->next = NULL;
	cout << "Cita confirmada" << endl;
}
void fecha()
{
	system("pause");
	system("cls");

	cout << "Ingrese el numero del dia(1 al 30)\n" << endl;
	cout << "";
	cin >> day;

	cout << "Ingrese el dia de la semana en numero(1 al 7)\n" << endl;
	cout << "";
	cin >> week;

	cout << "Ingrese numero del mes(1 al 12)\n" << endl;
	cout << "";
	cin >> month;
	cout << "Fecha de la cita:" << semanas[week - 1] << " " << day << " de " << meses[month - 1] << endl;
}
void mostrar()
{
	cliente* auxiliar = first;
	if (first == NULL)
	{
		cout << "Sin citas registradas" << endl;
		return;
	}

	while (auxiliar != NULL)
	{
		cout << "\ncliente:" << auxiliar->nombre << endl << "\nEdad:" << auxiliar->edad << endl << "\nFolio de registro:" << auxiliar->codigo << endl << "\nTratamiento por aplicar:" << auxiliar->tratamiento << endl;
		auxiliar = auxiliar->next;

	}

}
void modificar()
{
	cliente* auxiliar = first;
	if (first == NULL) {
		cout << "La lista esta vacia." << endl;
		return;
	}
	int clienteeliminar;
	cout << "Digite el folio a modificar" << endl;
	cin >> clienteeliminar;

	while ((auxiliar != NULL) && (auxiliar->codigo != clienteeliminar))
	{
		auxiliar = auxiliar->next;
	}
	cout << "Nombre:" << "(Antes era:" << auxiliar->nombre << ")" << endl;
	cin >> auxiliar->nombre;

	cout << "Edad:" << "(Antes era:" << auxiliar->edad << ")" << endl;
	cin >> auxiliar->edad;

	cout << "Tratamiento:" << "(Antes era:" << auxiliar->tratamiento << ")" << endl;
	cin >> auxiliar->tratamiento;

	fecha();

	cout << "Informacion Actualizada" << endl;
}
void eliminar()
{
	cliente* auxiliar = first;
	cliente* anterior = NULL;
	if (first == NULL)
	{
		cout << "Sin clientes registrados" << endl;
		return;
	}
	int citaeliminar;
	cout << "Folio del cliente a eliminar:" << endl;
	cin >> citaeliminar;
	while ((auxiliar != NULL) && (auxiliar->codigo != citaeliminar))
	{
		anterior = auxiliar;
		auxiliar = auxiliar->next;
	}
	if (first == last && auxiliar == first)
	{
		delete auxiliar;
		first = NULL;
		last = NULL;
		cout << "Informacion eliminada Exitosamente" << endl;
		return;
	}
	if (anterior == NULL)
	{
		first = auxiliar->next;
	}
	else
	{
		anterior->next = anterior->next->next;
		if (auxiliar->next == NULL)
		{
			last = anterior;
		}
	}
}
void guardar() {
	cliente* auxiliar = first;

	if (first == NULL) {
		cout << "La lista esta vacia" << endl;
		return;
	}
	char cadena[255];
	cout << "Nombre del archivo:";
	cin >> cadena;
	ofstream escribir;
	escribir.open(cadena, ios::out | ios::binary);
	if (escribir.is_open()) {
		while (auxiliar != NULL) {
			escribir.write(reinterpret_cast<char*>(auxiliar), sizeof(cliente));
			auxiliar = auxiliar->next;
		}
	}
	escribir.close();
	cout << "Guardado exitosamente." << endl << endl;
}
void monton()
{
	int precio, totalclientes;
	cout << "Vuelva a seleccionar para confirmar el servicio que desea recibir" << endl;
	cin >> last->tratamiento;
	switch (last->tratamiento)
	{
	case 1:
		precio = 350;
		cout << "Limpieza dental" << endl;
		cout << "Descripcion:\nEl objetivo es remover el sarro acumulado de tus dientes para evitar enfermedades que puedan dañarlos a largo plazo\nEsta se realiza en una clínica dental y dura aproximadamente 45 minutos." << endl;
		cout << "Precio:" << precio << endl;
		cout << "Cantidad de clientes a tratar:";
		cin >> totalclientes;
		last->costo = precio * totalclientes;
		cout << "El costo sera de:" << last->costo;
		break;

	case 2:
		precio = 1200;
		cout << "Brackets" << endl;
		cout << "Descripcion:\nson instrumentos utilizados con el objetivo de poder reparar una serie de problemas dentales\nPara corregir los dientes torcidos o volver a la posición normal aquellos que se encuentran mal ubicados." << endl;
		cout << "Precio:" << precio << endl;;
		cout << "Cantidad de clientes a tratar:";
		cin >> totalclientes;
		last->costo = precio * totalclientes;
		cout << "El costo sera de:" << last->costo;
		break;
	case 3:
		precio = 2500;
		cout << "Endodoncia" << endl;
		cout << "Descripcion:\n" << endl;
		cout << "Precio:" << precio << endl;
		cout << "Cantidad de clientes a tratar:";
		cin >> totalclientes;
		last->costo = precio * totalclientes;
		cout << "El costo sera de:" << last->costo;
		break;
	case 4:
		precio = 2800;
		cout << "Implantes Dentales" << endl;
		cout << "Descripcion:\n" << endl;
		cout << "Precio:" << precio << endl;
		cout << "Cantidad de clientes a tratar:";
		cin >> totalclientes;
		last->costo = precio * totalclientes;
		cout << "El costo sera de:" << last->costo;
		break;
	case 5:
		precio = 1500;
		cout << "Extraccion de muelas del juicio" << endl;
		cout << "Descripcion:\n" << endl;
		cout << "Precio:" << precio << endl;
		cout << "Cantidad de clientes a tratar:";
		cin >> totalclientes;
		last->costo = precio * totalclientes;
		cout << "El costo sera de:" << last->costo;
		break;
	case 6:
		precio = 2000;
		cout << "Empastes Dentales" << endl;
		cout << "Descripcion:\n" << endl;
		cout << "Precio:" << precio << endl;
		cout << "Cantidad de clientes a tratar:";
		cin >> totalclientes;
		last->costo = precio * totalclientes;
		cout << "El costo sera de:" << last->costo;
		break;
	default:
		break;
	}
}