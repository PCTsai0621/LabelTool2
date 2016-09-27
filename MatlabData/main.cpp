//#include <stdio.h>
//#include <stdlib.h>

#include "MatFileProcess.h"

int main()
{
	MatFileProcess *m = new MatFileProcess();

	int result;
	char *file = "labels.mat";
	const char *parameterName = "ptsAll";

	//result = diagnose(file);
	result = m->Print3DmxArray(file, parameterName);
	/*result = 0;
	printf("Usage: matdgns <matfile>");
	printf(" where <matfile> is the name of the MAT-file");
	printf(" to be diagnosed\n");*/

	if (result == 0)	printf("Program Done\n");

	system("pause");

	return (result == 0) ? EXIT_SUCCESS : EXIT_FAILURE;


}