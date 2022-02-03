# UGRMPBase Un repo base para la asignatura Metodología de la programación

# Preparandolo todo
-  [Videotutorial](https://drive.google.com/file/d/1VO7ib1QnUlEk1pHtn4F7D6QJwZZykgbo/view?usp=sharing) introducción a la asignatura.
- Documentos de apoyo al videotutorial para la preparación del entorno de trabajo en el ordenador. En él se describe, a rasgos generales, cómo preparar el ordenador para la asignatura e incluye enlaces a otros videotutoriales, PDF, o Webs con descripciones más precisas de cada aspecto concreto. Este documento en PDF que aparece aquí son las transparencias del videotutorial y contiene los enlaces desde los que acceder a las herramientas y documentos que se citan en el vídeo. 
  - Las transparencias del vídeo con enlaces 
  - Descargar el repo
    ```
    git clone https://github.com/Anatoli-Grishenko/UGRMPBase UGRMPBase
    ``` 
  - Mantener el repo actualizado con los últimos cambios
    ```
    cd UGRMPbase
    git pull
    ```
  - [Videotutorial](https://drive.google.com/file/d/1sxjvPOP9VChG-1PW2I3iZF-wVbesABo4/view?usp=sharing) Preparando el entorno de trabajo 
	- Paquetes de Linux que deben estar presentes durante las prácticas (sudo apt install) `gcc` `make`    `valgrind`     `wdiff`  `doxygen`    `ImageMagick` `git`
 - Para aquellos que decidáis la opción de VirtualBox, el profesorado de MP hemos preparado una copia de una máquina virtual ya preparada con Linux, NetBeans y C++. Aquí tenéis las instrucciones  para instalarla. Son tres pasos muy sencillos
   - Descargar e Instalar [Virtualbox](https://www.oracle.com/emea/virtualization/solutions/try-oracle-vm-virtualbox/?source=:ad:pas:go:dg:a_emea:71700000086137880-58700007342953610-p65823631225:RC_WWMK201210P00009C0001:&SC=:ad:pas:go:dg:a_emea::RC_WWMK201210P00009C0001::&gclid=CjwKCAiAl-6PBhBCEiwAc2GOVOk47paaZegmnUyyKtx-WFrjIcTIDntJfqxW40Kk8E3DFxK2_RPZBBoCUzwQAvD_BwE&gclsrc=aw.ds)
   - Descargar la Máquina virtual oficial de la asignatura de Google Drive. Es una versión de `Ubuntu 20` conocida como `LUbuntu 20` la cual ya vien empaquetada para consumir la mínima cantidad de recursos dado que se va a usar dentro de una VirtualBox sobre Windows. Esta imagen ya está configurada para la asignatura MP y lleva todo el software necesario instalado.
   - Importar la máquina virtual  y acceder a ella. [guía de importación](https://github.com/Anatoli-Grishenko/UGRMPBase/blob/main/PDFs/importova.pdf)
   - Usuario `mp`
   - Password `.CambiaEsto`
- Y, finalmente una última opción: el servidor de imágenes virtuales de la [ETSIIT](https://turing.ugr.es/). Arrancar con Ubuntu 18. Ya tiene instalado NetBeans 11.2 y C++. 

# Secuencia de prácticas
|Comienzo | Práctica | Herramientas | Metodología
| -----| -----|-----| ----- |
|Semana1 21/feb/2022 |[**Imaging0**](https://github.com/Anatoli-Grishenko/UGRMPBase/blob/main/PDFs/Imaging0.pdf) Acceso a memoria a nivel de bit| [**NetBeans 1**](https://github.com/Anatoli-Grishenko/UGRMPBase/blob/main/PDFs/netbeans.pdf) Entorno | Separar declaración de implementación de métodos. Métodos `const`.Parámetros por valor y por referencia. Paso de vectores a funciones y métodos |
|Semana2	28/feb/2022 | |[**NetBeans 2**](https://github.com/Anatoli-Grishenko/UGRMPBase/blob/main/PDFs/netbeans.pdf) Compilación separada. Bibliotecas | Directivas de preprocesador. Test-Driven Development: testeo de aplicaciones y control de la calidad (QA) |
|Semana3	7/mar/2022 | [**Imaging1**](https://github.com/Anatoli-Grishenko/UGRMPBase/blob/main/PDFs/Imaging1.pdf)  Tratamiento de imágenes digitales. El histograma|[**NetBeans 3**](https://github.com/Anatoli-Grishenko/UGRMPBase/blob/main/PDFs/netbeans.pdf) Depurador | Clases con vectores estáticos. Paso de vectores a funciones y métodos |
|Semana4	14/mar/2022 | | | |
|Semana5	21/mar/2022 |[**Imaging2**](https://github.com/Anatoli-Grishenko/UGRMPBase/blob/main/PDFs/Imaging2.pdf) Guardar imágenes en disco. Segmentación de imágenes por histograma| |Acceso a datos en disco. Lectura y escritura. Errores frecuentes |
|Semana6	28/mar/2022 | | | |
|Semana7	4/abr/2022 | [**Imaging3**](https://github.com/Anatoli-Grishenko/UGRMPBase/blob/main/PDFs/Imaging3.pdf) Copiar y pegar imágenes. Binarización de imágenes. | |Uso de parámetros desde la línea de comandos |
|Semana8	11/abr/2022 |**Semana Santa**| | | 
|Semana9	18/abr/2022 | | | |
|Semana10	25/abr/2022 |[**Imaging4**](https://github.com/Anatoli-Grishenko/UGRMPBase/blob/main/PDFs/Imaging4.pdf) Uso de memoria dinámica I (arrays). Zoom in y Zoom out| [**valgrind**](https://github.com/Anatoli-Grishenko/UGRMPBase/blob/main/PDFs/valgrind.pdf) Detección de pérdidas de memoria| Uso de memoria dinámica en C++. Arrays dinámicos. Detección de pérdidas de memoria|
|Semana11	2/may/2022 | | | |
|Semana12	9/may/2022 |**Examen de laboratorio** | | |
|Semana13	16/may/2022 |[**Imaging5**](https://github.com/Anatoli-Grishenko/UGRMPBase/blob/main/PDFs/Imaging5.pdf) Uso de memoria dinámica II (matrices bidimensionales). Esteganografía | | Matrices bidimensionales dinámicas. CStrings |
|Semana14	23/may/2022 | | | |
|Semana15	30/may/2022 | | | |
|Semana16	6/jun/2022 | | | |

# Técnicas, herramientas y metodologías de prácticas

En esta sección encontrarás manuales y videotutoriales sobre temas específicos de las prácticas que irán complementando al tema principal de la práctica.

## El entorno de desarrollo NetBeans
NetBeans es un entorno de desarrollo integrado libre y multiplataforma, creado principalmente para el lenguaje de programación Java, pero que ofrece soporte para otros muchos lenguajes de programación. Existe además un número importante de módulos para extenderlo. NetBeans es un producto libre y gratuito sin restricciones de uso. 
- [Manual de referencia](https://github.com/Anatoli-Grishenko/UGRMPBase/blob/main/PDFs/netbeans.pdf)


## Documentación con Doxygen

Doxygen es un programa de apoyo a la documentación (comentarios) de proyectos de software que usa una sintaxis de anotación de los comentarios en el código que podríamos llamar, estándar, y común a otros lenguajes.

- [Manual de doxygen](https://github.com/Anatoli-Grishenko/UGRMPBase/blob/main/PDFs/doxygen.pdf)
- [Videotutorial](https://drive.google.com/drive/u/1/folders/1Ki1RYMaBIORurj7MiQUqWsCBt_lsbPfv) 

## Compilación separada
Es una metodología de desarrollo de proyectos de software que divide el proyecto en unidades funcionales, llamados módulos o paquetes o bibliotecas (librerías), que se compilan por separado y se enlazan en un único fichero

- Primera parte.De un proyecto monolítico a un proyecto modularizado.
  - Proyecto NetBeans `MPGeometry` monolítico
  - [Videotutorial]( https://drive.google.com/file/d/1-KiBquuuHJ5_zNeSLqWH88PqazuoTVmy/view?usp=sharin) modularización y compilación  separada
  - Proyecto NetBeans MPGeometry modularizado `MPGeometry_MOD.zip`
- Segunda parte.Uso de bibliotecas (librerías)
  - [Videotutorial](https://drive.google.com/file/d/1m9pC3XWjz6BS9Srfu_4B_Bimw_jfw5xP/view?usp=sharing)

## Test-Driven Development

Es una metodología de desarrollo de proyectos software en la que primero se definen los tests de validez que debe pasar el proyecto y después es cuando se codifica el proyecto. Un proyecto se considera válido si pasa todos los tests previstos.

- Introducción a Test-Driven Development. [Videotutorial](https://drive.google.com/file/d/132dXXwUCx0Jrrzq2S2y2BN6lLsvEGrPJ/view?usp=sharing)
- Creando el proyecto. [Videotutorial](https://drive.google.com/file/d/1V7FCuVPR1PQ5GM-jU_s44neWG6RZwKZp/view?usp=sharing)
- Pasar los primeros tests unitarios . [Videotutorial](https://drive.google.com/file/d/1VWcj4jr0keKv0-Gy_Mz9JRmSpbCpPAWq/view?usp=sharing)
- Pasar todos los tests unitarios. [Videotutorial](https://drive.google.com/file/d/1R0zEd_yxQ51Yo0N3VTNH-s7pYzgefXMg/view?usp=sharing)
- Los tests de integración. [Videotutorial](https://drive.google.com/file/d/13weHJA5zQhC9YADoqyVhUHxc7WHoPE1O/view?usp=sharing)
- Proyecto `MyVector`  
- [Manual completo TDD](https://github.com/Anatoli-Grishenko/UGRMPBase/blob/main/PDFs/TDDGTEST_V2.pdf)

# Depuración de programas
El depurador es una herramienta que suele estar incorporada en los IDE (Integrated Development Environment) como NetBeans. Se utiliza para ejecutar el programa paso a paso e intentar encontrar errores en el código.

- Manual sobre el [depurador de NetBeans](https://github.com/Anatoli-Grishenko/UGRMPBase/blob/main/PDFs/Debugger.pdf)
- [Videotutorial 1](https://drive.google.com/file/d/1vtFSsMQKnaHpsGD25TCPHCAdmDVJ_a1k/view?usp=sharing)
- [Videotutorial 2](https://drive.google.com/file/d/1cStDUlagLLo_UQk5HOvZNWuqg3dxxCNl/view?usp=sharing)
- Proyectos de NetBeans para depurar incluídos en el videotutorial: `Debugger1` `Debugger2` `Debugger3`

## Detección de pérdidas de memoria y errores en la gestión de la memoria
Valgrind y Dr Memory son herramientas para la detección, sobre todo, de pérdidas de memoria, pero también de otros problemas de gestión de la memoria dinámica.

- Manual sobre el uso de [Valgrind](https://github.com/Anatoli-Grishenko/UGRMPBase/blob/main/PDFs/valgrind.pdf)
- Manual sobre el uso de [Dr Memory](https://github.com/Anatoli-Grishenko/UGRMPBase/blob/main/PDFs/drmemory.pdf)
- Proyecto Interactivo `ValgrindShowcase`
  - Descomprimir
  - Cargar en Netbeans
  - Ejecutar y seguir las instrucciones. Se puede volver a empezar de nuevo sin más que descomprimir de nuevo.

# Manejo de ficheros de texto (muy básico)
Los ficheros de texto permiten almacenar datos que  pueden leer los programas de forma masiva para procesarlos. Este apartado es una (muy breve) introducción al manejo de ficheros que se verá en teoría.

- Manual sobre el manejo (muy básico) de [ficheros de texto](https://github.com/Anatoli-Grishenko/UGRMPBase/blob/main/PDFs/Ficheros.pdf)
- Videotutorial 1. [Ficheros de entrada](https://drive.google.com/file/d/1A3ToJaVXrF1k2bl0dz2xz1e3Hu4arvR8/view?usp=sharing)
- Videotutorial 2. [Ficheros de salida](https://drive.google.com/file/d/1xllMQyf0sQP-cfrGSabFi5shA4bUzMZc/view?usp=sharing)
- Videotutorial 3. Gestión de [errores en el manejo de ficheros](https://drive.google.com/file/d/19us64WCMXZyEd5um_MuZpLp5IqQU3nMV/view?usp=sharing)

## Paso de argumentos a la función main()

Esta es una técnica muy habitual para introducir datos en un programa desde la línea de comandos. Absolutamente imprescindible en programas de consola de Linux/Unix.

- Manual sobre el [paso de argumentos a main()](https://github.com/Anatoli-Grishenko/UGRMPBase/blob/main/PDFs/ArgumentosMain.pdf)
- [Videotutorial 1](https://drive.google.com/file/d/1xlVzVTwbFSWfhdaHGgNSq67bQo0c46nJ/view?usp=sharing)
- [Videotutorial 2](https://drive.google.com/file/d/1HaYIyECXYuZ1FAMSlSB1P7PSj9qCXlXG/view?usp=sharing)

# Manejo de errores y excepciones 
Breve introducción a la gestión de señales de error durante la ejecución de un programa y la gestión controlada de estos mediante el uso de excepciones. Videotutorial 

- Manejo de señales de error. [Videotutorial](https://drive.google.com/file/d/1U0pBUxBrklBKLkZcgsIkClCeQxyf1Bv0/view?usp=sharing)
- Manejo de excepciones [Videotutorial](https://drive.google.com/file/d/1aPJP1ft4OiQZED2dVGs7pbzy3nf7kQ1J/view?usp=sharing)





