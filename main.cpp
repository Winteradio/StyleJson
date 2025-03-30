#include <LogProject/Log.h>
#include <LogProject/LogPlatform.h>
#include <RapidJson/rapidjson/document.h>

#include "Variant/Variant.h"

class Object
{
	public:
		Object()
		{
			LOGINFO() << "Object Constructor!";
		}
		~Object()
		{
			LOGINFO() << "Object Destructor!";
		}
};

int MAIN()
{
	Log::Init(1024, Log::Enum::eMode_Print | Log::Enum::eMode_Save, Log::Enum::eLevel_Type);

	LOGINFO() << "Hello World!";

	rapidjson::Document doc;

	LOGINFO() << "SizeOf : " << SizeOf<int>();
	LOGINFO() << "SizeOf : " << SizeOf<int, float, double, char, bool>();

	StyleJson::Variant<int, float, double> var;

	var.Set(1.0f);

	LOGINFO() << "Float : " << var.Is<float>();
	LOGINFO() << "Value : " << var.Get<float>();
	LOGINFO() << "Index : " << var.GetIndex();

	var.Set(2.0);	

	LOGINFO() << "Double : " << var.Is<double>();
	LOGINFO() << "Value : " << var.Get<double>();
	LOGINFO() << "Index : " << var.GetIndex();

	// var.Set(true);
	// LOGINFO() << "Index : " << var.GetIndex();

	LOGINFO() << "Total Index  : " << TotalIndex<int, float, double>();

	StyleJson::Variant<int, Object> var2;

	var2.Set(Object());
	LOGINFO() << "Object : " << var2.Is<Object>();

	var2.Set(1);
	LOGINFO() << "Int : " << var2.Is<int>();

	system("pause");
	return 0;
}