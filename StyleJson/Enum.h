#ifndef __STYLEJSON_ENUM_H__
#define __STYLEJSON_ENUM_H__

#include <array>

namespace StyleJson
{
	namespace Enum
	{
		template<typename T>
		struct EnumPair
		{
			const T	eType;
			const char* strType;

			constexpr EnumPair()
				: eType()
				, strType("none")
			{}

			constexpr EnumPair(const T& _eType, const char* _strType)
				: eType(_eType)
				, strType(_strType)
			{}
		};

		namespace Root
		{
			enum class eProperty
			{
				eProperty_None = 0,
				eProperty_Version,
				eProperty_Style_Version,
				eProperty_Center,
				eProperty_Imports,
				eProperty_Sprite,
				eProperty_Glyphs,
				eProperty_Sources,
				eProperty_Layers,
				eProperty_End,
			};

			constexpr std::array<EnumPair<eProperty>, static_cast<size_t>(eProperty::eProperty_End)> PROPERTY_LIST =
			{{
				{eProperty::eProperty_None, "none"},
				{eProperty::eProperty_Version, "version"},
				{eProperty::eProperty_Style_Version, "style_version"},
				{eProperty::eProperty_Center, "center"},
				{eProperty::eProperty_Imports, "imports"},
				{eProperty::eProperty_Sprite, "sprite"},
				{eProperty::eProperty_Glyphs, "glyphs"},
				{eProperty::eProperty_Sources, "sources"},
				{eProperty::eProperty_Layers, "layers"},
			}};
		};

		namespace Layer
		{
			enum class eType
			{
				eType_None = 0,
				eType_Fill,
				eType_Line,
				eType_Symbol,
				eType_Circle,
				eType_Heatmap,
				eType_FillExtrusion,
				eType_Raster,
				eType_RasterParticle,
				eType_Hillshade,
				eType_Model,
				eType_Background,
				eType_Sky,
				eType_Slot,
				eType_Clip,
				eType_End,
			};

			enum class eProperty
			{
				eProperty_None = 0,
				eProperty_Id,
				eProperty_Type,
				eProperty_Filter,
				eProperty_Source,
				eProperty_Source_Layer,
				eProperty_Min_Zoom,
				eProperty_Max_Zoom,
				eProperty_End,
			};

			enum class eSubProperty
			{
				eProperty_None = 0,
				eProperty_Layer,
				eProperty_Paint,
				eProperty_End,
			};

			constexpr std::array<EnumPair<eType>, static_cast<size_t>(eType::eType_End)> TYPE_LIST = {{
				{eType::eType_None, "none"},
				{eType::eType_Fill, "fill"},
				{eType::eType_Line, "line"},
				{eType::eType_Symbol, "symbol"},
				{eType::eType_Circle, "circle"},
				{eType::eType_Heatmap, "heatmap"},
				{eType::eType_FillExtrusion, "fill-extrusion"},
				{eType::eType_Raster, "raster"},
				{eType::eType_RasterParticle, "raster-particle"},
				{eType::eType_Hillshade, "hillshade"},
				{eType::eType_Model, "model"},
				{eType::eType_Background, "background"},
				{eType::eType_Sky, "sky"},
				{eType::eType_Slot, "slot"},
				{eType::eType_Clip, "clip"}
			}};

			constexpr std::array<EnumPair<eProperty>, static_cast<size_t>(eProperty::eProperty_End)> PROPERTY_LIST = {{
				{eProperty::eProperty_None, "none"},
				{eProperty::eProperty_Id, "id"},
				{eProperty::eProperty_Type, "type"},
				{eProperty::eProperty_Filter, "filter"},
				{eProperty::eProperty_Source, "source"},
				{eProperty::eProperty_Source_Layer, "source-layer"},
				{eProperty::eProperty_Min_Zoom, "minzoom"},
				{eProperty::eProperty_Max_Zoom, "maxzoom"}
			}};

			constexpr std::array<EnumPair<eSubProperty>, static_cast<size_t>(eSubProperty::eProperty_End)> SUB_PROPERTY_LIST = {{
				{eSubProperty::eProperty_None, "none"},
				{eSubProperty::eProperty_Layer, "layer"},
				{eSubProperty::eProperty_Paint, "paint"}
			}};
		};

