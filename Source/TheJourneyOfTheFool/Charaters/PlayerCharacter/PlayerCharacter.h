// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TheJourneyOfTheFool/Charaters/PaperCharacterBase.h"
#include "PlayerCharacter.generated.h"

/**
 * 玩家角色
 */
UCLASS()
class THEJOURNEYOFTHEFOOL_API APlayerCharacter : public APaperCharacterBase
{
	GENERATED_BODY()

public:
	APlayerCharacter();
};
