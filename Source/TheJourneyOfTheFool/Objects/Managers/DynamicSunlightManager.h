// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DynamicSunlightManager.generated.h"

/**
 * @brief 游戏时间
 */
USTRUCT(BlueprintType)
struct FTime
{
	GENERATED_BODY()

	/**
	* @brief 天数
	*/
	UPROPERTY(BlueprintReadWrite)
	uint8 Day;
	
	/**
	* @brief 小时
	*/
	UPROPERTY(BlueprintReadWrite)
	uint8 Hour;

	/**
	* @brief 分钟
	*/
	UPROPERTY(BlueprintReadWrite)
	uint8 Minute;

	FTime(): Day(0), Hour(0), Minute(0)
	{
	};

	FTime(uint8 Day, uint8 Hour,uint8 Minute)
	{
		this->Minute = Minute % 60;

		this->Hour = Hour % 24;

		this->Day = Day;
	}
};

/**
 * 动态阳光管理器
 */
UCLASS(BlueprintType)
class THEJOURNEYOFTHEFOOL_API UDynamicSunlightManager : public UObject
{
	GENERATED_BODY()

private:
	/**
	* @brief 单例
	*/
	static UDynamicSunlightManager* Instance;

	/**
	* @brief 当前游戏时间
	*/
	FTime CurrentTime;
	
public:
	/**
	* @brief 获得单例
	* @return 单例
	*/
	UFUNCTION(BlueprintCallable)
	static UDynamicSunlightManager* GetInstance()
	{
		if(!Instance)
		{
			Instance = NewObject<UDynamicSunlightManager>();
			Instance->AddToRoot();
		}

		return Instance;
	}

	/**
	* @brief 获得当前游戏时间
	*/
	UFUNCTION(BlueprintCallable)
	FTime GetCurrentTime() const
	{
		return CurrentTime;
	}

	/**
	* @brief 设置当前游戏时间
	* @param TargetTime 需要设置成的时间
	*/
	UFUNCTION(BlueprintCallable)
	void SetCurrentTime(FTime TargetTime);

	/**
	* @brief 增加游戏时间
	* @param TargetTime 需要增加的时间
	*/
	UFUNCTION(BlueprintCallable)
	void AddCurrentTime(FTime TargetTime);

	/**
	* @brief 旋转直射光组件以达到控制阳光的效果
	* @param DirectionalLight 直射光组件
	*/
	UFUNCTION(BlueprintCallable)
	void RotateDirectionalLight(class ADirectionalLight* DirectionalLight) const;

private:
	/**
	* @brief 通过当前时间计算应该旋转多少度
	* @return 旋转体
	*/
	FRotator CalculateRotation() const;
};
