#include "Layer/Layer.h"

#include "Enum.h"

namespace StyleJson
{
	Layer::Layer()
		: m_strID("")
		, m_strSourceID("")
		, m_strSourceLayer("")
	{}

	Layer::~Layer()
	{}

	const Enum::Layer::eType Layer::GetType()
	{
		return Enum::Layer::eType::eType_None;
	}

	const std::string& Layer::GetID() const
	{
		return m_strID;
	}

	const std::string& Layer::GetSourceID() const
	{
		return m_strSourceID;
	}

	const std::string& Layer::GetSourceLayer() const
	{
		return m_strSourceLayer;
	}

	const std::shared_ptr<Filter> Layer::GetFilter() const
	{
		return m_spFilter;
	}

	void Layer::SetSourceLayer(const std::string& _sourceLayer)
	{
		m_strSourceLayer = _sourceLayer;
	}

	void Layer::SetSourceID(const std::string& _sourceID)
	{
		m_strSourceID = _sourceID;
	}
}