# UGRMPBase Un repo base para la asignatura Metodología de la programación

# Preparandolo todo
-  [Videotutorial](https://drive.google.com/file/d/1VO7ib1QnUlEk1pHtn4F7D6QJwZZykgbo/view?usp=sharing) introducción a la asignatura.
- Documentos de apoyo al videotutorial para la preparación del entorno de trabajo en el ordenador. En él se describe, a rasgos generales, cómo preparar el ordenador para la asignatura e incluye enlaces a otros videotutoriales, PDF, o Webs con descripciones más precisas de cada aspecto concreto. Este documento en PDF que aparece aquí son las transparencias del videotutorial y contiene los enlaces desde los que acceder a las herramientas y documentos que se citan en el vídeo. 
  - Las transparencias del vídeo con enlaces 
  - Descargar el repo
    ```
    git clone https://github.com/Anatoli-Grishenko/UGRMPBase UGRMPBase
    ``` 
  - [Videotutorial](https://drive.google.com/file/d/1sxjvPOP9VChG-1PW2I3iZF-wVbesABo4/view?usp=sharing) Preparando el entorno de trabajo 
	- Paquetes de Linux que deben estar presentes durante las prácticas (sudo apt install) `gcc` `make`    `valgrind`     `wdiff`      `ImageMagick` `git`
 - Para aquellos que decidáis la opción de VirtualBox, el profesorado de MP hemos preparado una copia de una máquina virtual ya preparada con Linux, NetBeans y C++. Aquí tenéis las instrucciones  para instalarla. Son tres pasos muy sencillos
   - Descargar e Instalar [Virtualbox](https://www.oracle.com/emea/virtualization/solutions/try-oracle-vm-virtualbox/?source=:ad:pas:go:dg:a_emea:71700000086137880-58700007342953610-p65823631225:RC_WWMK201210P00009C0001:&SC=:ad:pas:go:dg:a_emea::RC_WWMK201210P00009C0001::&gclid=CjwKCAiAl-6PBhBCEiwAc2GOVOk47paaZegmnUyyKtx-WFrjIcTIDntJfqxW40Kk8E3DFxK2_RPZBBoCUzwQAvD_BwE&gclsrc=aw.ds)
   - Descargar la Máquina virtual de Google Drive
	 - Importar la máquina virtual y acceder a ella. Claves de acceso y la descripción paso a paso en la [guía de importación](https://github.com/Anatoli-Grishenko/UGRMPBase/blob/main/PDFs/importova.pdf)
- Y, finalmente una última opción: el servidor de imágenes virtuales de la [ETSIIT](https://turing.ugr.es/). Arrancar con Ubuntu 18. Ya tiene instalado NetBeans 11.2 y C++. 

# Secuencia de prácticas
|Comienzo | Práctica | Herramientas | Metodología
| -----| -----|-----| ----- |
|Semana1 21/feb/2022 |**Imaging0** Acceso a memoria a nivel de bit| **NetBeans 1** Entorno | Separar declaración de implementación de métodos. Métodos `const`.Parámetros por valor y por referencia. Paso de vectores a funciones y métodos |
|Semana2	28/feb/2022 | |**NetBeans 2** Compilación separada. Bibliotecas | Directivas de preprocesador. Test-Driven Development: testeo de aplicaciones y control de la calidad (QA) |
|Semana3	7/mar/2022 | **Imaging1** Tratamiento de imágenes digitales. El histograma|**NetBeans 3** Depurador | Clases con vectores estáticos. Paso de vectores a funciones y métodos |
|Semana4	14/mar/2022 | | | |
|Semana5	21/mar/2022 |**Imaging2** Guardar imágenes en disco. Segmentación de imágenes por histograma| |Acceso a datos en disco. Lectura y escritura. Errores frecuentes |
|Semana6	28/mar/2022 | | | |
|Semana7	4/abr/2022 | **Imaging3** Copiar y pegar imágenes. Binarización de imágenes. | |Uso de parámetros desde la línea de comandos |
|Semana8	11/abr/2022 |**Semana Santa**| | | 
|Semana9	18/abr/2022 | | | |
|Semana10	25/abr/2022 |**Imaging4** Uso de memoria dinámica I (arrays). Zoom in y Zoom out| **valgrind** Detección de pérdidas de memoria| Uso de memoria dinámica en C++. Arrays dinámicos. Detección de pérdidas de memoria|
|Semana11	2/may/2022 | | | |
|Semana12	9/may/2022 |**Examen de laboratorio** | | |
|Semana13	16/may/2022 |**Imaging5** Uso de memoria dinámica II (matrices bidimensionales). Esteganografía | | Matrices bidimensionales dinámicas. CStrings |
|Semana14	23/may/2022 | | | |
|Semana15	30/may/2022 | | | |
|Semana16	6/jun/2022 | | | |



