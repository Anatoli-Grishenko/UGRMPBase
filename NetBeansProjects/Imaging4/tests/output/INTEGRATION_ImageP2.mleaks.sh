#!/bin/bash
/usr/bin//valgrind --leak-check=full ./dist/Debug/GNU-Linux/imaging4 -i data/telediario.pgm -c data/kfc.pgm < ./tests/validation/INTEGRATION_ImageP2.keyboard 1> /dev/null 2>> ./tests/output/INTEGRATION_ImageP2.mleaks.full
