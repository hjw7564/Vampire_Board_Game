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

	if (targetIndex!=playerTileIndex) {
			if (determinedTarget == false) {
				target = boardTiles[(playerTileIndex + 1) % boardTiles.Num()];
				direction = target->GetActorLocation() - boardTiles[playerTileIndex]->GetActorLocation();
				totalDistance = direction.Size();
				direction = direction.GetSafeNormal();
				currDistance = 0.0f;
				determinedTarget = true;
			}

			if (target != nullptr && currDistance < totalDistance) {
				FVector location = GetActorLocation();
				location += direction * playerSpeed * DeltaTime;
				SetActorLocation(location);
				currDistance = (location - boardTiles[playerTileIndex]->GetActorLocation()).Size();
			}
			else if (target != nullptr && currDistance >= totalDistance) {
				SetActorLocation(target->GetActorLocation());
				determinedTarget = false;
				playerTileIndex  = (playerTileIndex+1)%boardTiles.Num();
			}
	}
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
	targetIndex = (playerTileIndex + rollNum) % boardTiles.Num();
	UE_LOG(LogTemp, Warning, TEXT("We are on tile %d"), playerTileIndex);
}

