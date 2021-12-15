#pragma once
#include"pch.h"
ref class App sealed : public Windows::ApplicationModel::Core::IFrameworkView {
private:
	Platform::Agile<Windows::UI :: Core::CoreWindow> _window;
	bool _windowClosed, _windowVisible;
public:	
	App();
	void virtual Initialize(Windows::ApplicationModel::Core::CoreApplicationView^);
	void virtual SetWindow(Windows::UI::Core::CoreWindow^);
	void virtual Load(Platform::String^);
	void virtual Run();
	void virtual Uninitialize();

	void OnActivated(
		Windows::ApplicationModel::Core::CoreApplicationView^,
		Windows::ApplicationModel::Activation::IActivatedEventArgs^);
	void OnSuspending(Platform::Object^, Windows::ApplicationModel::SuspendingEventArgs^);
	void OnResuming(Platform::Object^ a, Platform::Object^ b);

	void OnKeyDown(Windows::UI::Core::CoreWindow^, Windows::UI::Core::KeyEventArgs^);
	void OnPointerPressed(Windows::UI::Core::CoreWindow^, Windows::UI::Core::PointerEventArgs^);

};
