# Biblioteca S4ALib
Biblioteca para el **S4A EDU Robotic Controller**.

## Autor
Jorge Villalobos Carvajal - Marzo.2018

## Uso
Se declara una variable con el tipo de la biblioteca y se inicializa por medio del método **begin** en el **setup** del sketch.
#### Ejemplo
```
#include <S4ALib.h>

S4ALib Robot;

void setup() {
  Robot.begin();
}  // setup

void loop() {
  robot.forward(500);
  robot.left(500);
  robot.right(500);
  robot.backward(500);
}
```

## Métodos de la biblioteca
Método | Descripción
------ | -----------
begin() | Inicializa los puertos del controlador (usar en el setup del sketch)
forward() | Se desplaza hacia adelante
forward(int ms) | Se desplaza hacia adelante por **_ms_** milisegundos y se detiene
backward() | Se desplaza hacia atrás
backward(int ms) | Se desplaza hacia atrás por **_ms_** milisegundos y se detiene
left() | Gira hacia la izquierda
left(int ms) | Gira hacia la izquierda por **_ms_** milisegundos y se detiene
right() | Gira hacia la derecha
right(int ms) | Gira hacia la derecha por **_ms_** milisegundos y se detiene
stop() | Detiene ambos motores, estableciendo su velocidad en 0.
ledOn() | Enciende el led incorporado
ledOff() | Apaga el led incorporado
blink(int ms) | Realiza un parpadeo del led incorporado por **_ms_** milisegundos
setMotors(bool leftVal, bool rightVal) | Establece la dirección de los motores (**LOW** = hacia adelante, **HIGH** = hacia atrás)
setSpeed(int leftVal, int rightVal) | Establece la velocidad de los motores (valores entre 0 y 255)

## Recomendaciones
- Si va a utilizar el header para comunicaciones, recuerde quitar el dispositivo que tenga conectado antes de cargar el sketch.
- Una vez cargado el sketch, se debe utilizar la alimentación externa (**6V - 9V**) y mover el switch de encendido a la posición **ON**.
- Se puede utilizar la placa **Duemilanove or Diecimila, ATmega328P** o descargar en el administrador de placas

![Instalacion placa](/images/DriversPlaca.png)


## Licencia
Este proyecto ha sido liberado bajo la licencia: **MIT License**
