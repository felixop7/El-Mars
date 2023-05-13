
#include "MenuPlayerController.h"
#include "MenuHUD.h"

AMenuPlayerController::AMenuPlayerController()
{

}

void AMenuPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (InputComponent)
	{

		InputComponent->BindAction(TEXT("OpenMenu"), EInputEvent::IE_Pressed, this, &AMenuPlayerController::OpenMenu);
	}
}

void AMenuPlayerController::OpenMenu()
{
	if (AMenuHUD* MenuHUD = Cast<AMenuHUD>(GetHUD()))
	{
		MenuHUD->ShowMenu();
	}
}
