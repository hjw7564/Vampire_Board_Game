// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerPiece.h"
#include "GameManager.generated.h"


UCLASS()
class VAMPIRE_BOARD_GAME_API AGameManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameManager();

	UFUNCTION(BlueprintCallable, Category = "Manager")
		APlayerPiece* AdvanceTurn();

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "PlayerPiece")
		APlayerPiece* player;

	UPROPERTY(EditInstanceOnly)
		TArray<AActor*> board;

	UPROPERTY(EditInstanceOnly)
		TArray<APlayerPiece*> players;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



protected:
	int turnCount;
	float enemyHealth;
	int currentPlayerIndex;

};
