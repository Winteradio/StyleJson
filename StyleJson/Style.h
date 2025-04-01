#ifndef __STYLEJSON_STYLE_H__
#define __STYLEJSON_STYLE_H__

#include <memory>
#include <vector>
#include <string>

#include "Base.h"

namespace StyleJson
{
	class Layer;
	class Sprite;

	class Style : public Base
	{
		public :
			Style();
			virtual ~Style();

		public :
			bool Deserialize(const rapidjson::Value& _rawStyle) override;

			const std::shared_ptr<Sprite> GetSprite() const;
			const std::shared_ptr<Layer> GetLayer(const std::string& _layerID) const;
			const std::vector<std::shared_ptr<Layer>> GetLayers() const;

			template<typename T>
			const std::shared_ptr<T> GetLayerAs(const std::string& _layerID) const
			{
				for (const auto& spLayer : m_vLayers)
				{
					if (spLayer && (spLayer->GetID() == _layerID) && (spLayer->GetType() == T::GetType()))
					{
						return reinterpret_cast<T*>(spLayer);
					}
				}

				return nullptr;
			}

		private :
			void AddLayer(std::shared_ptr<Layer> _spLayer);
			void AddSprite(std::shared_ptr<Sprite> _spSprite);

		private :
			std::vector<std::shared_ptr<Layer>> m_vLayers;
			std::shared_ptr<Sprite> m_spSprite;
	};
};

#endif // __STYLEJSON_STYLE_H__