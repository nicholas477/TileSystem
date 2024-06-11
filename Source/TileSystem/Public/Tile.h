// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"

UCLASS()
class TILESYSTEM_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATile();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Tile")
		TArray<uint8> AdjacencyMatches;

	// This is called on the CDO, so don't mess with variables
	UFUNCTION(BlueprintNativeEvent, Category = "Tile")
		bool MatchesAdjacencyArray(uint8 AdjacencyValue);

	// If true, then it will only match on the 4 directions instead of all 8 directions
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Tile")
		bool bMatchOnCardinalOnly;

	// Leaves only the north south east west bits
	UFUNCTION(BlueprintPure, Category = "Tile")
		uint8 RemoveNonCardinalBits(uint8 Value) const;

	// Removes the north south east west bits, leaving the corner bits only
	UFUNCTION(BlueprintPure, Category = "Tile")
		uint8 RemoveCardinalBits(uint8 Value) const;

	UPROPERTY(BlueprintReadOnly, Category = "Tile")
		uint8 AdjacencyBits;
};
