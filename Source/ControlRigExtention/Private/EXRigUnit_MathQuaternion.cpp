// Fill out your copyright notice in the Description page of Project Settings.


#include "EXRigUnit_MathQuaternion.h"
#include "Units/RigUnitContext.h"

FEXRigUnit_MathQuaternionFromTwoNormals_Execute()
{
	DECLARE_SCOPE_HIERARCHICAL_COUNTER_RIGUNIT()
	if (A.IsNearlyZero() || B.IsNearlyZero())
	{
		Result = FQuat::Identity;
		return;
	}
	Result = FQuat::FindBetweenNormals(A, B).GetNormalized();
}
