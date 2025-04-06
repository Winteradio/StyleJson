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
			bool Deserialize(const rapidjson::Value& _rawLayer) override;

			const std::string& GetID() const;
			const std::string& GetSourceID() const;
			const std::string& GetSourceLayer() const;
			const int GetMinZoom() const;
			const int GetMaxZoom() const;

			const std::shared_ptr<Filter> GetFilter() const;

			void SetID(const std::string& _layerID);
			void SetSourceID(const std::string& _sourceID);
			void SetSourceLayer(const std::string& _sourceLayer);
			void SetMinZoom(const int _minZoom);
			void SetMaxZoom(const int _maxZoom);

		protected :
			bool DeserializeBase(const rapidjson::Value& _rawLayer);
			bool DeserializeSub(const rapidjson::Value& _rawLayer);
			
			virtual bool DeserializePaint(const rapidjson::Value& _rawPaint) = 0;
			virtual bool DeserializeLayout(const rapidjson::Value& _rawLayout) = 0;

		protected :
			std::shared_ptr<Filter> m_spFilter;

		private :
			std::string m_strID;
			std::string m_strSourceID;
			std::string m_strSourceLayer;

			int m_nMinZoom;
			int m_nMaxZoom;
	};
};

#endif // __STYLEJSON_LAYER_H__