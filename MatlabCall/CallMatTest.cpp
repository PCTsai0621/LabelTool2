#include <stdio.h>
#include <stdlib.h>
#include "mat.h"

#define DEBUG 1
double *mxData_label, *mxData_log;



int diagnose(char *file)
{
	MATFile *pmat;
	const char **dir;
	const char *name;
	int	  ndir;
	int	  i;
	mxArray *pa;

	/*
	* Open file to get directory
	*/
	pmat = matOpen(file, "r");
	if (pmat == NULL) {
		printf("Error opening file %s\n", file);
		return(1);
	}
	
	/*
	* get directory of MAT-file
	*/
	dir = (const char **)matGetDir(pmat, &ndir);
	if (dir == NULL) {
		printf("Error reading directory of file %s\n", file);
		return(1);
	}
	else {
		printf("Directory of %s:\n", file);
		for (i = 0; i < ndir; i++)
			printf("%s\n", dir[i]);
	}
	mxFree(dir);

	/* In order to use matGetNextXXX correctly, reopen file to read in headers. */
	if (matClose(pmat) != 0) {
		printf("Error closing file %s\n", file);
		return(1);
	}
	pmat = matOpen(file, "r");
	if (pmat == NULL) {
		printf("Error reopening file %s\n", file);
		return(1);
	}

	/* Get headers of all variables */
	printf("\nExamining the header for each variable:\n");
	for (i = 0; i < ndir; i++) {
		pa = matGetNextVariableInfo(pmat, &name);
		if (pa == NULL) {
			printf("Error reading in file %s\n", file);
			return(1);
		}
		/* Diagnose header pa */
		printf("According to its header, array %s has %d dimensions\n",
			name, mxGetNumberOfDimensions(pa));
		if (mxIsFromGlobalWS(pa))
			printf("  and was a global variable when saved\n");
		else
			printf("  and was a local variable when saved\n");
		mxDestroyArray(pa);
	}

	/* Reopen file to read in actual arrays. */
	if (matClose(pmat) != 0) {
		printf("Error closing file %s\n", file);
		return(1);
	}
	pmat = matOpen(file, "r");
	if (pmat == NULL) {
		printf("Error reopening file %s\n", file);
		return(1);
	}

	/* Read in each array. */
	printf("\nReading in the actual array contents:\n");
	for (i = 0; i<ndir; i++) {
		pa = matGetNextVariable(pmat, &name);
		if (pa == NULL) {
			printf("Error reading in file %s\n", file);
			return(1);
		}
		/*
		* Diagnose array pa
		*/
		printf("According to its contents, array %s has %d dimensions\n",
			name, mxGetNumberOfDimensions(pa));
		if (mxIsFromGlobalWS(pa))
			printf("  and was a global variable when saved\n");
		else
			printf("  and was a local variable when saved\n");
		mxDestroyArray(pa);
	}

	if (matClose(pmat) != 0) {
		printf("Error closing file %s\n", file);
		return(1);
	}
	printf("Done\n");

	return 0;
}

/*Print out the 3D array data of the input mat file*/
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
	if (mxGetNumberOfDimensions(pa1) != 2) {
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
	if ((dims[0] & dims[1] & dims[2]) == 0 )
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

/* Analyze field FNAME in struct array SPTR. */
static void analyzestructarray(const mxArray *sPtr, const char *fName)
{
	mwSize nElements;       /* number of elements in array */
	mwIndex eIdx;           /* element index */
	const mxArray *fPtr;    /* field pointer */
	double *realPtr;        /* pointer to data */
	double total;           /* value to calculate */
	total = 0;
	nElements = (mwSize)mxGetNumberOfElements(sPtr);

	int nDim;
	const mwSize *dims;
	int row, col, z;
	mxClassID classid;
	//nDim = mxGetNumberOfDimensions(pa1);
	

	printf("Element of struct array is: %d\n", nElements);

	for (eIdx = 0; eIdx < nElements; eIdx++) {

		fPtr = mxGetField(sPtr, eIdx, fName);
		dims = mxGetDimensions(fPtr);
		classid = mxGetClassID(fPtr);

		if ((fPtr != NULL)
			&& ( classid == mxDOUBLE_CLASS)
			&& (!mxIsComplex(fPtr)))
		{
			
			printf("The Data is Double Array\n\n");
			double *mxData = (double*)mxGetData(fPtr);
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

		printf("The field %s of %dth of labels is complex? %d\n", fName, eIdx+1, mxIsComplex(fPtr));
	}
	//printf("Total for %s: %.2f\n", fName, total);
}

/* Find struct array ARR in MAT-file FILE.
* Pass field name FIELD to analyzestructarray function. */
int findstructure(
	const char *file,
	const char *arr,
	const char *field, 
	double *mxData,
	const mwSize *dims) {

	MATFile *mfPtr; /* MAT-file pointer */
	mxArray *aPtr;  /* mxArray pointer */

	mfPtr = matOpen(file, "r");
	if (mfPtr == NULL) {
		printf("Error opening file %s\n", file);
		return(1);
	}

	aPtr = matGetVariable(mfPtr, arr);
	if (aPtr == NULL) {
		printf("mxArray not found: %s\n", arr);
		return(1);
	}

	if (mxGetClassID(aPtr) == mxSTRUCT_CLASS) {
		if (mxGetFieldNumber(aPtr, field) == -1) {
			printf("Field not found: %s\n", field);
		}
		else {
			analyzestructarray(aPtr, field);
		}
	}
	else {
		printf("%s is not a structure\n", arr);
	}
	mxDestroyArray(aPtr);

	if (matClose(mfPtr) != 0) {
		printf("Error closing file %s\n", file);
		return(1);
	}
	return(0);
}

int main()
{
	int result_label, result_log, result;
	char *file_label = "MOMO_more.mat";
	const char *parameterName_label = "labels";
	const char *field_label1 = "ptsAll";

	char *file_log = "MOMO_more.mat";
	const char *parameterName_log = "labels";
	const char *field_log1 = "ptsAll";
	
	//result = diagnose(file);
	//result = Print3DmxArray(file, parameterName);
	result_label = findstructure(file_label, parameterName_label, field_label1);
	result_log = findstructure(file_log, parameterName_log, field_log1);



	result = result_label | result_log;
	/*result = 0;
	printf("Usage: matdgns <matfile>");
	printf(" where <matfile> is the name of the MAT-file");
	printf(" to be diagnosed\n");*/
	
	if ((result_label == 0) && (result_log == 0))	printf("Program Done\n");

	system("pause");

	return (result == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}