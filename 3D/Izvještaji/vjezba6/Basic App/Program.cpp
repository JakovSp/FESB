#include"pch.h"
#include"Renderer.h"

using namespace vxe;
using namespace std;
using namespace Platform;

[MTAThreadAttribute]
int32_t main(Array<String^>^) {
	auto renderer = make_shared<Renderer>();
	Vanity vanity{ renderer };
	vanity.Run();
	return 0;
}