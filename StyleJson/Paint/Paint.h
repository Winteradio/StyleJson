#ifndef __STYLEJSON_PAINT_H__
#define __STYLEJSON_PAINT_H__

#include "Property/Property.h"
#include "Property/PropertyValue.h"

namespace StyleJson
{
	namespace Paint
	{
		class LinePaintColor : public PropertyValue<Color> {};
		class LinePaintWidth : public PropertyValue<float> {};
	
		class LinePaintProperty : public Property<LinePaintColor
												, LinePaintWidth> {};
	
		class FillPaintColor : public PropertyValue<float> {};
	
		class FillPaintProperty : public Property<FillPaintColor> {};
	};
};

#endif // __STYLEJSON_PAINT_H__