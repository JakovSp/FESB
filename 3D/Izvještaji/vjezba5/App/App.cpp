#include"pch.h"
#include"App.h"
#include"Timer.h"
#include"Renderer.h"

using namespace std;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::UI::Core;
using namespace Platform;
using namespace Windows::ApplicationModel;
using namespace Windows::Foundation;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI::Popups;


App::App() {
	OutputDebugStringW(L"\nApp()");
}

void App::Initialize(CoreApplicationView^ view) {	
	OutputDebugStringW(L"\nInitializing ...");

	view->Activated += ref new 
		TypedEventHandler <CoreApplicationView^,IActivatedEventArgs^>
		(this, &App::OnActivated);

	CoreApplication::Suspending += ref new
		EventHandler<SuspendingEventArgs^>
		(this, &App::OnSuspending);
	
	CoreApplication::Resuming += ref new
		EventHandler<Platform::Object^>
		(this, &App::OnResuming);
}

void App::SetWindow(CoreWindow^ window){
	OutputDebugStringW(L"\nSetting window ...");
	_window = window;
	window->KeyDown += ref new 
		TypedEventHandler<CoreWindow^, KeyEventArgs^>
		(this, &App::OnKeyDown);
	window->PointerPressed += ref new
		TypedEventHandler<CoreWindow^, PointerEventArgs^>
		(this, &App::OnPointerPressed);
}

void App::Load(Platform::String^ str) {
	//OutputDebugStringW(str->ToString());
}

void App::Run() {
	OutputDebugStringW(L"\nRunning ...");
	Timer timer;
	Renderer renderer(1, 10);
	timer.Reset();
	timer.Tick();

	auto dispatcher = CoreWindow::GetForCurrentThread()->Dispatcher;
	while(!_windowClosed) {
		timer.Tick();
		renderer.CalculateStatistics(timer);
		renderer.Render();
		if (_windowVisible) {
			dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessAllIfPresent);
		}
		else {
			dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessOneAndAllPending);
		}
	}

}

void App::Uninitialize() {
	OutputDebugStringW(L"\nUninitializing ...");
}

void App::OnActivated(
	Windows::ApplicationModel::Core::CoreApplicationView^ view,
	Windows::ApplicationModel::Activation::IActivatedEventArgs^ args) {
	OutputDebugStringW(L"\nActivating ...");
	CoreWindow::GetForCurrentThread()->Activate();
}

void App::OnSuspending(Platform::Object^ object, Windows::ApplicationModel::SuspendingEventArgs^ args) {
	OutputDebugStringW(L"\nSuspending ...");
}

void App::OnResuming(Platform::Object^ a, Platform::Object^ b) {
	OutputDebugStringW(L"\nResuming ...");
}

void App::OnKeyDown(CoreWindow^ window, KeyEventArgs^ args) {
	auto key = args->VirtualKey;
	auto messageDialog = ref new MessageDialog(key.ToString());
	messageDialog->ShowAsync();
}

void App::OnPointerPressed(CoreWindow^ window, PointerEventArgs^ args) {
	float x = args->CurrentPoint->Position.X;
	float y = args->CurrentPoint->Position.Y;
	auto messageDialog = ref new MessageDialog("X: " + x.ToString() + "\nY: " + y.ToString());
	messageDialog->ShowAsync();
}