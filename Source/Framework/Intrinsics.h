#pragma once

#include <xmmintrin.h>

#include "Framework/Vector3_Base.h"


namespace InsightMath
{

	/*
		Packed 16-bit floating-point vector.
	*/
	typedef __m128 XMVector;




	// -------------------------
	//		Construction		|
	// -------------------------

	inline void PackXMVector3(const Vector3Base_t<float>* Source, XMVector* Destination)
	{
		// Load X Y Z into intermediate registers.
		__m128 X = _mm_load_ss(&Source->X);
		__m128 Y = _mm_load_ss(&Source->Y);
		__m128 Z = _mm_load_ss(&Source->Z);
		// Load X and Y into their own register using the low order bits
		__m128 XYCombined = _mm_unpacklo_ps(X, Y);
		// Load Z into the high order bits of the combined X and Y register.
		*Destination = _mm_movelh_ps(XYCombined, Z);
	}

	/*
		Store an XMVector as A FVector3.
	*/
	inline void XMVectorUnpackToVector3(Vector3Base_t<float>* Destination, XMVector* Source)
	{

		XMVector T1 = _mm_shuffle_ps(*Source, *Source, _MM_SHUFFLE(1, 1, 1, 1));
		XMVector T2 = _mm_shuffle_ps(*Source, *Source, _MM_SHUFFLE(2, 2, 2, 2));

		_mm_store_ps(&(Destination->X), *Source);
		_mm_store_ps(&(Destination->Y), T1);
		_mm_store_ps(&(Destination->Z), T2);
	}



	// ---------------------
	//		Arithmetic		|
	// ---------------------

	/*
		Add two packed vectors together.
	*/
	inline XMVector XMVectorAdd(const XMVector& V1, const XMVector& V2)
	{
		return _mm_add_ps(V1, V2);
	}

	/*
		Subtract two packed vectors together.
	*/
	inline XMVector XMVectorSubtract(const XMVector& V1, const XMVector& V2)
	{
		return _mm_sub_ps(V1, V2);
	}

	/*
		Multiply two packed vectors together.
	*/
	inline XMVector XMVectorMultiply(const XMVector& V1, const XMVector& V2)
	{
		return _mm_mul_ps(V1, V2);
	}

	/*
		Divide two packed vectors together.
	*/
	inline XMVector XMVectorDivide(const XMVector& V1, const XMVector& V2)
	{
		return _mm_div_ps(V1, V2);
	}
}
