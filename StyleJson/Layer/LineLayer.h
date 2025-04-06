#ifndef __STYLEJSON_LINELAYER_H__
#define __STYLEJSON_LINELAYER_H__

#include "Layer/Layer.h"
#include "Paint/Paint.h"
#include "Layout/Layout.h"
#include "Filter/Filter.h"

namespace StyleJson
{
	class LineLayer : public Layer
	{
		public :
			LineLayer();
			virtual ~LineLayer();

		public :
			static const Enum::Layer::eType GetType();

		protected :
			bool DeserializeSub(const rapidjson::Value& _rawLayer) final;

		private :
			std::shared_ptr<Paint::LinePaintProperty> m_spPaintProperty;
			std::shared_ptr<Layout::LineLayoutProperty> m_spLayoutProperty;
	};
};

#endif // __STYLEJSON_LINELAYER_H__