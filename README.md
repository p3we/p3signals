# p3signals
Tiny C++ library providing signals slots pattern implementation 

Example:

```C++
#include <p3signals.hpp>

class Observable
{
public:
	void madeChange()
	{
		changed.fire(true);
	}

public /*signals*/:
	p3::Signal<bool> changed;
};

class Observer
{
public:
	Observer()
	: changeSlot(p3::make_slot(&Observer::handleChange, this))
	{}

public:
	void handleChange(bool value)
	{
		std::cout << "Oh! Something changed to " << (value) ? "true" : "false" << std::endl;
	}

public /*slots*/:
	p3:Slot<bool> changeSlot;
};

int main()
{
	Observable foo;
	Observer bar;

	// connect signal with slot
	// there are also += and -= operators
	foo.changed.connect(bar.changeSlot);

	// this method triggers also changed signal
	foo.madeChange();

	// disconnect is also called after signal/slot destruction
	foo.changed.disconnect(bar.changeSlot);

	return 0;
}
```

