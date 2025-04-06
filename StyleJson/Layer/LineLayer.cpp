#include "Layer/LineLayer.h"

#include "Enum.h"
#include "Expression/ExpressionFactory.h"

namespace StyleJson
{
	LineLayer::LineLayer()
		: m_paintProperty()
		, m_layoutProperty()
	{}

	LineLayer::~LineLayer()
	{}

	const Enum::Layer::eType LineLayer::GetType()
	{
		return Enum::Layer::eType::eType_Line;
	}

	bool LineLayer::DeserializePaint(const rapidjson::Value& _rawPaint)
	{
		for (const auto& enumPair : Enum::Paint::Line::PAINT_PROPERTY_LIST)
		{
			if (_rawPaint.HasMember(enumPair.strType))
			{
				const auto& rawExpression = _rawPaint[enumPair.strType];
				std::shared_ptr<Expression> spExpression = ExpressionFactory::GetInstance().Create(rawExpression);
				if (!spExpression || !spExpression->Deserialize(rawExpression))
				{
					continue;
				}

				switch (enumPair.eType)
				{
					case Enum::Paint::Line::eProperty::eProperty_LineColor:
					{
						auto& lineColor = m_paintProperty.Get<Paint::LinePaintColor>();
						lineColor.Set(spExpression);
						break;
					}

					case Enum::Paint::Line::eProperty::eProperty_LineWidth:
					{
						auto& lineWidth = m_paintProperty.Get<Paint::LinePaintWidth>();
						lineWidth.Set(spExpression);
						break;
					}

					default:
					{
						// TODO
						break;
					}
				}
			}
		}

		return true;
	}

	bool LineLayer::DeserializeLayout(const rapidjson::Value& _rawLayout)
	{
		for (const auto& enumPair : Enum::Layout::Line::LAYOUT_PROPERTY_LIST)
		{
			if (_rawLayout.HasMember(enumPair.strType))
			{
				const auto& rawExpression = _rawLayout[enumPair.strType];
				std::shared_ptr<Expression> spExpression = ExpressionFactory::GetInstance().Create(rawExpression);
				if (!spExpression || !spExpression->Deserialize(rawExpression))
				{
					continue;
				}

				switch (enumPair.eType)
				{
					case Enum::Layout::Line::eProperty::eProperty_LineSortKey:
					{
						auto& lineSort = m_paintProperty.Get<Layout::LineSortKey>();
						lineSort.Set(spExpression);
						break;
					}

					default:
					{
						// TODO
						break;
					}
				}
			}
		}

		return true;
	}
}