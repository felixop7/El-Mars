
#include"SlateBasics.h"
#include"SlateExtras.h"
class SMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMenuWidget) {}
	SLATE_ARGUMENT(TWeakObjectPtr<class AMenuHUD>, OwingHUD)
		SLATE_END_ARGS()
		// Here every widget needs a construcor function
		void Construct(const FArguments& InArgs);

	FReply OnPlayClicked() const;
	FReply OnQuitClicked() const;



	// HUD that created this widget
	TWeakObjectPtr<class AMenuHUD> OwingHUD;
	virtual bool SupportsKeyboardFocus() const override { return true; };
};
