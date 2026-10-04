Integrantes: Dante Pizarro y Antonio Arancibia
Rut  22216463-k  y 22313079-8
Sistema de gestion de pacientes para un hospital, desarrollado en c++

El codigo permite: cargar pacientes desde un archivo de texto ("pacientes.txt") , usar una cola para los pacientes pendientes, una lista enlazada para los distintos departamentos del hospital, cada uno con su propia cola de pacientes, una pila para el historial de atenciones.

El programa muestra un menu con las siguientes opciones : 1. Atender pacientes, 2. Ver departamentos, 3. Revisar historial de atenciones, 4. Salir

Ademas el archivo de texto "pacientes.txt" debe tener el siguiente formato: ID;Nombre;Edad;Servicio

Las instrucciones de ejecucion de nuestro codigo serian que al empezar a ejecutar nuestro codigo se muestra un menu con las 4 instrucciones anteriores. Atender pacientes agrega a los pacientes a una cola de pacientes para ser atendidos, ver departamento permite saber donde se encuentra cada paciente dependiendo de su tratamientos. Revisar el historial es como dice revisar que cliente se atendio y salir acaba de ejecutar el codigo. Y para compilar este codigo no se requiere de librerias externas por lo que solo se debe ejecutar desde la raiz del proyecto.
