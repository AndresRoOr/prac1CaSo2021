/**
 * @file	Fecha.h
 * @brief	Archivo cabecera donde se almacena toda la información relacionada con la clase Fecha.
 */

#pragma once
#ifndef FECHA_H
#define FECHA_H
#include <string>
using namespace std;

/**
 * @brief Clase sencilla para representar fechas y horas.
 */
class Fecha {
	unsigned dia, mes, anio, hora, min; ///< Información de fecha y hora.
	static const unsigned diasMes[12]; ///< Almacena los dias por mes.

public:

	/**
	 * @brief Constructor por defecto de la clase Fecha.
	 */
	Fecha();

	/**
	 * @brief Constructor parametrizado de la clase Fecha.
	 */
	Fecha(unsigned aDia, unsigned aMes, unsigned aAnio, unsigned aHora = 0,
			unsigned aMin = 0);

	/**
	 * @brief Constructor por copia de la clase Fecha.
	 */
	Fecha(const Fecha &f) :
			dia(f.dia), mes(f.mes), anio(f.anio), hora(f.hora), min(f.min) {
	}

	/**
	 * @brief Asigna un nuevo día.
	 */
	void asignarDia(unsigned aDia, unsigned aMes, unsigned aAnio);

	/**
	 * @brief Asigna una nueva hora.
	 */
	void asignarHora(unsigned aHora, unsigned aMin);

	/**
	 * @brief Devuelve la hora.
	 * @return hora unsigned. Atributo de la clase.
	 */
	unsigned verHora() const {
		return hora;
	}

	/**
	 * @brief Obtener minutos.
	 * @return min unsigned. Atributo de la clase.
	 */
	unsigned verMin() const {
		return min;
	}

	/**
	 * @brief Obtener día.
	 * @return dia unsigned. Atributo de la clase.
	 */
	unsigned verDia() const {
		return dia;
	}

	/**
	 * @brief Obtener mes.
	 * @return mes unsigned. Atributo de la clase.
	 */
	unsigned verMes() const {
		return mes;
	}

	/**
	 * @brief Obtener año
	 * @return anio unsigned. Atributo de la clase.
	 */
	unsigned verAnio() const {
		return anio;
	}

	/**
	 * @brief Obtener una cadena con el día.
	 */
	string cadenaDia() const;

	/**
	 * @brief Obtener una cadena con la hora.
	 */
	string cadenaHora() const;

	/**
	 * @brief Obtener una cadena con día y hora.
	 * @return Devuelve un string con toda la información de la clase.
	 */
	string cadena() const {
		return cadenaDia() + " " + cadenaHora();
	}

	/**
	 * @brief Indica si las dos fechas tienen el mismo día.
	 * @param [in] f Fecha(dir, const). Fecha que queremos comprobar.
	 * @return bool. True en el caso de que las dos fechas tengan el mismo día, false en cualquier otro caso.
	 */
	bool mismoDia(const Fecha &f) const {
		return dia == f.dia && mes == f.mes && anio == f.anio;
	}

	/**
	 * @brief Comparar fechas.
	 */
	bool operator<(const Fecha &f);

	/**
	 * @brief Operador de asignación de la clase Fecha.
	 */
	Fecha &operator=(const Fecha &f);

	/**
	 * @brief Añadir un número de minutos indicado.
	 */
	void anadirMin(int numMin);

	/**
	 * @brief Añadir un número de horas indicado.
	 */
	void anadirHoras(int numHoras);

	/**
	 * @brief Añadir un número de dias indicado.
	 */
	void anadirDias(int numDias);

	/**
	 * @brief Añadir un número de meses indicado.
	 */
	void anadirMeses(int numMeses);

	/**
	 * @brief Añadir un numero de años indicado.
	 */
	void anadirAnios(int numAnios);

	/**
	 * @brief Comprobación de la validez de una fecha.
	 */
	void comprobarFecha(unsigned aDia, unsigned aMes, unsigned aAnio,
			unsigned aHora, unsigned aMin) const;

	/**
	 * @brief Función auxiliar de conversión desde estructura de tiempo tm de time.h.
	 */
	void leerTiempo(const tm &t);

	/**
	 * @brief Función auxiliar de conversión a estructura de tiempo tm de time.h.
	 */
	void escribirTiempo(tm &t);

	/**
	 * @brief Excepción que representa fechas incorrectas.
	 */
	class ErrorFechaIncorrecta {
	};

	/**
	 * @brief Destructor de la clase Fecha.
	 */
	~Fecha();
};

/**
 * @brief Serialización de fechas.
 */
ostream &operator<<(ostream &os, const Fecha &f);

#endif
