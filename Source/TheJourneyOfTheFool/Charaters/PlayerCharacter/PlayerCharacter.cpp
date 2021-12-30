// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "Components/CapsuleComponent.h"

APlayerCharacter::APlayerCharacter()
{
	GetCapsuleComponent()->SetCapsuleRadius(10.f);
	GetCapsuleComponent()->SetCapsuleHalfHeight(10.f);
}
