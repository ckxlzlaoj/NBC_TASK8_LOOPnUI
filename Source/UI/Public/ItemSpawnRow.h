// Fill out your copyright notice in the Description page of Project Settings.
#include "CoreMinimal.h"
#include "Engine/DataTable.h" // FTableRowBase ���ǰ� ����ִ� ���
#include "ItemSpawnRow.generated.h"

USTRUCT(BlueprintType)
struct FItemSpawnRow : public FTableRowBase
{
    GENERATED_BODY()

public:
    // ������ �̸�
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName ItemName;
    // � ������ Ŭ������ ��������
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<AActor> ItemClass;
    // �� �������� ���� Ȯ��
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SpawnChance;
};