#pragma once
#include"pch.h"
#include"App.h"

ref class ApplicationFactory sealed : public Windows::ApplicationModel::Core::IFrameworkViewSource {
private:
	App^ _application;

public:
	ApplicationFactory() {
		OutputDebugStringW(L"\nApplicationFactory()");
	}
	virtual Windows::ApplicationModel::Core::IFrameworkView^ CreateView(){
		OutputDebugStringW(L"\nCreating a view ...");
		_application = ref new App();
		return _application;
	}
	virtual ~ApplicationFactory() {
		OutputDebugStringW(L"\n~ApplicationFactory()");
	}
};