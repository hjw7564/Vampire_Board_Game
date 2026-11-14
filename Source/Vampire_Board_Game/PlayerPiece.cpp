// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPiece.h"
#include "BoardTile.h"

// Sets default values
APlayerPiece::APlayerPiece()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerPiece::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPiece::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPiece::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerPiece::SpawnPieceActor() {
	FActorSpawnParameters spawnParam;
	spawnParam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	GetWorld()->SpawnActor<AActor>(actorBPToSpawn, spawnPos, spawnParam);
}


void APlayerPiece::Roll() {
	rollNum = FMath::RandRange(1, 6);
	AActor* currTile;
	if (playerTileIndex + rollNum >= boardTiles.Num()) {
		currTile = boardTiles[playerTileIndex + rollNum - boardTiles.Num()];
		playerTileIndex += rollNum - boardTiles.Num();
	}
	else {
		currTile = boardTiles[playerTileIndex + rollNum];
		playerTileIndex += rollNum;
	}
	UE_LOG(LogTemp, Warning, TEXT("We are on tile %d"), playerTileIndex);
}

