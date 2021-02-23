/**
 * @file	Fecha.h
 * @brief	Archivo cabecera donde se almacena toda la información relacionada con la clase Fecha
 */

#pragma once
#ifndef FECHA_H
#define FECHA_H
#include <string>
using namespace std;

/**
 * @brief Excepción que representa fechas incorrectas
 */
class ErrorFechaIncorrecta {
};

/**
 * @brief Clase sencilla para representar fechas y horas
 */
class Fecha {
	unsigned dia, mes, anio, hora, min; ///< Información de fecha y hora
	static const unsigned diasMes[12]; ///< Almacena los días por mes

	/**
	 * @brief Comprobación de la validez de una fecha
	 */
	void comprobarFecha(unsigned aDia, unsigned aMes, unsigned aAnio,
			unsigned aHora, unsigned aMin) const;

	/**
	 * @brief Función auxiliar de conversión desde estructura de tiempo tm de time.h
	 */
	void leerTiempo(const tm &t);

	/**
	 * @brief Función auxiliar de conversión a estructura de tiempo tm de time.h
	 */
	void escribirTiempo(tm &t);

public:

	/**
	 * @brief Constructor por defecto de la clase Fecha
	 *
	 * Crea una fecha con la hora actual
	 */
	Fecha();

	/**
	 * @brief Constructor parametrizado de la clase Fecha
	 *
	 * Crea una fecha concreta. Devuelve una excepción ErrorFechaIncorrecta si la fecha introducida no es correcta
	 */
	Fecha(unsigned aDia, unsigned aMes, unsigned aAnio, unsigned aHora = 0,
			unsigned aMin = 0);

	/**
	 * @brief Constructor por copia de la clase Fecha
	 */
	Fecha(const Fecha &f) :
			dia(f.dia), mes(f.mes), anio(f.anio), hora(f.hora), min(f.min) {
	}

	/**
	 * @brief Asigna un nuevo día
	 * @param [in] aDia unsigned.
	 * @param [in] aMes unsigned.
	 * @param [in] aAnio unsigned.
	 */
	void asignarDia(unsigned aDia, unsigned aMes, unsigned aAnio);

	/**
	 * @brief Asigna una nueva hora
	 * @param [in] aHora unsigned.
	 * @param [in] aMin unsigned.
	 */
	void asignarHora(unsigned aHora, unsigned aMin);

	/**
	 * @brief Devuelve la hora
	 * @return hora unsigned.
	 */
	unsigned verHora() const {
		return hora;
	}

	/**
	 * @brief Obtener minutos
	 * @return min unsigned.
	 */
	unsigned verMin() const {
		return min;
	}

	/**
	 * @brief Obtener dia
	 * @return dia unsigned.
	 */
	unsigned verDia() const {
		return dia;
	}

	/**
	 * @brief Obtener mes
	 * @return mes unsigned.
	 */
	unsigned verMes() const {
		return mes;
	}

	/**
	 * @brief Obtener año
	 * @return anio unsigned
	 */
	unsigned verAnio() const {
		return anio;
	}

	/**
	 * @brief Obtener una cadena con el día
	 * @return
	 */
	string cadenaDia() const;

	/**
	 * @brief Obtener una cadena con la hora
	 * @return
	 */
	string cadenaHora() const;

	/**
	 * @brief Obtener una cadena con día y hora
	 * @return
	 */
	string cadena() const {
		return cadenaDia() + " " + cadenaHora();
	}

	/**
	 * @brief Indica si las dos fechas tienen el mismo día
	 * @param [in] f Fecha(dir, const).
	 * @return
	 */
	bool mismoDia(const Fecha &f) const {
		return dia == f.dia && mes == f.mes && anio == f.anio;
	}

	/**
	 * @brief Comparar fechas
	 * @param [in] f Fecha(dir, const).
	 * @return
	 */
	bool operator<(const Fecha &f);

	/**
	 * @brief Operador de asignación de la clase Fecha
	 * @param [in] f Fehca(const, dir)
	 * @return Devuelve una nueva instancia de la clase Fecha con los datos de la Fecha pasada como parámetro.
	 */
	Fecha &operator=(const Fecha &f);

	/**
	 * @brief Añadir un número de minutos indicado
	 * @param [in] numMin int.
	 */
	void anadirMin(int numMin);

	/**
	 * @brief Añadir un número de horas indicado
	 * @param [in] numHoras int.
	 */
	void anadirHoras(int numHoras);

	/**
	 * @brief Añadir un número de días indicado
	 * @param [in] numDias int.
	 */
	void anadirDias(int numDias);

	/**
	 * @brief Añadir un número de meses indicado
	 * @param [in] numMeses
	 */
	void anadirMeses(int numMeses);

	/**
	 * @brief Añadir un número de años indicado
	 * @param [in] numAnios int.
	 */
	void anadirAnios(int numAnios);

	/**
	 * @brief Destructor de la clase Fecha
	 */
	~Fecha();
};

/**
 * @brief Serialización de fechas
 * @param os ostream(dir).
 * @param f Fecha(const, dir).
 * @return
 */
ostream &operator<<(ostream &os, const Fecha &f);

#endif
