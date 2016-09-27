/*=================================================================
* mexatexit.c
*
* This example demonstrates how to use mexAtExit.  It allows you to
* write strings to a data file, matlab.data.  The MEX-file
* mexatexit.c registers an exit function that closes the datafile.
* The input to the MEX-file mexatexit is a string.  You may continue
* calling the function with new strings to add to the file
* matlab.data. The data file will not be closed until the MEX-file is
* cleared or MATLAB is exited, which cause the exit function to be
* executed.

* This is a MEX-file for MATLAB.
* Copyright 1984-2011 The MathWorks, Inc.
* All rights reserved.
*=================================================================*/

/* $Revision: 1.6.6.2 $ */

#include <stdio.h>
#include <string.h> /* strlen */
#include "mex.h"

static FILE  *fp = NULL;

/* Here is the exit function, which gets run when the MEX-file is
cleared and when the user exits MATLAB. The mexAtExit function
should always be declared as static. */
static void CloseStream(void)
{
	mexPrintf("Closing file matlab.data.\n");
	fclose(fp);
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	char *str;
	(void)plhs;      /* unused parameter */

	/* Check for proper number of input and output arguments */
	if (nrhs != 1) {
		mexErrMsgIdAndTxt("MATLAB:mexatexit:invalidNumInputs",
			"One input argument required.");
	}
	if (nlhs > 1){
		mexErrMsgIdAndTxt("MATLAB:mexatexit:maxrhs",
			"Too many output arguments.");
	}
	if (!(mxIsChar(prhs[0]))){
		mexErrMsgIdAndTxt("MATLAB:mexatexit:invalidInput",
			"Input must be of type string.\n.");
	}

	if (fp == NULL){
		fp = fopen("matlab.data", "w");
		if (fp == NULL){
			mexErrMsgIdAndTxt("MATLAB:mexatexit:errorOpeningFile",
				"Could not open file matlab.data.");
		}
		mexPrintf("Opening file matlab.data.\n");

		/* Register an exit function. You should only register the
		exit function after the file has been opened successfully*/
		mexAtExit(CloseStream);
	}
	/* The user passes a string in prhs[0]; write the string
	to the data file. NOTE: you must free str after it is used */
	str = mxArrayToString(prhs[0]);
	if ((size_t)fprintf(fp, "%s\n", str) != strlen(str) + 1){
		mxFree(str);
		mexErrMsgIdAndTxt("MATLAB:mexatexit:errorWritingFile",
			"Could not write data to file.\n");
	}
	mexPrintf("Writing data to file.\n");
	mxFree(str);
}
