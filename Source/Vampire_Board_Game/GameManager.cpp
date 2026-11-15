// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"
#include "PlayerPiece.h"

// Sets default values
AGameManager::AGameManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGameManager::BeginPlay()
{
	Super::BeginPlay();
	for (int32 i = 0; i < players.Num(); ++i) {
		players[i]->boardTiles = board;
	}
	currentPlayerIndex = 0;
	
}

// Called every frame
void AGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

APlayerPiece* AGameManager::AdvanceTurn() {
	currentPlayerIndex = (currentPlayerIndex + 1) % players.Num();
	return players[currentPlayerIndex];
}

