// Fill out your copyright notice in the Description page of Project Settings.


#include "DynamicSunlightManager.h"

#include "Engine/DirectionalLight.h"

UDynamicSunlightManager* UDynamicSunlightManager::Instance = nullptr;

void UDynamicSunlightManager::SetCurrentTime(const FTime TargetTime)
{
	CurrentTime = TargetTime;
}

void UDynamicSunlightManager::AddCurrentTime(FTime TargetTime)
{
	CurrentTime.Minute += TargetTime.Minute;
	int Carrying = CurrentTime.Minute / 60;
	CurrentTime.Minute %= 60;

	CurrentTime.Hour += TargetTime.Hour + Carrying;
	Carrying = CurrentTime.Hour / 24;
	CurrentTime.Hour %= 24;

	CurrentTime.Day += TargetTime.Day + Carrying;
}

void UDynamicSunlightManager::RotateDirectionalLight(ADirectionalLight* DirectionalLight) const
{
	DirectionalLight->SetActorRelativeRotation(CalculateRotation());
}

FRotator UDynamicSunlightManager::CalculateRotation() const
{
	const float TargetPitch = 90 + CurrentTime.Hour * 15 + CurrentTime.Minute * 0.25;
	const FRotator Rotator = FRotator(TargetPitch, 0, 0);
	
	return Rotator;
}

