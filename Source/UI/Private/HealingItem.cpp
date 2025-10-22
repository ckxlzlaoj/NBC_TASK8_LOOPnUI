// Fill out your copyright notice in the Description page of Project Settings.


#include "HealingItem.h"
#include "SpartaMyCharacter.h"

AHealingItem::AHealingItem()
{
	HealAmount = 20.0f;
	ItemType = "Healing";
}

void AHealingItem::ActivateItem(AActor* Activator)
{
	// �÷��̾� ĳ������ ü���� 20��ŭ ȸ����Ű�� ���� ���� ���� ����
    if (Activator && Activator->ActorHasTag("Player"))
    {
        // ȸ�� ����� �޽���
        GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("Player gained %d HP!"), HealAmount));
		if (ASpartaMyCharacter* PlayerCharacter = Cast<ASpartaMyCharacter>(Activator))
		{
			// 캐릭터의 체력을 회복
			PlayerCharacter->AddHealth(HealAmount);
		}
        DestroyItem();
    }
}