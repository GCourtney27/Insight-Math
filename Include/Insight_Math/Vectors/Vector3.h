/*
	Header - Vector3.h
	Source - None

	Author - Garrett Courtney

	Description:
	Represents Vector3's with different data layouts.

*/

#pragma once

#include "Framework/Vector3_Base.h"
#include "Insight_Math/Primative_Types.h"

namespace InsightMath
{

	// ------------------------
	//	Floating Point Vectors |
	// ------------------------

	/*
		A vector with 3 32-bit floating point components.
	*/
	typedef Vector3Base_t<Float> FVector3;

	/*
		A vector with 3 double precision floating components.
	*/
	typedef Vector3Base_t<Double> DVector3;



	// -------------------------
	//		Integer Vectors		|
	// -------------------------

	// Unsigned Int Vectors
	// --------------------

	/*
		A vector with 3 8-bit unsigned integer components.
	*/
	typedef Vector3Base_t<UInt8> U8Vector3;

	/*
		A vector with 3 16-bit unsigned integer components.
	*/
	typedef Vector3Base_t<UInt16> U16Vector3;

	/*
		A vector with 3 32-bit unsigned integer components.
	*/
	typedef Vector3Base_t<UInt32> U32Vector3;

	/*
		A vector with 3 64-bit unsigned integer components.
	*/
	typedef Vector3Base_t<UInt64> U64Vector3;

	// Signed Int Vectors
	// ------------------

	/*
		A vector with 3 8-bit signed integer components.
	*/
	typedef Vector3Base_t<Int8> I8Vector3;

	/*
		A vector with 3 16-bit signed integer components.
	*/
	typedef Vector3Base_t<Int16> I16Vector3;

	/*
		A vector with 3 32-bit signed integer components.
	*/
	typedef Vector3Base_t<Int32> IVector3;

	/*
		A vector with 3 64-bit signed integer components.
	*/
	typedef Vector3Base_t<Int64> I64Vector3;


}

// eof