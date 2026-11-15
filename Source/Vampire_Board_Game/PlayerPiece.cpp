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
				currPos = GetActorLocation();
				destination = FVector(target->GetActorLocation().X, target->GetActorLocation().Y, currPos.Z);
				direction = destination - currPos;
				totalDistance = direction.Size();
				direction = direction.GetSafeNormal();
				currDistance = 0.0f;
				determinedTarget = true;
			}

			if (target != nullptr && currDistance < totalDistance) {
				FVector location = GetActorLocation();
				location += direction * playerSpeed * DeltaTime;
				SetActorLocation(location);
				currDistance = (location - currPos).Size();
			}
			else if (target != nullptr && currDistance >= totalDistance) {
				SetActorLocation(destination);
				determinedTarget = false;
				playerTileIndex  = (playerTileIndex+1)%boardTiles.Num();
				targetTile = Cast<ABoardTile>(boardTiles[playerTileIndex]);
				if (targetTile != nullptr && targetIndex==playerTileIndex) {
					AddCoin(targetTile->tileCoin);
					UE_LOG(LogTemp, Warning, TEXT("Coins: %i"), coins);
				}
			}
	}
}

// Called to bind functionality to input
void APlayerPiece::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerPiece::SpawnPieceActor() {
	/*FActorSpawnParameters spawnParam;
	spawnParam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	GetWorld()->SpawnActor<AActor>(actorBPToSpawn, spawnPos, spawnParam);*/
}


void APlayerPiece::Roll() {
	rollNum = FMath::RandRange(1, 6);
	targetIndex = (playerTileIndex + rollNum) % boardTiles.Num();
	UE_LOG(LogTemp, Warning, TEXT("We are on tile %d"), playerTileIndex);
}

void APlayerPiece::AddCoin(int coinsToAdd) {
	coins += coinsToAdd;
	if (coins < 0) {
		coins = 0;
	}
}

