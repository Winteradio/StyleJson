#ifndef __STYLEJSON_SYMBOLLAYER_H__
#define __STYLEJSON_SYMBOLLAYER_H__

#include "Layer/Layer.h"

namespace StyleJson
{
	class SymbolLayer : public Layer
	{
		public :
			SymbolLayer();
			virtual ~SymbolLayer();

		public :
			const Enum::Layer::eType GetType();

		public :
			bool Deserialize(const rapidjson::Value& _jsonLayer) final;
	};
};

#endif // __STYLEJSON_SYMBOLLAYER_H__