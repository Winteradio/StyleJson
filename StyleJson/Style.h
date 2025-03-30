#ifndef __STYLEJSON_STYLE_H__
#define __STYLEJSON_STYLE_H__

#include <memory>
#include "StyleJsonBase.h"

namespace StyleJson
{
	class Layer;
	class Layout;
	class Filter;

	class Style : public Base
	{
		public :
			Style();
			virtual ~Style();

		public :
			rapidjson::Value Serialize() override;
			bool Deserialize(const rapidjson::Value& _jsonValue) override;

		public :
			void AddLayer(std::shared_ptr<Layer> _spLayer);
			const std::shared_ptr<Layer> GetLayer() const;

			void AddLayout(std::shared_ptr<Layout> _spLayout);
			const std::shared_ptr<Layout> GetLayout() const;

			void AddFilter(std::shared_ptr<Filter> _spFilter);
			const std::shared_ptr<Filter> GetFilter() const;

		private :
			std::shared_ptr<Layer> m_spLayer;
			std::shared_ptr<Layout> m_spLayout;
			std::shared_ptr<Filter> m_spFilter;
	};
};

#endif // __STYLEJSON_STYLE_H__