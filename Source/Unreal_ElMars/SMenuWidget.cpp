
#include "SMenuWidget.h"
#include "MenuHUD.h"
#include "GameFramework/PlayerController.h"

#define LOCTEXT_NAMESPACE "MainMenu"

void SMenuWidget::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;
	OwingHUD = InArgs._OwingHUD;
	const FMargin ContentPadding = FMargin(500.f, 300.f);
	const FMargin ButtonPadding = FMargin(10.f);
	const FText TitleText = LOCTEXT("GameTitle", "El. Mars");
	const FText PlayText = LOCTEXT("PlayGame", "Play");
	const FText SettingsText = LOCTEXT("Help", "W:Forward S:Backward A:Left D:Right");
	const FText QuitText = LOCTEXT("QuitGame", "Quit Game");

	FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	ButtonTextStyle.Size = 40.f;
	FSlateFontInfo TitleTextStyle = ButtonTextStyle;
	TitleTextStyle.Size = 60.f;

	ChildSlot
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SImage)
			.ColorAndOpacity(FColor::Transparent)
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.Padding(ContentPadding)
		[
			SNew(SVerticalBox)

			// Title text
		+ SVerticalBox::Slot()
		[
			SNew(STextBlock)
			.Font(TitleTextStyle)
		.Text(TitleText)
		.Justification(ETextJustify::Center)
		]

	// Play Button
	+ SVerticalBox::Slot()
		.Padding(ButtonPadding)
		[
			SNew(SButton)
			.OnClicked(this, &SMenuWidget::OnPlayClicked)
		[
			SNew(STextBlock)
			.Font(ButtonTextStyle)
		.Text(PlayText)
		.Justification(ETextJustify::Center)
		]
		]
	// Quit Button
	+ SVerticalBox::Slot()

		.Padding(ButtonPadding)
		[
			SNew(SButton)
			.OnClicked(this, &SMenuWidget::OnQuitClicked)
		[
			SNew(STextBlock)
			.Font(ButtonTextStyle)
		.Text(QuitText)
		.Justification(ETextJustify::Center)
		]
		]
		]
		];
}
FReply SMenuWidget::OnPlayClicked() const
{
	if (OwingHUD.IsValid())
	{
		OwingHUD->RemoveMenu();
	}
	return	FReply::Handled();

}
FReply SMenuWidget::OnQuitClicked() const
{
	if (OwingHUD.IsValid())
	{
		if (APlayerController* PC = OwingHUD->PlayerOwner)
		{
			PC->ConsoleCommand("quit");
		}
	}
	return FReply::Handled();

}
#undef LOCTEXT_NAMESPACE
