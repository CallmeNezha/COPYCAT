#ifndef ENTRY_H_HEADER_GUARD
#define ENTRY_H_HEADER_GUARD

#include <kobayaxi/kobayaxi.h>

#define ENTRY_IMPLEMENT_MAIN(_app)                \
	int main(int _argc, char** _argv)             \
	{                                             \
		_app app;                                 \
		return entry::runApp(app, _argc, _argv);		  \
	}


namespace entry
{

	/// 
	struct KOBAYAXI_NO_VTABLE AppI
	{
		virtual ~AppI() = 0;
		virtual void init(int _argc, char** _argv) = 0;
		virtual int  shutdown() = 0;
		virtual bool update() = 0;
	};

	inline AppI::~AppI()
	{
	}

	///
	int runApp(AppI& _app, int _argc, char** _argv);

} // !namespace entry

#endif // !ENTRY_H_HEADER_GUARD