		namespace Paint
		{
			namespace Fill
			{
				enum class eProperty {
					eProperty_None = 0,
					eProperty_FillAntialias,
					eProperty_FillColor,
					eProperty_FillEmissiveStrength,
					eProperty_FillOpacity,
					eProperty_FillOutlineColor,
					eProperty_FillPattern,
					eProperty_FillSortKey,
					eProperty_FillTranslate,
					eProperty_FillTranslateAnchor,
					eProperty_FillZOffset,
					eProperty_Visibility,
					eProperty_End
				};
		
				constexpr std::array<EnumPair<eProperty>, static_cast<size_t>(eProperty::eProperty_End)> PROPERTY_LIST = {{
					{eProperty::eProperty_None, "none"},
					{eProperty::eProperty_FillAntialias, "fill-antialias"},
					{eProperty::eProperty_FillColor, "fill-color"},
					{eProperty::eProperty_FillEmissiveStrength, "fill-emissive-strength"},
					{eProperty::eProperty_FillOpacity, "fill-opacity"},
					{eProperty::eProperty_FillOutlineColor, "fill-outline-color"},
					{eProperty::eProperty_FillPattern, "fill-pattern"},
					{eProperty::eProperty_FillSortKey, "fill-sort-key"},
					{eProperty::eProperty_FillTranslate, "fill-translate"},
					{eProperty::eProperty_FillTranslateAnchor, "fill-translate-anchor"},
					{eProperty::eProperty_FillZOffset, "fill-z-offset"},
					{eProperty::eProperty_Visibility, "visibility"}
				}};
			};

			namespace Line
			{

			};

			namespace Symbol
			{

			};
		};

		namespace Layout
		{
			namespace Fill
			{

			};

			namespace Line
			{

			};

			namespace Symbol
			{

			};
		};

		namespace Expression
		{
			enum class eType
			{
				eType_None = 0,

				// Math operators
				eType_Math_Add,              // ["+"]
				eType_Math_Subtract,         // ["-"]
				eType_Math_Multiply,         // ["*"]
				eType_Math_Divide,           // ["/"]
				eType_Math_Modulo,           // ["%"]
				eType_Math_Power,            // ["^"]
				eType_Math_Abs,              // ["abs"]
				eType_Math_Acos,             // ["acos"]
				eType_Math_Asin,             // ["asin"]
				eType_Math_Atan,             // ["atan"]
				eType_Math_Ceil,             // ["ceil"]
				eType_Math_Cos,              // ["cos"]
				eType_Math_Distance,         // ["distance"]
				eType_Math_Floor,            // ["floor"]
				eType_Math_Ln,               // ["ln"]
				eType_Math_Log10,            // ["log10"]
				eType_Math_Log2,             // ["log2"]
				eType_Math_Max,              // ["max"]
				eType_Math_Min,              // ["min"]
				eType_Math_Round,            // ["round"]
				eType_Math_Sin,              // ["sin"]
				eType_Math_Sqrt,             // ["sqrt"]
				eType_Math_Tan,              // ["tan"]
				eType_Math_Pi,               // ["pi"]
				eType_Math_E,                // ["e"]
				eType_Math_Ln2,              // ["ln2"]
				eType_Math_Random,           // ["random"]
		
				// Logical operators
				eType_Logical_Not,           // ["!"]
				eType_Logical_NotEqual,      // ["!="]
				eType_Logical_LessThan,      // ["<"]
				eType_Logical_LessOrEqual,   // ["<="]
				eType_Logical_Equal,         // ["=="]
				eType_Logical_GreaterThan,   // [">"]
				eType_Logical_GreaterOrEqual,// [">="]
				eType_Logical_All,           // ["all"]
				eType_Logical_Any,           // ["any"]
				eType_Logical_Case,          // ["case"]
				eType_Logical_Coalesce,      // ["coalesce"]
				eType_Logical_Match,         // ["match"]
				eType_Logical_Within,        // ["within"]
		
				// String operators
				eType_String_Concat,         // ["concat"]
				eType_String_Downcase,       // ["downcase"]
				eType_String_Upcase,         // ["upcase"]
				eType_String_IsSupportedScript, // ["is-supported-script"]
				eType_String_ResolvedLocale,  // ["resolved-locale"]
				eType_String_Format,          // ["format"]
		
