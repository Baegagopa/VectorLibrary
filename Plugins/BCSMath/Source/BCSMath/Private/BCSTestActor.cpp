// Fill out your copyright notice in the Description page of Project Settings.

#include "BCSTestActor.h"
#include "BCSVector.h"

// Sets default values
ABCSTestActor::ABCSTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABCSTestActor::BeginPlay()
{
	Super::BeginPlay();
	FBCSVector3 offset(100.0f, 10.0f, 1.0f);
	
}

// Called every frame
void ABCSTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

