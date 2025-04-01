#ifndef __STYLEJSON_LAYER_H__
#define __STYLEJSON_LAYER_H__

#include <memory>
#include <string>
#include "Base.h"
#include "Filter/Filter.h"

namespace StyleJson
{
	namespace Enum
	{
		namespace Layer
		{
			enum class eType;
		};
	};
	
	class Layer : public Base
	{
		public :
			Layer();
			virtual ~Layer();

		public :
			static const Enum::Layer::eType GetType();

		public :
			const std::string& GetID() const;
			const std::string& GetSourceID() const;
			const std::string& GetSourceLayer() const;

			const std::shared_ptr<Filter> GetFilter() const;

			void SetSourceLayer(const std::string& _sourceLayer);
			void SetSourceID(const std::string& _sourceID);

		protected :
			std::shared_ptr<Filter> m_spFilter;

		private :
			std::string m_strID;
			std::string m_strSourceID;
			std::string m_strSourceLayer;
	};
};

#endif // __STYLEJSON_LAYER_H__