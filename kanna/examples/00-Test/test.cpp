#include <stdio.h>
#include "entry/entry.h"

class A final : public entry::AppI
{
public:
	void init(int _argc, char** _argv) override {}
	int  shutdown() override { return 1; }
	bool update() override { return true; }
};

ENTRY_IMPLEMENT_MAIN(A);



