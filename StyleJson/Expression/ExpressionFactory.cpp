#include "Expression/ExpressionFactory.h"

#include "Enum.h"
#include "Expression/AllExpression.h"
#include "Expression/MatchExpression.h"
#include "Expression/GetExpression.h"

namespace StyleJson
{
	ExpressionFactory& ExpressionFactory::GetInstance()
	{
		static ExpressionFactory instance;
		return instance;
	}

	std::shared_ptr<Expression> ExpressionFactory::Create(const rapidjson::Value& _rawExpression)
	{
		if (_rawExpression.IsArray() && (_rawExpression.Size() > 0) && (_rawExpression[0].IsString()))
		{
			const auto& expressionName = _rawExpression[0].GetString();
			for (const auto& enumPair : Enum::Expression::TYPE_LIST)
			{
				if (expressionName == std::string(enumPair.strType))
				{
					switch (enumPair.eType)
					{
						case Enum::Expression::eType::eType_Math_Add:
						case Enum::Expression::eType::eType_Math_Subtract:
						case Enum::Expression::eType::eType_Math_Multiply:
						case Enum::Expression::eType::eType_Math_Divide:
						case Enum::Expression::eType::eType_Math_Modulo:
						case Enum::Expression::eType::eType_Math_Power:
						case Enum::Expression::eType::eType_Math_Abs:
						case Enum::Expression::eType::eType_Math_Acos:
						case Enum::Expression::eType::eType_Math_Asin:
						case Enum::Expression::eType::eType_Math_Atan:
						case Enum::Expression::eType::eType_Math_Ceil:
						case Enum::Expression::eType::eType_Math_Cos:
						case Enum::Expression::eType::eType_Math_Distance:
						case Enum::Expression::eType::eType_Math_Floor:
						case Enum::Expression::eType::eType_Math_Ln:
						case Enum::Expression::eType::eType_Math_Log10:
						case Enum::Expression::eType::eType_Math_Log2:
						case Enum::Expression::eType::eType_Math_Max:
						case Enum::Expression::eType::eType_Math_Min:
						case Enum::Expression::eType::eType_Math_Round:
						case Enum::Expression::eType::eType_Math_Sin:
						case Enum::Expression::eType::eType_Math_Sqrt:
						case Enum::Expression::eType::eType_Math_Tan:
						case Enum::Expression::eType::eType_Math_Pi:
						case Enum::Expression::eType::eType_Math_E:
						case Enum::Expression::eType::eType_Math_Ln2:
						case Enum::Expression::eType::eType_Math_Random:
						case Enum::Expression::eType::eType_Logical_Not:
						case Enum::Expression::eType::eType_Logical_NotEqual:
						case Enum::Expression::eType::eType_Logical_LessThan:
						case Enum::Expression::eType::eType_Logical_LessOrEqual:
						case Enum::Expression::eType::eType_Logical_Equal:
						case Enum::Expression::eType::eType_Logical_GreaterThan:
						case Enum::Expression::eType::eType_Logical_GreaterOrEqual:
						// case Enum::Expression::eType::eType_Logical_All:
						case Enum::Expression::eType::eType_Logical_Any:
						case Enum::Expression::eType::eType_Logical_Case:
						case Enum::Expression::eType::eType_Logical_Coalesce:
						// case Enum::Expression::eType::eType_Logical_Match:
						case Enum::Expression::eType::eType_Logical_Within:
						case Enum::Expression::eType::eType_String_Concat:
						case Enum::Expression::eType::eType_String_Downcase:
						case Enum::Expression::eType::eType_String_Upcase:
						case Enum::Expression::eType::eType_String_IsSupportedScript:
						case Enum::Expression::eType::eType_String_ResolvedLocale:
						case Enum::Expression::eType::eType_String_Format:
						// case Enum::Expression::eType::eType_Data_Get:
						case Enum::Expression::eType::eType_Data_Has:
						case Enum::Expression::eType::eType_Data_At:
						case Enum::Expression::eType::eType_Data_In:
						case Enum::Expression::eType::eType_Data_IndexOf:
						case Enum::Expression::eType::eType_Data_Length:
						case Enum::Expression::eType::eType_Data_Slice:
						case Enum::Expression::eType::eType_Data_FeatureState:
						case Enum::Expression::eType::eType_Data_GeometryType:
						case Enum::Expression::eType::eType_Data_Id:
						case Enum::Expression::eType::eType_Data_LineProgress:
						case Enum::Expression::eType::eType_Data_Properties:
						case Enum::Expression::eType::eType_Data_Accumulated:
						case Enum::Expression::eType::eType_Camera_Zoom:
						case Enum::Expression::eType::eType_Camera_Pitch:
						case Enum::Expression::eType::eType_Camera_DistanceFromCenter:
						case Enum::Expression::eType::eType_Camera_MeasureLight:
						case Enum::Expression::eType::eType_Color_Rgb:
						case Enum::Expression::eType::eType_Color_Rgba:
						case Enum::Expression::eType::eType_Color_Hsl:
						case Enum::Expression::eType::eType_Color_Hsla:
						case Enum::Expression::eType::eType_Color_ToRgba:
						case Enum::Expression::eType::eType_Color_ToHsla:
						case Enum::Expression::eType::eType_Heatmap_Density:
						case Enum::Expression::eType::eType_Variable_Let:
						case Enum::Expression::eType::eType_Variable_Var:
						case Enum::Expression::eType::eType_Conversion_ToBoolean:
						case Enum::Expression::eType::eType_Conversion_ToColor:
						case Enum::Expression::eType::eType_Conversion_ToNumber:
						case Enum::Expression::eType::eType_Conversion_ToString:
						case Enum::Expression::eType::eType_Conversion_TypeOf:
						case Enum::Expression::eType::eType_Assertion_Array:
						case Enum::Expression::eType::eType_Assertion_Boolean:
						case Enum::Expression::eType::eType_Assertion_Number:
						case Enum::Expression::eType::eType_Assertion_Object:
						case Enum::Expression::eType::eType_Assertion_String:
						case Enum::Expression::eType::eType_Interpolation_Interpolate:
						case Enum::Expression::eType::eType_Interpolation_InterpolateHcl:
						case Enum::Expression::eType::eType_Interpolation_InterpolateLab:
						case Enum::Expression::eType::eType_Interpolation_Step:
						case Enum::Expression::eType::eType_Literal:
						case Enum::Expression::eType::eType_NumberFormat:
						case Enum::Expression::eType::eType_Image:
						case Enum::Expression::eType::eType_Collator:
						{
							// TODO
							return nullptr;
						}

						case Enum::Expression::eType::eType_Logical_All:
						{
							return std::make_shared<AllExpression>();
						}

						case Enum::Expression::eType::eType_Logical_Match:
						{
							return std::make_shared<MatchExpression>();
						}

						case Enum::Expression::eType::eType_Data_Get:
						{
							return std::make_shared<GetExpression>();
						}

						default :
						{
							// Nothing
							return nullptr;
						}
					}
				}
			}
		}

		return nullptr;
	}
}