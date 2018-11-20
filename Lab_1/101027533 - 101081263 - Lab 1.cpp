//***************************************************************************
// 101027533 - 101081263 Lab 1.cpp by Michael Noseworthy + Boris Merlo (C) 2017 All Rights Reserved.
//
// Lab 1 submission.
//
// Description:
// Click run to see the results.
//
//***************************************************************************

#include <windows.h>
#include <DirectXMath.h>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;
using namespace DirectX;



//Checking for SSE2 support and then converting bool into true and false answers via "Yes" or "No".
void canCPUSupport()
{
	cout << "Does your program support SSE2? ";
	bool b;
	b = XMVerifyCPUSupport();
	if (b == 0)
		cout << "No" << endl;
	else if (b == 1)
		cout << "Yes" << endl;
	else
		cout << "error" << endl;


	cout << endl;
}




int main()
{
	canCPUSupport();
	//Initialize the matrix:
	
    float a00; float a01; float a02; float a03;
    float a10; float a11; float a12; float a13;
    float a20; float a21; float a22; float a23;
    float a30; float a31; float a32; float a33;

    a00 = static_cast <float>(rand() % 100);
    a01 = static_cast <float>(rand() % 100);
    a02 = static_cast <float>(rand() % 100);
    a03 = 1.0f;

    a10 = static_cast <float>(rand() % 100);
    a11 = static_cast <float>(rand() % 100);
    a12 = static_cast <float>(rand() % 100);
    a13 = 1.0f;

    a20 = static_cast <float>(rand() % 100);
    a21 = static_cast <float>(rand() % 100);
    a22 = static_cast <float>(rand() % 100);
    a23 = 1.0f;

    a30 = static_cast <float>(rand() % 100);
    a31 = static_cast <float>(rand() % 100);
    a32 = static_cast <float>(rand() % 100);
    a33 = 1.0f;

	const XMFLOAT4X4 myArray (a00,   a01,   a02,   a03,
                        a10,   a11,   a12,   a13,
                        a20,   a21,   a22,   a23,
                        a30,   a31,   a32,   a33);

	cout << internal;
	cout << "Values for myArray: " << endl;
	
	cout << "m11 = " << setw(2) << myArray._11 << " " << "m12 = " << setw(2) << myArray._12 << " " <<  "m13 = " << setw(2) << myArray._13 << " " << "m14 = " << setw(2) << myArray._14 << endl;
	cout << "m21 = " << setw(2) << myArray._21 << " " << "m22 = " << setw(2) << myArray._22 << " " <<  "m23 = " << setw(2) << myArray._23 << " " << "m24 = " << setw(2) << myArray._24 << endl;
	cout << "m31 = " << setw(2) << myArray._31 << " " << "m32 = " << setw(2) << myArray._32 << " " <<  "m33 = " << setw(2) << myArray._33 << " " << "m34 = " << setw(2) << myArray._34 << endl;
	cout << "m41 = " << setw(2) << myArray._41 << " " << "m42 = " << setw(2) << myArray._42 << " " <<  "m43 = " << setw(2) << myArray._43 << " " << "m44 = " << setw(2) << myArray._44 << endl;

	cout << endl;

	//Method 1:
	//

	cout << "Commencing Method 1 XMMatrixInverse function: " << endl << endl;
	XMMATRIX mtxHolder;
        
    mtxHolder = XMLoadFloat4x4(&myArray);
	
	//get determinant

	XMVECTOR det = XMMatrixDeterminant(mtxHolder);

	cout << "Value of DirectX Function determinant: " << *det.m128_f32 << endl << endl;

	//get Inverse
    XMMATRIX mtxInv;
	mtxInv	= XMMatrixInverse(&det, mtxHolder);

	cout << "Values for mtxInv after DirectX Function Inverse: " << endl;
	cout << "m11 = " << setw(11) << XMVectorGetX(mtxInv.r[0])  << " " << "m12 = " << setw(11) << XMVectorGetY(mtxInv.r[0])  << " " <<  "m13 = " << setw(11) << XMVectorGetZ(mtxInv.r[0])  << " " << "m14 = " << setw(11) << XMVectorGetW(mtxInv.r[0]) << endl;
	cout << "m21 = " << setw(11) << XMVectorGetX(mtxInv.r[1])  << " " << "m22 = " << setw(11) << XMVectorGetY(mtxInv.r[1])  << " " <<  "m23 = " << setw(11) << XMVectorGetZ(mtxInv.r[1])  << " " << "m24 = " << setw(11) << XMVectorGetW(mtxInv.r[1]) << endl;
	cout << "m31 = " << setw(11) << XMVectorGetX(mtxInv.r[2])  << " " << "m32 = " << setw(11) << XMVectorGetY(mtxInv.r[2])  << " " <<  "m33 = " << setw(11) << XMVectorGetZ(mtxInv.r[2])  << " " << "m34 = " << setw(11) << XMVectorGetW(mtxInv.r[2]) << endl;
	cout << "m41 = " << setw(11) << XMVectorGetX(mtxInv.r[3])  << " " << "m42 = " << setw(11) << XMVectorGetY(mtxInv.r[3])  << " " <<  "m43 = " << setw(11) << XMVectorGetZ(mtxInv.r[3])  << " " << "m44 = " << setw(11) << XMVectorGetW(mtxInv.r[3]) << endl;
	 
	cout << "Method 1 succeeded!" << endl << endl;


	//Method 2:
	//
	cout << "Commencing Method 2 Direct Math Functions: " << endl << endl;

	//primmerae columna
	float T11 = XMVectorGetX(mtxHolder.r[0]);
	float T21 = XMVectorGetX(mtxHolder.r[1]);
	float T31 = XMVectorGetX(mtxHolder.r[2]);
	float T41 = XMVectorGetX(mtxHolder.r[3]);
	//segunda columna
	float T12 = XMVectorGetY(mtxHolder.r[0]);
	float T22 = XMVectorGetY(mtxHolder.r[1]);
	float T32 = XMVectorGetY(mtxHolder.r[2]);
	float T42 = XMVectorGetY(mtxHolder.r[3]);
	//tercera columna
	float T13 = XMVectorGetZ(mtxHolder.r[0]);
	float T23 = XMVectorGetZ(mtxHolder.r[1]);
	float T33 = XMVectorGetZ(mtxHolder.r[2]);
	float T43 = XMVectorGetZ(mtxHolder.r[3]);
	//cuarte columna
	float T14 = XMVectorGetW(mtxHolder.r[0]);
	float T24 = XMVectorGetW(mtxHolder.r[0]);
	float T34 = XMVectorGetW(mtxHolder.r[0]);
	float T44 = XMVectorGetW(mtxHolder.r[0]);

	float determinant = T11 * (T22*T33*T44 + T23 * T34*T42 + T24 * T32*T43
			- T24 * T33*T42 - T23 * T32*T44 - T22 * T34*T43)
		- T21 * (T12*T33*T44 + T13 * T34*T42 + T14 * T32*T43
			- T14 * T33*T42 - T13 * T32*T44 - T12 * T34*T43)
		+ T31 * (T12*T23*T44 + T13*T24*T42 + T14*T22*T43
			- T14*T23*T42 - T13*T22*T44 - T12*T24*T43)
		- T41*(T12*T23*T34 + T13*T24*T32 + T14*T22*T33
			- T14*T23*T32 - T13*T22*T34 - T12*T24*T33);

	cout << "Calculated determinant to be: " << determinant << endl << endl;

	float M11det = T22 * T33*T44 + T23 * T34*T42 + T24 * T32 * T43
		- T24 * T33*T42 - T23* T32 * T44 - T22 * T34 *T43;
	float M12det = T21 * T33*T44 + T23 * T34*T41 + T24 * T31*T43
		- T24 * T33*T41 - T23 * T31*T44 - T21 * T34*T43;
	float M13det = T21 * T32*T44 + T22 * T34*T41 + T24 * T31*T42
		- T24 * T32*T41 - T22 * T31*T44 - T21 * T34*T42;
	float M14det = T21 * T32*T43 + T22 * T33*T41 + T23 * T31*T42
		- T23 * T32*T41 - T22 * T31*T43 - T21 * T33*T42;

	float M21det = T12 * T33*T44 + T13 * T34*T42 + T14 * T32 * T43
		- T14 * T33*T42 - T13 * T32 * T44 - T12 * T34 *T43;
	float M22det = T11 * T33*T44 + T13 * T34*T41 + T14 * T31*T43
		- T14 * T33*T41 - T13 * T31*T44 - T11 * T34*T43;
	float M23det = T11 * T32*T44 + T12 * T34*T41 + T14 * T31*T42
		- T14 * T32*T41 - T12 * T31*T44 - T11 * T34*T42;
	float M24det = T11 * T32*T43 + T12 * T33*T41 + T13 * T31*T42
		- T13 * T32*T41 - T12 * T31*T43 - T11 * T33*T42;

	float M31det = T12 * T23*T44 + T13 * T24*T42 + T14 * T22 * T43
		- T14 * T23*T42 - T13 * T22 * T44 - T12 * T24 *T43;
	float M32det = T11 * T23*T44 + T13 * T24*T41 + T14 * T21*T43
		- T14 * T23*T41 - T13 * T21*T44 - T11 * T24*T43;
	float M33det = T11 * T22*T44 + T12 * T24*T41 + T14 * T21*T42
		- T14 * T22*T41 - T12 * T21*T44 - T11 * T24*T42;
	float M34det = T11 * T22*T43 + T12 * T23*T41 + T13 * T21*T42
		- T13 * T22*T41 - T12 * T21*T43 - T11 * T23*T42;

	float M41det = T12 * T23*T34 + T13 * T24*T32 + T14 * T22 * T33
		- T14 * T23*T32 - T13 * T22 * T34 - T12 * T24 *T33;
	float M42det = T11 * T23*T34 + T13 * T24*T31 + T14 * T21*T33
		- T14 * T23*T31 - T13 * T21*T43 - T11 * T24*T33;
	float M43det = T11 * T22*T34 + T12 * T24*T31 + T14 * T21*T32
		- T14 * T22*T31 - T12 * T21*T34 - T11 * T24*T32;
	float M44det = T11 * T22*T33 + T12 * T23*T31 + T13 * T21*T32
		- T13 * T22*T31 - T12 * T21*T33 - T11 * T23*T32;

	//adjugate
	float Adj11 = static_cast <float>(pow(-1 , 1+1) * M11det);
	float Adj12 = static_cast <float>(pow(-1, 1+2) * M21det);
	float Adj13 = static_cast <float>(pow(-1, 1+3) * M31det);
	float Adj14 = static_cast <float>(pow(-1, 1+4) * M41det);
	
	float Adj21 = static_cast <float>(pow(-1, 2 + 1) * M12det);
	float Adj22 = static_cast <float>(pow(-1, 2 + 2) * M22det);
	float Adj23 = static_cast <float>(pow(-1, 2 + 3) * M32det);
	float Adj24 = static_cast <float>(pow(-1, 2 + 4) * M42det);

	float Adj31 = static_cast <float>(pow(-1, 3 + 1) * M13det);
	float Adj32 = static_cast <float>(pow(-1, 3 + 2) * M23det);
	float Adj33 = static_cast <float>(pow(-1, 3 + 3) * M33det);
	float Adj34 = static_cast <float>(pow(-1, 3 + 4) * M43det);

	float Adj41 = static_cast <float>(pow(-1, 4 + 1) * M14det);
	float Adj42 = static_cast <float>(pow(-1, 4 + 2) * M24det);
	float Adj43 = static_cast <float>(pow(-1, 4 + 3) * M34det);
	float Adj44 = static_cast <float>(pow(-1, 4 + 4) * M44det);

	float Inv11 = Adj11 / determinant;
	float Inv12 = Adj12 / determinant;
	float Inv13 = Adj13 / determinant;
	float Inv14 = Adj14 / determinant;
	//cout << "Inv11 = " << Inv11 << ", " << Inv12 << ", " << Inv13 << ", " << Inv14 <<   endl;

	float Inv21 = Adj21 / determinant;
    float Inv22 = Adj22 / determinant;
    float Inv23 = Adj23 / determinant;
    float Inv24 = Adj24 / determinant;

    float Inv31 = Adj31 / determinant;
    float Inv32 = Adj32 / determinant;
    float Inv33 = Adj33 / determinant;
    float Inv34 = Adj34 / determinant;

    float Inv41 = Adj41 / determinant;
    float Inv42 = Adj42 / determinant;
    float Inv43 = Adj43 / determinant;
    float Inv44 = Adj44 / determinant;
        
    cout << "m11 = " << setw(11) << Inv11 <<  " " << "m21 = " << setw(11) <<Inv12 << " " << "m31 = " << setw(11) <<Inv13 << " " << "m41 = " << setw(11) <<Inv14 << endl;
    cout << "m12 = " << setw(11) << Inv21 <<  " " << "m22 = " << setw(11) <<Inv22 << " " << "m32 = " << setw(11) <<Inv23 << " " << "m42 = " << setw(11) <<Inv24 << endl;
    cout << "m13 = " << setw(11) << Inv31 <<  " " << "m23 = " << setw(11) <<Inv32 << " " << "m33 = " << setw(11) <<Inv33 << " " << "m43 = " << setw(11) <<Inv34 << endl;
    cout << "m14 = " << setw(11) << Inv41 <<  " " << "m24 = " << setw(11) <<Inv42 << " " << "m34 = " << setw(11) <<Inv43 << " " << "m44 = " << setw(11) <<Inv44 << endl;

	cout << "Method 2 succeeded!" << endl << endl;

	
    return 0;

}