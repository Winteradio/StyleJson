#ifndef __STYLEJSON_LINELAYER_H__
#define __STYLEJSON_LINELAYER_H__

#include "Layer/Layer.h"
#include "Paint/Paint.h"
#include "Layout/Layout.h"

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
			bool DeserializePaint(const rapidjson::Value& _rawPaint) final;
			bool DeserializeLayout(const rapidjson::Value& _rawLayout) final;

		private :
			Paint::LinePaintProperty m_paintProperty;
			Layout::LineLayoutProperty m_layoutProperty;
	};
};

#endif // __STYLEJSON_LINELAYER_H__