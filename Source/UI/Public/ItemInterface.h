// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ItemInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UItemInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class UI_API IItemInterface
{
	GENERATED_BODY()
    // �÷��̾ �� �������� ������ ������ �� ȣ��
    virtual void OnItemOverlap(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult) = 0;
    // �÷��̾ �� �������� ������ ����� �� ȣ��
    virtual void OnItemEndOverlap(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex) = 0;
    // �������� ���Ǿ��� �� ȣ��
    virtual void ActivateItem(AActor* Activator) = 0;
    // �� �������� ����(Ÿ��)�� ��ȯ (��: "Coin", "Mine" ��)
    virtual FName GetItemType() const = 0;


	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
};
