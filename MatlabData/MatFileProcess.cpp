#pragma once

#include "MatFileProcess.h"

int Print3DmxArray(char *file, const char *parameterName)
{
	MATFile *pmat;
	const mxArray *pa1;
	
	//	int status;

	pmat = matOpen(file, "r");
	if (pmat == NULL) {
		printf("Error reopening file %s\n", file);
		return(EXIT_FAILURE);
	}

	pa1 = matGetVariable(pmat, parameterName);
	if (pa1 == NULL) {
		printf("Error reading existing matrix ptsAll\n");
		return(EXIT_FAILURE);
	}
	if (mxGetNumberOfDimensions(pa1) != 3) {
		printf("Error saving matrix: result does not have two dimensions\n");
		return(EXIT_FAILURE);
	}

	int nDim;
	const mwSize *dims;
	int row, col, z;
	mxClassID classid;

	classid = mxGetClassID(pa1);
	nDim = mxGetNumberOfDimensions(pa1);
	dims = mxGetDimensions(pa1);

	/*DEBUG BLOCK*/
	if (DEBUG == 1)
	{
		printf("*************************\n");
		printf("*******DEBUG MODE********\n");
		printf("*************************\n\n");

		printf("Input Mat File: %s\n", file);
		printf("3D Array Name: %s\n\n", parameterName);

		printf("The Variable \"classid\" is: %d\n", classid);
		printf("The %s Dimensions is: %d\n", parameterName, nDim);
		printf("The Dimensions is: %d x %d x %d\n\n", dims[0], dims[1], dims[2]);

		printf("*************************\n");
		printf("*****END DEBUG MODE******\n");
		printf("*************************\n\n");
	}

	/*Check if the data is error when reading*/
	if ((dims[0] & dims[1] & dims[2]) == 0)
	{
		printf("Error for Empty Data Format \n");
		return(EXIT_FAILURE);
	}

	/*Read as unsigned char array*/
	if (classid == mxUINT8_CLASS) {
		printf("The Data is unsigned char Array\n\n");
		unsigned char *mxData = (unsigned char*)mxGetData(pa1);
		for (z = 0; z < dims[2]; z++) {
			for (row = 0; row < dims[0]; row++) {
				for (col = 0; col < dims[1]; col++) {
					printf("%d ", mxData[
						dims[0] * dims[1] * z + dims[0] * col + row]);
				}
				printf("\n");
			}
			printf("\n");
		}
	}

	/*Read as Double array*/
	else if (classid == mxDOUBLE_CLASS) {
		printf("The Data is Double Array\n\n");
		double *mxData = (double*)mxGetData(pa1);
		for (z = 0; z < dims[2]; z++) {
			for (row = 0; row < dims[0]; row++) {
				for (col = 0; col < dims[1]; col++) {
					printf("%lf ", mxData[
						dims[0] * dims[1] * z + dims[0] * col + row]);
				}
				printf("\n");
			}
			printf("\n");
		}
	}

	/*Read as Float array*/
	else if (classid == mxSINGLE_CLASS) {
		printf("The Data is float Array\n\n");
		float *mxData = (float*)mxGetData(pa1);
		for (z = 0; z < dims[2]; z++) {
			for (row = 0; row < dims[0]; row++) {
				for (col = 0; col < dims[1]; col++) {
					printf("%lf ", mxData[
						dims[0] * dims[1] * z + dims[0] * col + row]);
				}
				printf("\n");
			}
			printf("\n");
		}
	}

	return 0;

}