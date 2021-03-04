################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Aplication.cpp \
../Biblioteca.cpp \
../Fecha.cpp \
../Libro.cpp \
../PedidoBiblioteca.cpp \
../PedidoUsuario.cpp \
../Usuario.cpp \
../main.cpp 

OBJS += \
./Aplication.o \
./Biblioteca.o \
./Fecha.o \
./Libro.o \
./PedidoBiblioteca.o \
./PedidoUsuario.o \
./Usuario.o \
./main.o 

CPP_DEPS += \
./Aplication.d \
./Biblioteca.d \
./Fecha.d \
./Libro.d \
./PedidoBiblioteca.d \
./PedidoUsuario.d \
./Usuario.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


