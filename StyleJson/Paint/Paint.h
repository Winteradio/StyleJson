#ifndef __STYLEJSON_PAINT_H__
#define __STYLEJSON_PAINT_H__

#include "Property/Property.h"
#include "Property/PropertyValue.h"

namespace StyleJson
{
	namespace Paint
	{
		struct LinePaintColor : PropertyValue<Color> {};
		struct LinePaintWidth : PropertyValue<float> {};
	
		using LinePaintProperty = Property<LinePaintColor
										, LinePaintWidth>;
	
		struct FillPaintColor : PropertyValue<float> {};
	
		using FillPaintProperty = Property<FillPaintColor>;
	};
};

#endif // __STYLEJSON_PAINT_H__