#include "Style.h"
#include "Layer/Layer.h"
#include "Layout/Layout.h"
#include "Filter/Filter.h"

namespace StyleJson
{
	Style::Style()
	{}

	Style::~Style()
	{}

	rapidjson::Value Style::Serialize()
	{
		rapidjson::Value seValue;

		return seValue;
	}

	bool Style::Deserialize(const rapidjson::Value& _jsonValue)
	{
		return true;
	}

	void Style::AddLayer(std::shared_ptr<Layer> _spLayer)
	{
		if (!_spLayer)
		{
			return;
		}

		m_spLayer = _spLayer;
	}

	const std::shared_ptr<Layer> Style::GetLayer() const
	{
		return m_spLayer;
	}

	void Style::AddLayout(std::shared_ptr<Layout> _spLayout)
	{
		if (!_spLayout)
		{
			return;
		}

		m_spLayout = _spLayout;
	}

	const std::shared_ptr<Layout> Style::GetLayout() const
	{
		return m_spLayout;
	}
}