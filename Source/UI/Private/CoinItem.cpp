// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinItem.h"
#include "Engine/World.h"
#include "SpartaGameStateBase.h"

ACoinItem::ACoinItem()
{
    // ���� �⺻���� 0���� ����
    PointValue = 0;
    ItemType = "DefaultCoin";
}

void ACoinItem::ActivateItem(AActor* Activator)
{
    // �÷��̾� �±� Ȯ��
    if (Activator && Activator->ActorHasTag("Player"))
    {
        // ���� ȹ�� ����� �޽���
        GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("Player gained %d points!"), PointValue));
        if (UWorld* World = GetWorld())
        {
            if (ASpartaGameStateBase* GameState = World->GetGameState<ASpartaGameStateBase>())
            {
                GameState->AddScore(PointValue);
            }
        }
        // �θ� Ŭ���� (BaseItem)�� ���ǵ� ������ �ı� �Լ� ȣ��
        DestroyItem();
    }
}