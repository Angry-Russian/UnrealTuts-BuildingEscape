// Dmitri Kolytchev 2017

#pragma once

#include "CoreMinimal.h"
#include "Gameframework/Actor.h"
#include "Components/ActorComponent.h"
#include "DoorOpener.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UDoorOpener : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorOpener();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	float closeSpeed = 1.0f;
	void OpenDoor();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	bool isOpen = false;
	float start = 0.f;
	float initialYaw = 0.f;
	
};
