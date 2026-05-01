// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VHealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHealthDepletedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChangedSignature, float, NewHealth, float, MaxHealth);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHEDLIGHT_API UVHealthComponent : public UActorComponent
{
	GENERATED_BODY()

	// Current health
	UPROPERTY()
	float Health;

	// Max health
	UPROPERTY(EditDefaultsOnly, Category = "Default")
	float MaxHealth;

public:	
	// Sets default values for this component's properties
	UVHealthComponent();


	UPROPERTY(BlueprintAssignable, Category = "Default")
	FOnHealthChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "Default")
	FOnHealthDepletedSignature OnHealthDepleted;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintCallable)
	float GetHealth() const;

	UFUNCTION(BlueprintCallable)
	float GetMaxHealth() const;

	UFUNCTION(BlueprintCallable)
	void UpdateHealth(float DeltaHealth);

};
