// Fill out your copyright notice in the Description page of Project Settings.


#include "HealingItem.h"

AHealingItem::AHealingItem()
{
	HealAmount = 20.0f;
	ItemType = "Healing";
}

void AHealingItem::ActivateItem(AActor* Activator)
{
	// 플레이어 캐릭터의 체력을 20만큼 회복시키는 로직 등을 구현 가능
    if (Activator && Activator->ActorHasTag("Player"))
    {
        // 회복 디버그 메시지
        GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("Player gained %d HP!"), HealAmount));

        DestroyItem();
    }
}