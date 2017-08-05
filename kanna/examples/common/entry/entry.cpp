#include "entry_private.h"

// Here extern means _main_ is defined outside of this cpp.


namespace entry
{

	int runApp(AppI& _app, int _argc, char** _argv)
	{
		_app.init(_argc, _argv);

		return 1;
	}

}