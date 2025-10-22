#include "BaseItem.h"
#include "Components/SphereComponent.h"


ABaseItem::ABaseItem()
{
    PrimaryActorTick.bCanEverTick = false;

    // ��Ʈ ������Ʈ ���� �� ����
    Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
    SetRootComponent(Scene);

    // �浹 ������Ʈ ���� �� ����
    Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
    // ��ħ�� �����ϴ� �������� ����
    Collision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
    // ��Ʈ ������Ʈ�� ����
    Collision->SetupAttachment(Scene);

    // ����ƽ �޽� ������Ʈ ���� �� ����
    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMesh->SetupAttachment(Collision);
    // �޽ð� ���ʿ��ϰ� �浹�� ���� �ʵ��� �ϱ� ����, ������ NoCollision ������ ������ �� ����.

// Overlap �̺�Ʈ ���ε�
    Collision->OnComponentBeginOverlap.AddDynamic(this, &ABaseItem::OnItemOverlap);
    Collision->OnComponentEndOverlap.AddDynamic(this, &ABaseItem::OnItemEndOverlap);
}

void ABaseItem::OnItemOverlap(
    UPrimitiveComponent* OverlappedComp,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex,
    bool bFromSweep,
    const FHitResult& SweepResult)
{
    // OtherActor�� �÷��̾����� Ȯ�� ("Player" �±� Ȱ��)
    if (OtherActor && OtherActor->ActorHasTag("Player"))
    {
        GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("Overlap!!!")));
        // ������ ��� (ȹ��) ���� ȣ��
        ActivateItem(OtherActor);
    }
}

void ABaseItem::OnItemEndOverlap(
    UPrimitiveComponent* OverlappedComp,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex)
{
}

void ABaseItem::ActivateItem(AActor* Activator)
{
    GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("Overlap!!")));
}

FName ABaseItem::GetItemType() const
{
    return ItemType;
}

void ABaseItem::DestroyItem()
{
    Destroy();
}