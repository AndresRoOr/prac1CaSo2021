/**
 * @file Fecha.cpp
 * @brief Contiene el código fuente de todas las funciones del archivo cabecera Fecha.h
 */

#include "Fecha.h"
#include <ctime>
#include <cstdio>
#include "Fecha.h"

const unsigned Fecha::diasMes[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

/**
 * @brief Constructor por defecto de la clase Fecha.
 * Crea una fecha con la hora actual.
 */
Fecha::Fecha() {
	time_t tiempoActual;
	struct tm *fechaActual;
	time(&tiempoActual); /// Obtiene la hora actual del sistema.
	fechaActual = localtime(&tiempoActual); /// Decodifica la hora en campos separados.
	dia = fechaActual->tm_mday;
	mes = fechaActual->tm_mon + 1;
	anio = fechaActual->tm_year + 1900;
	hora = fechaActual->tm_hour;
	min = fechaActual->tm_min;
}

/**
 * @brief Constructor parametrizado de la clase Fecha.
 * Crea una fecha concreta. Devuelve una excepción ErrorFechaIncorrecta si la fecha introducida no es correcta.
 */
Fecha::Fecha(unsigned aDia, unsigned aMes, unsigned aAnio, unsigned aHora,
		unsigned aMin) {
	comprobarFecha(aDia, aMes, aAnio, aHora, aMin); /// Filtra las fechas incorrectas.
	dia = aDia;
	mes = aMes;
	anio = aAnio;
	hora = aHora;
	min = aMin;
}

/**
 * @brief Asigna un nuevo día.
 * @param [in] aDia unsigned. Nuevo día.
 * @param [in] aMes unsigned. Nuevo mes.
 * @param [in] aAnio unsigned. Nuevo año.
 */
void Fecha::asignarDia(unsigned aDia, unsigned aMes, unsigned aAnio) {
	comprobarFecha(aDia, aMes, aAnio, hora, min);
	dia = aDia;
	mes = aMes;
	anio = aAnio;
}

/**
 * @brief Asigna una nueva hora.
 * @param [in] aHora unsigned. Nueva hora.
 * @param [in] aMin unsigned. Nuevos minutos.
 */
void Fecha::asignarHora(unsigned aHora, unsigned aMin) {
	comprobarFecha(dia, mes, anio, aHora, aMin);
	hora = aHora;
	min = aMin;
}

/**
 * @brief Comparar fechas.
 * @param [in] f Fecha(dir, const).
 * @return bool. True en el caso de que la fecha actual sea menor que la fecha parámetro, false en cualquier otro caso.
 */
bool Fecha::operator<(const Fecha &f) {
	if (anio < f.anio)
		return true;
	else if (anio > f.anio)
		return false;

	if (mes < f.mes)
		return true;
	else if (mes > f.mes)
		return false;

	if (dia < f.dia)
		return true;
	else if (dia > f.dia)
		return false;

	if (hora < f.hora)
		return true;
	else if (hora > f.hora)
		return false;

	if (min < f.min)
		return true;

	return false;
}

/**
 * @brief Operador de asignación de la clase Fecha.
 * @param [in] f Fecha (const, dir). Fecha que queremos copiar.
 * @return Devuelve una nueva instancia de la clase Fecha con los datos de la Fecha pasada como parámetro.
 */
Fecha &Fecha::operator=(const Fecha &f) {
	dia = f.dia;
	mes = f.mes;
	anio = f.anio;
	hora = f.hora;
	min = f.min;
	return *this;
}

/**
 * @brief Añadir un número de minutos indicado.
 * @param [in] numMin int. Minutos que queremos incrementar.
 */
void Fecha::anadirMin(int numMin) {
	struct tm fecha;
	escribirTiempo(fecha);
	fecha.tm_min += numMin;
	mktime(&fecha);
	leerTiempo(fecha);
}

/**
 * @brief Añadir un número de horas indicado.
 * @param [in] numHoras int. Horas que queremos incrementar.
 */
void Fecha::anadirHoras(int numHoras) {
	struct tm fecha;
	escribirTiempo(fecha);
	fecha.tm_hour += numHoras;
	mktime(&fecha);
	leerTiempo(fecha);
}

/**
 * @brief Añadir un número de días indicado.
 * @param [in] numDias int. Días que queremos incrementar.
 */
void Fecha::anadirDias(int numDias) {
	struct tm fecha;
	escribirTiempo(fecha);
	fecha.tm_mday += numDias;
	mktime(&fecha);
	leerTiempo(fecha);
}

/**
 * @brief Añadir un número de meses indicado.
 * @param [in] numMeses int. Meses que queremos incrementar.
 */
void Fecha::anadirMeses(int numMeses) {
	struct tm fecha;
	escribirTiempo(fecha);
	fecha.tm_mon += numMeses;
	mktime(&fecha);
	leerTiempo(fecha);
}

/**
 * @brief Añadir un número de años indicado.
 * @param [in] numAnios int. Años que queremos incrementar.
 */
void Fecha::anadirAnios(int numAnios) {
	struct tm fecha;
	escribirTiempo(fecha);
	fecha.tm_year += numAnios;
	mktime(&fecha);
	leerTiempo(fecha);
}

/**
 * @brief Obtener una cadena con el día.
 * @return Devuelve la fecha en formato string.
 */
string Fecha::cadenaDia() const {
	char buffer[11];
	sprintf(buffer, "%u/%u/%u", dia, mes, anio);
	return string(buffer);
}


/**
 * @brief Obtener una cadena con la hora.
 * @return Devuelve la hora en formato string.
 */
string Fecha::cadenaHora() const {
	char buffer[6];
	sprintf(buffer, "%u:%u", hora, min);
	return string(buffer);
}

/**
 * @brief Destructor de la clase Fecha.
 */
Fecha::~Fecha() {
}

/**
 * @brief Comprobación de la validez de una fecha.
 * @param [in] aDia unsigned. Día de la fecha.
 * @param [in] aMes unsigned. Mes de la fecha.
 * @param [in] aAnio unsigned. Año de la fecha.
 * @param [in] aHora unsigned. Hora de la fecha.
 * @param [in] aMin unsigned. Minuto de la fecha.
 */
void Fecha::comprobarFecha(unsigned aDia, unsigned aMes, unsigned aAnio, unsigned aHora, unsigned aMin) const {
	if (aMin > 59 || aHora > 23)
		throw ErrorFechaIncorrecta();
	if (aMes < 1 || aMes > 12)
		throw ErrorFechaIncorrecta();
	if (aDia < 1 || aDia > diasMes[aMes - 1])
		throw ErrorFechaIncorrecta();
	if (aDia == 29 && aMes == 2	&& aAnio % 4 != 0)
		throw ErrorFechaIncorrecta();
}

//Si descomentas esta y la dejas tal cual esta, te baja a 9 y la de arriba, tal cual esta, te la deja en 10.
/*void Fecha::comprobarFecha(unsigned aDia, unsigned aMes, unsigned aAnio, unsigned aHora, unsigned aMin) const {

    //Array que almacenara los dias que tiene cada mes (si el ano es bisiesto, sumaremos +1 al febrero)
    unsigned diasmes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    //Comprobar si la hora, minutos son aceptables
    if(aMin == 0 or aMin >= 60 or aHora == 0 or aHora >= 24)
    	throw ErrorFechaIncorrecta();

    //Comprobar que el mes sea valido
    if(aMes < 1 or aMes > 12)
    	throw ErrorFechaIncorrecta();

    //Comprobar que el dia sea valido
    aMes = aMes-1;
    if(aDia == 0 or aDia > diasmes[aMes])
    	throw ErrorFechaIncorrecta();

    //Si ha pasado todas estas condiciones, la fecha es valida
}*/

/**
 * @brief Función auxiliar de conversión desde estructura de tiempo tm de time.h.
 * @param [out] t tm (const, dir).
 */
void Fecha::leerTiempo(const tm &t) {
	dia = t.tm_mday;
	mes = t.tm_mon + 1;
	anio = t.tm_year + 1900;
	hora = t.tm_hour;
	min = t.tm_min;
}

/**
 * @brief Función auxiliar de conversión a estructura de tiempo tm de time.h.
 * @param [out] t tm (dir).
 */
void Fecha::escribirTiempo(tm &t) {
	t.tm_mday = dia;
	t.tm_mon = mes - 1;
	t.tm_year = anio - 1900;
	t.tm_hour = hora;
	t.tm_min = min;
	t.tm_sec = 0;
}

/**
 * @brief Serialización de fechas.
 * @param [out] os ostream (dir).
 * @param [in] f Fecha(const, dir).
 * @return os ostream.
 */
ostream &operator<<(ostream &os, const Fecha &f) {
	os << f.cadena();
	return os;
}