				// Data operators
				eType_Data_Get,              // ["get"]
				eType_Data_Has,               // ["has"]
				eType_Data_At,                // ["at"]
				eType_Data_In,                // ["in"]
				eType_Data_IndexOf,           // ["index-of"]
				eType_Data_Length,            // ["length"]
				eType_Data_Slice,             // ["slice"]
				eType_Data_FeatureState,      // ["feature-state"]
				eType_Data_GeometryType,      // ["geometry-type"]
				eType_Data_Id,                // ["id"]
				eType_Data_LineProgress,      // ["line-progress"]
				eType_Data_Properties,        // ["properties"]
				eType_Data_Accumulated,       // ["accumulated"]
		
				// Camera operators
				eType_Camera_Zoom,            // ["zoom"]
				eType_Camera_Pitch,            // ["pitch"]
				eType_Camera_DistanceFromCenter, // ["distance-from-center"]
				eType_Camera_MeasureLight,     // ["measure-light"]
		
				// Color operators
				eType_Color_Rgb,              // ["rgb"]
				eType_Color_Rgba,             // ["rgba"]
				eType_Color_Hsl,              // ["hsl"]
				eType_Color_Hsla,             // ["hsla"]
				eType_Color_ToRgba,           // ["to-rgba"]
				eType_Color_ToHsla,           // ["to-hsla"]
		
				// Heatmap operator
				eType_Heatmap_Density,        // ["heatmap-density"]
		
				// Variable binding
				eType_Variable_Let,           // ["let"]
				eType_Variable_Var,           // ["var"]
		
				// Type conversion
				eType_Conversion_ToBoolean,   // ["to-boolean"]
				eType_Conversion_ToColor,     // ["to-color"]
				eType_Conversion_ToNumber,    // ["to-number"]
				eType_Conversion_ToString,    // ["to-string"]
				eType_Conversion_TypeOf,      // ["typeof"]
		
				// Type assertion
				eType_Assertion_Array,        // ["array"]
				eType_Assertion_Boolean,      // ["boolean"]
				eType_Assertion_Number,       // ["number"]
				eType_Assertion_Object,      // ["object"]
				eType_Assertion_String,      // ["string"]
		
				// Interpolation
				eType_Interpolation_Interpolate,  // ["interpolate"]
				eType_Interpolation_InterpolateHcl, // ["interpolate-hcl"]
				eType_Interpolation_InterpolateLab, // ["interpolate-lab"]
				eType_Interpolation_Step,     // ["step"]
		
				// Literal
				eType_Literal,                // ["literal"]
				eType_NumberFormat,           // ["number-format"]
				eType_Image,                  // ["image"]
				eType_Collator,               // ["collator"]

				eType_End,
			};

