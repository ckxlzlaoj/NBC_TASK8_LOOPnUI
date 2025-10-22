// Fill out your copyright notice in the Description page of Project Settings.


#include "SmallCoinItem.h"


ASmallCoinItem::ASmallCoinItem()
{

	PointValue = 50;
	ItemType = "SmallCoin";
}

void ASmallCoinItem::ActivateItem(AActor* Activator)
{
	// �θ��� �⺻ ���� ȹ�� ���� ���
	Super::ActivateItem(Activator);

	DestroyItem(); // ������ �Ҹ�(�θ��� DestroyItem() Ȥ�� ��ü ����)
}