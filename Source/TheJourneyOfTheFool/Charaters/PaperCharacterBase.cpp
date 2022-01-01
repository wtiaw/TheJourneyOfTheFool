// Fill out your copyright notice in the Description page of Project Settings.


#include "PaperCharacterBase.h"

#include "Components/CapsuleComponent.h"

APaperCharacterBase::APaperCharacterBase()
{
	GetCapsuleComponent()->SetCapsuleRadius(10.f);
	GetCapsuleComponent()->SetCapsuleHalfHeight(10.f);

	GetComponentByClass(UPaperFlipbookComponent);
}
