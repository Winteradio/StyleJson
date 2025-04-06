#ifndef __STYLEJSON_LAYOUT_H__
#define __STYLEJSON_LAYOUT_H__

#include "Property/Property.h"
#include "Property/PropertyValue.h"

namespace StyleJson
{
	namespace Layout
	{
		struct LineSortKey : public PropertyValue<int64_t> {};

		class LineLayoutProperty : public Property<LineSortKey> {};

		struct FillSortKey : public PropertyValue<int64_t> {};

		class FillLayoutProperty : public Property<FillSortKey> {};

		struct SymbolSortKey : public PropertyValue<int64_t> {};
		struct SymbolIcomImage : public PropertyValue<std::string> {};

		class SymbolLayoutProperty : public Property<SymbolSortKey
													, SymbolIcomImage> {};
	};
};

#endif // __STYLEJSON_LAYOUT_H__