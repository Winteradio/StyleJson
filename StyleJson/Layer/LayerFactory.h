#ifndef __STYLEJSON_LAYERFACTORY_H__
#define __STYLEJSON_LAYERFACTORY_H__

#include <memory>
#include "FactoryBase.h"

namespace StyleJson
{
	class Layer;

	class LayerFactory : public FactoryBase<Layer>
	{
		private :
			LayerFactory() = default;
			~LayerFactory() = default;

		public :
			static LayerFactory& GetInstance();

		public :
			std::shared_ptr<Layer> Create(const rapidjson::Value& _rawLayer) final;
	};
};

#endif // __STYLEJSON_LAYERFACTORY_H__