/*
	Header - Vector2.h
	Source - None

	Author - Garrett Courtney

	Description:
	Represents Vector2's with different data layouts.

*/

#pragma once

#include "Framework/Vector2_Base.h"
#include "Insight_Math/Primative_Types.h"

namespace InsightMath
{

	// ------------------------
	//	Floating Point Vectors |
	// ------------------------

	/*
		A vector with 2 32-bit floating point components.
	*/
	typedef Vector2Base_t<Float> FVector2;

	/*
		A vector with 2 double precision floating components.
	*/
	typedef Vector2Base_t<Double> DVector2;



	// -------------------------
	//		Integer Vectors		|
	// -------------------------

	// Unsigned Int Vectors
	// --------------------

	/*
		A vector with 2 8-bit unsigned integer components.
	*/
	typedef Vector2Base_t<UInt8> U8Vector2;

	/*
		A vector with 2 16-bit unsigned integer components.
	*/
	typedef Vector2Base_t<UInt16> U16Vector2;

	/*
		A vector with 2 32-bit unsigned integer components.
	*/
	typedef Vector2Base_t<UInt32> U32Vector2;

	/*
		A vector with 2 64-bit unsigned integer components.
	*/
	typedef Vector2Base_t<UInt64> U64Vector2;

	// Signed Int Vectors
	// ------------------

	/*
		A vector with 2 8-bit signed integer components.
	*/
	typedef Vector2Base_t<Int8> I8Vector2;

	/*
		A vector with 2 16-bit signed integer components.
	*/
	typedef Vector2Base_t<Int16> I16Vector2;

	/*
		A vector with 2 32-bit signed integer components.
	*/
	typedef Vector2Base_t<Int32> IVector2;

	/*
		A vector with 2 64-bit signed integer components.
	*/
	typedef Vector2Base_t<Int64> I64Vector2;


}

// eof