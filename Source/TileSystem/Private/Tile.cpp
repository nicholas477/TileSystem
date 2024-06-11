// Fill out your copyright notice in the Description page of Project Settings.


#include "Tile.h"

#include "TileSystemFunctionLibrary.h"

// Sets default values
ATile::ATile()
{

}

bool ATile::MatchesAdjacencyArray_Implementation(uint8 AdjacencyValue)
{
    if (bMatchOnCardinalOnly)
    {
        AdjacencyValue &= FTileSystemFunctionLibrary::GetCardinalBits();
    }

    for (uint8 AdjacencyMatch : AdjacencyMatches)
    {
        if (bMatchOnCardinalOnly)
        {
            AdjacencyMatch &= FTileSystemFunctionLibrary::GetCardinalBits();
        }

        if (AdjacencyMatch == AdjacencyValue)
        {
            return true;
        }
    }

    return false;
}

uint8 ATile::RemoveNonCardinalBits(uint8 Value) const
{
    return Value & FTileSystemFunctionLibrary::GetCardinalBits();
}

uint8 ATile::RemoveCardinalBits(uint8 Value) const
{
    return Value & ~FTileSystemFunctionLibrary::GetCardinalBits();
}

