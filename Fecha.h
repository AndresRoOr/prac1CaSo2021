/**
 * @file	Fecha.h
 * @brief	Archivo cabecera donde se almacena toda la información relacionada con la clase Fecha.
 */

#pragma once
#ifndef FECHA_H
#define FECHA_H
#include <string>
#include <exception>

using namespace std;

/**
 * @brief Clase sencilla para representar fechas y horas.
 */
class Fecha {
	unsigned dia, mes, anio, hora, min; ///< Información de fecha y hora.
	static const unsigned diasMes[12]; ///< Almacena los dias por mes.

public:

	Fecha();

	Fecha(unsigned aDia, unsigned aMes, unsigned aAnio, unsigned aHora = 0,
			unsigned aMin = 0);

	/**
	 * @brief Constructor por copia de la clase Fecha.
	 */
	Fecha(const Fecha &f) :
			dia(f.dia), mes(f.mes), anio(f.anio), hora(f.hora), min(f.min) {
	}

	void asignarDia(unsigned aDia, unsigned aMes, unsigned aAnio);

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

	string cadenaDia() const;

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

	bool operator<(const Fecha &f);

	Fecha &operator=(const Fecha &f);

	void anadirMin(int numMin);

	void anadirHoras(int numHoras);

	void anadirDias(int numDias);

	void anadirMeses(int numMeses);

	void anadirAnios(int numAnios);

	void comprobarAnio(unsigned aDia, unsigned aMes, unsigned aAnio) const;

	void comprobarFecha(unsigned aDia, unsigned aMes, unsigned aAnio,
			unsigned aHora, unsigned aMin) const;

	void leerTiempo(const tm &t);

	void escribirTiempo(tm &t);

	/**
	 * @brief Excepción que representa fechas incorrectas.
	 */
	class ErrorFechaIncorrecta : public exception {
	public:
	    	const char* what() const throw () {
	        return "\nError: Fecha incorrecta.\n";
	    }
	};

	~Fecha();
};

ostream &operator<<(ostream &os, const Fecha &f);

#endif
