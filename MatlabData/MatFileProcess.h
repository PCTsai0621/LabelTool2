#pragma once

#include <stdio.h>
#include <string.h> /* For strcmp() */
#include <stdlib.h> /* For EXIT_FAILURE, EXIT_SUCCESS */
#include "mat.h"

#define DEBUG 1

class MatFileProcess
{
public:
	int Print3DmxArray(char *file, const char *parameterName);
private:
	
};
