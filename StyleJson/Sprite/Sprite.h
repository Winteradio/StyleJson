#ifndef __STYLEJSON_SPRITE_H__
#define __STYLEJSON_SPRITE_H__

#include "Base.h"

namespace StyleJson
{
	class Sprite : public Base
	{
		public :
			Sprite();
			virtual ~Sprite();

		public :
			bool Deserialize(const rapidjson::Value& _jsonSprite) override;
	};
};

#endif // __STYLEJSON_SPRITE_H__