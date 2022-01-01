// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "PaperCharacterBase.generated.h"

/**
 * 基础人物模板
 */
UCLASS()
class THEJOURNEYOFTHEFOOL_API APaperCharacterBase : public APaperCharacter
{
	GENERATED_BODY()

public:
	APaperCharacterBase();
	
	UPROPERTY(EditAnywhere, Category = "Character Attribute")
	float MaxHealth;
};
