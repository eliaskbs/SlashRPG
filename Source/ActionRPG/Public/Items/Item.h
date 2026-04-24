// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

class USphereComponent;
class UStaticMeshComponent;

enum class EItemState : uint8
{
	EIS_Hovering UMETA(DisplayName = "Hovering"),
	EIS_Equipped UMETA(DisplayName = "Equipped"),
};

UCLASS()
class ACTIONRPG_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere ,BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> ItemMesh;
	

public:
	
	UPROPERTY(BlueprintReadWrite)
	float TimeConstant = 5.f;
	UPROPERTY(BlueprintReadWrite)
	float Amplitude = 0.25f;
	
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintPure)
	float TransformedSin();
	
	UFUNCTION(BlueprintPure)
	float TransformedCos();
	
	UFUNCTION()
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
	UFUNCTION()
	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	EItemState ItemState = EItemState::EIS_Hovering;
	
private:
	
	
	float RunningTime;
	
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> Sphere;
	

};
