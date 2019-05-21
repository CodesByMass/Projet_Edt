#ifndef SGF_h
#define SGF_h

#include "../classes/les_h/Data.h"
#include <list> 
#include <iterator> 
#include <cmath> 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
using namespace std;

void ecriture_universite(Universite *u);

Universite* lecture_universite();

void conv_latex(EDT* edt);
#endif
