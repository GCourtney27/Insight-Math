#include "Insight_Math/Vectors/Vector3.h"
#include "Insight_Math/Vectors/Vector2.h"
#include <cassert>
#include <iostream>
#include <immintrin.h>

#define CHECK(Statement) assert(Statement)

using namespace InsightMath;

int BasicArithmetic();
int LinearAlgebra();
int SizeAndConstruction();

int RunTests()
{
	SizeAndConstruction();
	BasicArithmetic();
	LinearAlgebra();
	return 0;
}

#include <DirectXMath.h>
#include "Framework/Intrinsics.h"
int main(int argc, char** argv)
{
	XMVector V1, V2;
	FVector3 Vec1(1.0f, 2.0f, 3.0f);
	FVector3 Vec2(1.0f, 2.0f, 3.0f);
	PackXMVector3(&Vec1, &V1);
	PackXMVector3(&Vec2, &V2);

	XMVector R = XMVectorAdd(V1, V2);
	FVector3 RVec;
	XMVectorUnpackToVector3(&RVec, &R);

	int ErrorCode = RunTests();
	
	/*
	switch (ErrorCode)
	{
	case 0: printf("All Tests passed!");
	}*/


	return 0;
}

int SizeAndConstruction()
{
	// Check for bloat
	{
		FVector3 A;
		CHECK(A.SizeInBytes() == (3 * sizeof(float)));
	}

	// Check constructors
	{
		FVector3 A;
		CHECK(A.X == 0.0f);
		CHECK(A.Y == 0.0f);
		CHECK(A.Z == 0.0f);

		FVector3 B(0.0f, 1.0f, 2.0f);
		CHECK(B.X == 0.0f);
		CHECK(B.Y == 1.0f);
		CHECK(B.Z == 2.0f);

		FVector3 C(4.0f);
		CHECK(C.X == 4.0f);
		CHECK(C.Y == 4.0f);
		CHECK(C.Z == 4.0f);
	}

	return 0;
}

int BasicArithmetic()
{
	// Check operator ==
	{
		FVector3 A(0.0f, 2.0f, 6.0f);
		FVector3 B(0.0f, 2.0f, 6.0f);

		bool IsSame = A == B;
		CHECK(IsSame);

		A.SetXYZ(0.0f, 1.0f, 3.0f);
		B.SetXYZ(0.0f, 2.0f, 6.0f);

		bool NotSame = A == B;
		CHECK(NotSame == false);
	}

	// Check operator !=
	{
		FVector3 A(0.0f, 2.0f, 6.0f);
		FVector3 B(0.0f, 2.0f, 6.0f);

		bool IsSame = A != B;
		CHECK(IsSame == false);

		A.SetXYZ(0.0f, 1.0f, 3.0f);
		B.SetXYZ(0.0f, 2.0f, 6.0f);

		bool NotSame = A != B;
		CHECK(NotSame);
	}

	// Check operator +
	{
		FVector3 A(3.0f, 1.0f, -1.0f);
		FVector3 B(4.0f, 2.0f, 6.0f);

		FVector3 C = A + B;
		CHECK(C.X == 7.0f);
		CHECK(C.Y == 3.0f);
		CHECK(C.Z == 5.0f);
	}

	// Check operator -
	{
		FVector3 A(3.0f, 1.0f, -5.0f);
		FVector3 B(4.0f, 0.0f, 20.0f);

		FVector3 C = A - B;
		CHECK(C.X == -1.0f);
		CHECK(C.Y == 1.0f);
		CHECK(C.Z == -25.0f);
	}

	// Check operator *
	{
		FVector3 A(3.0f, 1.0f, -5.0f);
		FVector3 B(4.0f, 0.0f, 20.0f);

		FVector3 C = A * B;
		CHECK(C.X == 12.0f);
		CHECK(C.Y == 0.0f);
		CHECK(C.Z == -100.0f);
	}

	// Check operator /
	{
		FVector3 A(3.0f, 12.0f, -5.0f);
		FVector3 B(4.0f, 6.0f, 20.0f);

		FVector3 C = A / B;
		CHECK(C.X == 0.75f);
		CHECK(C.Y == 2.0f);
		CHECK(C.Z == -0.25f);
	}

	// Check operator +=
	{
		FVector3 A(3.0f, 1.0f, -1.0f);
		FVector3 B(4.0f, 2.0f, 6.0f);

		A += B;
		CHECK(A.X == 7.0f);
		CHECK(A.Y == 3.0f);
		CHECK(A.Z == 5.0f);
	}

	// Check operator -=
	{
		FVector3 A(3.0f, 1.0f, -5.0f);
		FVector3 B(4.0f, 0.0f, 20.0f);

		A -= B;
		CHECK(A.X == -1.0f);
		CHECK(A.Y == 1.0f);
		CHECK(A.Z == -25.0f);
	}

	// Check operator *
	{
		FVector3 A(3.0f, 1.0f, -5.0f);
		FVector3 B(4.0f, 0.0f, 20.0f);

		A *= B;
		CHECK(A.X == 12.0f);
		CHECK(A.Y == 0.0f);
		CHECK(A.Z == -100.0f);
	}

	// Check operator /=
	{
		FVector3 A(3.0f, 12.0f, -5.0f);
		FVector3 B(4.0f, 6.0f, 20.0f);

		A /= B;
		CHECK(A.X == 0.75f);
		CHECK(A.Y == 2.0f);
		CHECK(A.Z == -0.25f);
	}

	return 0;
}

int LinearAlgebra()
{
	// Check Dot product
	{

		//	|
		//	 ---
		FVector3 A(0.0f, 1.0f, 0.0f);
		FVector3 B(0.0f, 0.0f, 1.0f);

		
		float C = FVector3::Dot(A, B);
		CHECK(C == 0.0f);

		//	|
		//	|
		B.SetXYZ(0.0f, -1.0f, 0.0f);
		C = FVector3::Dot(A, B);
		CHECK(C == -1.0f);


		//	||
		B.SetXYZ(0.0f, 1.0f, 0.0f);
		C = FVector3::Dot(A, B);
		CHECK(C == 1.0f);
	}

	// Cross Product
	{
		FVector3 A(0.0f, 1.0f, 0.0f);
		FVector3 B(0.0f, 0.0f, 1.0f);

		FVector3 C = FVector3::Cross(A, B);
		CHECK(C.X == 1.0f);
		CHECK(C.Y == 0.0f);
		CHECK(C.Z == 0.0f);
	}

	return 0;
}