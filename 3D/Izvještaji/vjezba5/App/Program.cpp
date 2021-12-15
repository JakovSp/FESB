#include"pch.h"
#include"ApplicationFactory.h"

using namespace Platform;
using namespace Windows::ApplicationModel::Core;
using namespace std;

[MTAThread]
int main(Array<String^>^) {
	auto factory = ref new ApplicationFactory();
	CoreApplication::Run(factory);
	return 0;
}