#include "Expression/ExpressionValue.h"

namespace StyleJson
{
	ExpressionValue::ExpressionValue()
		: m_data()
	{}

	ExpressionValue::~ExpressionValue()
	{}

	bool ExpressionValue::Deserialize(const rapidjson::Value& _rawExpressionValue)
	{
		if (_rawExpressionValue.IsArray())
		{
			std::vector<ExpressionValue> valueList;
			valueList.reserve(_rawExpressionValue.Size());

			for (const auto& rawValue : _rawExpressionValue.GetArray())
			{
				ExpressionValue value;
				if (value.Deserialize(rawValue))
				{
					valueList.push_back(std::move(value));
				}
			}

			if (!valueList.empty())
			{
				m_data.Set<std::vector<ExpressionValue>>(std::move(valueList));
			}
		}
		else
		{
			if (_rawExpressionValue.IsBool())
			{
				m_data.Set<bool>(_rawExpressionValue.GetBool());
			}
			else if (_rawExpressionValue.IsInt())
			{
				m_data.Set<int64_t>(_rawExpressionValue.GetInt());
				return true;
			}
			else if (_rawExpressionValue.IsInt64())
			{
				m_data.Set<int64_t>(_rawExpressionValue.GetInt64());
			}
			else if (_rawExpressionValue.IsUint())
			{
				m_data.Set<uint64_t>(_rawExpressionValue.GetUint());
			}
			else if (_rawExpressionValue.IsUint64())
			{
				m_data.Set<uint64_t>(_rawExpressionValue.GetUint64());
			}
			else if (_rawExpressionValue.IsFloat())
			{
				m_data.Set<float>(_rawExpressionValue.GetFloat());
			}
			else if (_rawExpressionValue.IsDouble())
			{
				m_data.Set<double>(_rawExpressionValue.GetDouble());
			}
			else if (_rawExpressionValue.IsString())
			{
				m_data.Set<std::string>(_rawExpressionValue.GetString());
			}
			else
			{
				// Nothing
			}
		}
		
		return (m_data.GetIndex() != -1);
	}

	const ExpressionValue::Data& ExpressionValue::GetData() const
	{
		return m_data;
	}
}