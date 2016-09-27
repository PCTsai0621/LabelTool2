#include <iostream>
#include <math.h>
#include <engine.h>
#include <string>
#include <cmath>

#pragma comment (lib,"libmx.lib")
#pragma comment (lib,"libmat.lib")
#pragma comment (lib,"libmex.lib")
#pragma comment (lib,"libeng.lib")
using namespace std;


int main()
{
	Engine *m_pEngine;
	m_pEngine = engOpen("null");

	const int arraysize = 1000;
	const double degTored = .0174;

	double Sinarray[arraysize];
	double Cosarray[arraysize];
	double Degarray[arraysize];

	for (int iii = 0; iii < arraysize; iii++)
	{
		Degarray[iii] = iii;
		Sinarray[iii] = sin(iii*degTored);
		Cosarray[iii] = cos(iii*degTored);
	}
	
	cout << "Example 1 or 2 ?";
	char Sim = '1';
	cin >> Sim;

	if (Sim == '1')
	{
		mxArray* SIN = mxCreateDoubleMatrix(arraysize, 1, mxREAL);
		memcpy((void*)mxGetPr(SIN), (void*)Sinarray, sizeof(double)*arraysize);
		engPutVariable(m_pEngine, "SineGraph", SIN);

		mxArray* COS = mxCreateDoubleMatrix(arraysize, 1, mxREAL);
		memcpy((void*)mxGetPr(COS), (void*)Cosarray, sizeof(double)*arraysize);
		engPutVariable(m_pEngine, "CosineGraph", COS);

		mxArray* DEG = mxCreateDoubleMatrix(arraysize, 1, mxREAL);
		memcpy((void*)mxGetPr(DEG), (void*)Degarray, sizeof(double)*arraysize);
		engPutVariable(m_pEngine, "Degrees", DEG);

		engEvalString(m_pEngine, "figure('units','normalized','outerposition',[0 0 1 1]),");
		engEvalString(m_pEngine, "plot(Degrees, SineGraph,'r', Degrees, CosineGraph,'b'), grid minor, title(' Our matlab plot '),");

		system("pause");
	}
	else if (Sim == '2')
	{
		mxArray* dSIN = mxCreateDoubleMatrix(1, 1, mxREAL);
		mxArray* dCOS = mxCreateDoubleMatrix(1, 1, mxREAL);
		mxArray* dDEG = mxCreateDoubleMatrix(1, 1, mxREAL);

		double* pSIN = mxGetPr(dSIN);
		double* pCOS = mxGetPr(dCOS);
		double* pDEG = mxGetPr(dDEG);

		for (int iii = 0; iii < arraysize; iii++)
		{
			*pSIN = Sinarray[iii];
			*pCOS = Cosarray[iii];
			*pDEG = Degarray[iii];

		}
	}



}