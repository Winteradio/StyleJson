#ifndef __STYLEJSON_FILLLAYER_H__
#define __STYLEJSON_FILLLAYER_H__

#include "Layer/Layer.h"

namespace StyleJson
{
	class FillLayer : public Layer
	{
		public :
			FillLayer();
			virtual ~FillLayer();

		public :
			static const Enum::Layer::eType GetType();

		protected :
			bool DeserializeSub(const rapidjson::Value& _rawLayer) final;
	};
};

#endif // __STYLEJSON_FILLLAYER_H__