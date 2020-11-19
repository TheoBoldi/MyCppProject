// Fill out your copyright notice in the Description page of Project Settings.

#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, text)
#define printf(text, fstring) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, Fcolor::Green, FString::Printf(Text(text), fstring))

#include "LavaKillBox.h"
#include "DrawDebugHelpers.h"

ALavaKillBox::ALavaKillBox() 
{
	OnActorBeginOverlap.AddDynamic(this, &ALavaKillBox::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ALavaKillBox::OnOverlapEnd);

}

void ALavaKillBox::BeginPlay() 
{
	Super::BeginPlay();

	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, -1, 0, 5);
}

void ALavaKillBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this))
	{
		/*print("Overlap Begin");
		printf("Overlapped Actor = %S", OverlappedActor->GetName());*/
	}
}

void ALavaKillBox::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this))
	{
		/*print("Overlap Ended");
		printf("Overlapped Actor = %S", *OtherActor->GetName());*/
	}
}