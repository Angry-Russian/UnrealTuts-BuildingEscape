// Dmitri Kolytchev 2017

#include "DoorOpener.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UDoorOpener::UDoorOpener()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorOpener::BeginPlay()
{
	Super::BeginPlay();
	AActor* owner = GetOwner();
	initialYaw = owner->GetActorRotation().Yaw;
	OpenDoor();
}

void UDoorOpener::OpenDoor() {
	isOpen = true;
	start = GetWorld()->GetTimeSeconds();
}

// Called every frame
void UDoorOpener::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// TBD: on interact
	AActor* owner = GetOwner();
	if (!isOpen) {
		// open door if it's not open
		UE_LOG(LogTemp, Warning, TEXT("%s is closed."), *owner->GetName());
	} else {
		FRotator rotator = owner->GetActorRotation();
		float progression = fminf(1.f, (GetWorld()->GetTimeSeconds() - start) * closeSpeed);
		UE_LOG(LogTemp, Warning, TEXT("%s is closing... %f%%"), *owner->GetName(), progression);

		float newYaw = initialYaw + 90.f * (1.f - progression);
		rotator.Yaw = newYaw;
		owner->SetActorRotation(rotator);

		if (progression >= 1.f) {
			isOpen = false;
		}
	}
}

