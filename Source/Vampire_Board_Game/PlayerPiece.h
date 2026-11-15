// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerPiece.generated.h"

UCLASS()
class VAMPIRE_BOARD_GAME_API APlayerPiece : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerPiece();

	UFUNCTION(BlueprintCallable, Category = "Piece")
		void SpawnPieceActor();

	UFUNCTION(BlueprintCallable, Category = "Piece")
		void Roll();

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> actorBPToSpawn;

	UPROPERTY(EditAnywhere)
		FTransform spawnPos;
	
	UPROPERTY(EditAnywhere)
		TArray<AActor*> boardTiles;


	UPROPERTY(EditAnywhere)
		float playerSpeed;

	UPROPERTY()
		int32 rollNum;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	FVector direction;
	float totalDistance;
	float currDistance;
	FVector startTile;
	int64 playerTileIndex = 0;
	int64 targetIndex = 0;
	bool determinedTarget = false;
	AActor* target;

}
;