			constexpr std::array<EnumPair<eType>, static_cast<size_t>(eType::eType_End)> TYPE_LIST = {{
				{eType::eType_None, "none"},
		
				// Math operators
				{eType::eType_Math_Add, "+"},
				{eType::eType_Math_Subtract, "-"},
				{eType::eType_Math_Multiply, "*"},
				{eType::eType_Math_Divide, "/"},
				{eType::eType_Math_Modulo, "%"},
				{eType::eType_Math_Power, "^"},
				{eType::eType_Math_Abs, "abs"},
				{eType::eType_Math_Acos, "acos"},
				{eType::eType_Math_Asin, "asin"},
				{eType::eType_Math_Atan, "atan"},
				{eType::eType_Math_Ceil, "ceil"},
				{eType::eType_Math_Cos, "cos"},
				{eType::eType_Math_Distance, "distance"},
				{eType::eType_Math_Floor, "floor"},
				{eType::eType_Math_Ln, "ln"},
				{eType::eType_Math_Log10, "log10"},
				{eType::eType_Math_Log2, "log2"},
				{eType::eType_Math_Max, "max"},
				{eType::eType_Math_Min, "min"},
				{eType::eType_Math_Round, "round"},
				{eType::eType_Math_Sin, "sin"},
				{eType::eType_Math_Sqrt, "sqrt"},
				{eType::eType_Math_Tan, "tan"},
				{eType::eType_Math_Pi, "pi"},
				{eType::eType_Math_E, "e"},
				{eType::eType_Math_Ln2, "ln2"},
				{eType::eType_Math_Random, "random"},
		
				// Logical operators
				{eType::eType_Logical_Not, "!"},
				{eType::eType_Logical_NotEqual, "!="},
				{eType::eType_Logical_LessThan, "<"},
				{eType::eType_Logical_LessOrEqual, "<="},
				{eType::eType_Logical_Equal, "=="},
				{eType::eType_Logical_GreaterThan, ">"},
				{eType::eType_Logical_GreaterOrEqual, ">="},
				{eType::eType_Logical_All, "all"},
				{eType::eType_Logical_Any, "any"},
				{eType::eType_Logical_Case, "case"},
				{eType::eType_Logical_Coalesce, "coalesce"},
				{eType::eType_Logical_Match, "match"},
				{eType::eType_Logical_Within, "within"},
		
				// String operators
				{eType::eType_String_Concat, "concat"},
				{eType::eType_String_Downcase, "downcase"},
				{eType::eType_String_Upcase, "upcase"},
				{eType::eType_String_IsSupportedScript, "is-supported-script"},
				{eType::eType_String_ResolvedLocale, "resolved-locale"},
				{eType::eType_String_Format, "format"},
		
				// Data operators
				{eType::eType_Data_Get, "get"},
				{eType::eType_Data_Has, "has"},
				{eType::eType_Data_At, "at"},
				{eType::eType_Data_In, "in"},
				{eType::eType_Data_IndexOf, "index-of"},
				{eType::eType_Data_Length, "length"},
				{eType::eType_Data_Slice, "slice"},
				{eType::eType_Data_FeatureState, "feature-state"},
				{eType::eType_Data_GeometryType, "geometry-type"},
				{eType::eType_Data_Id, "id"},
				{eType::eType_Data_LineProgress, "line-progress"},
				{eType::eType_Data_Properties, "properties"},
				{eType::eType_Data_Accumulated, "accumulated"},
		
				// Camera operators
				{eType::eType_Camera_Zoom, "zoom"},
				{eType::eType_Camera_Pitch, "pitch"},
				{eType::eType_Camera_DistanceFromCenter, "distance-from-center"},
				{eType::eType_Camera_MeasureLight, "measure-light"},
		
				// Color operators
				{eType::eType_Color_Rgb, "rgb"},
				{eType::eType_Color_Rgba, "rgba"},
				{eType::eType_Color_Hsl, "hsl"},
				{eType::eType_Color_Hsla, "hsla"},
				{eType::eType_Color_ToRgba, "to-rgba"},
				{eType::eType_Color_ToHsla, "to-hsla"},
		
				// Heatmap operator
				{eType::eType_Heatmap_Density, "heatmap-density"},
		
				// Variable binding
				{eType::eType_Variable_Let, "let"},
				{eType::eType_Variable_Var, "var"},
		
				// Type conversion
				{eType::eType_Conversion_ToBoolean, "to-boolean"},
				{eType::eType_Conversion_ToColor, "to-color"},
				{eType::eType_Conversion_ToNumber, "to-number"},
				{eType::eType_Conversion_ToString, "to-string"},
				{eType::eType_Conversion_TypeOf, "typeof"},
		
				// Type assertion
				{eType::eType_Assertion_Array, "array"},
				{eType::eType_Assertion_Boolean, "boolean"},
				{eType::eType_Assertion_Number, "number"},
				{eType::eType_Assertion_Object, "object"},
				{eType::eType_Assertion_String, "string"},
		
				// Interpolation
				{eType::eType_Interpolation_Interpolate, "interpolate"},
				{eType::eType_Interpolation_InterpolateHcl, "interpolate-hcl"},
				{eType::eType_Interpolation_InterpolateLab, "interpolate-lab"},
				{eType::eType_Interpolation_Step, "step"},
		
				// Literal
				{eType::eType_Literal, "literal"},
				{eType::eType_NumberFormat, "number-format"},
				{eType::eType_Image, "image"},
				{eType::eType_Collator, "collator"}
			}};
		};
	};
};

#endif // __STYLEJSON_ENUM_H__