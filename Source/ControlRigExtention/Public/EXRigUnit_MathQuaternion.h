// Copyright 2022 Wuguyannian. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Units/RigUnit.h"
#include "Math/ControlRigMathLibrary.h"
#include "EXRigUnit_MathQuaternion.generated.h"


USTRUCT(meta = (Abstract, NodeColor = "0.05 0.25 0.05", Category = "Math|Quaternion", MenuDescSuffix = "(Quaternion)"))
struct CONTROLRIGEXTENTION_API FEXRigUnit_MathQuaternionBase : public FRigUnit
{
	GENERATED_BODY()
};

/**
 * Makes a quaternion from two normals, representing the shortest rotation between the two vectors.
 */
USTRUCT(meta = (DisplayName = "From Two Normals", PrototypeName = "FromTwoNormals", Keywords = "Make,Construct"))
struct CONTROLRIGEXTENTION_API FEXRigUnit_MathQuaternionFromTwoNormals : public FEXRigUnit_MathQuaternionBase
{
	GENERATED_BODY()

	FEXRigUnit_MathQuaternionFromTwoNormals()
	{
		A = B = FVector(1.f, 0.f, 0.f);
		Result = FQuat::Identity;
	}

	RIGVM_METHOD()
	virtual void Execute(const FRigUnitContext& Context) override;

	UPROPERTY(meta = (Input))
	FVector A;

	UPROPERTY(meta = (Input))
	FVector B;

	UPROPERTY(meta = (Output))
	FQuat Result;
};