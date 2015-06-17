#include <iostream>

#include <p3signals.hpp>

using namespace std;

int main(int argc, char *argv[])
{
	p3::Signal<bool> changed;
	p3::Slot<bool> change([](bool flag) { cout << "flag changed to " << (flag ? "true" : "false") << endl; });

	changed.connect(change);

	changed.fire(true);
	changed.fire(false);
	changed.fire(true);

	changed.disconnect(change);

	changed.fire(false);

	return 0;
}

