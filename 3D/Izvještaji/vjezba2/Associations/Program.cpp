#include"Mafia.h"
#include"Boss.h"
#include"Person.h"
#include"Helpers.h"

using namespace std;
using namespace mob;
using namespace abc;

Boss boss(L"Paulie Walnuts");

int main() {

	SetUTF8(wcout);

	Mafia* mafia = new Mafia(L"Naša", L"Igračke");
	boss.SetMafia(mafia);
	boss.Order();
	delete(mafia);
	
	Person(L"Tony Baloney",Date(14,2,1988));

	return 0;
}