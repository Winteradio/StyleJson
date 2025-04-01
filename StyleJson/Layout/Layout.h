#ifndef __STYLEJSON_LAYOUT_H__
#define __STYLEJSON_LAYOUT_H__

#include "Property/Property.h"

namespace StyleJson
{
	namespace Layout
	{
		struct LineSortKey {};

		class LineLayoutProperty : public Property<LineSortKey> {};

		struct FillSortKey {};

		class FillLayoutProperty : public Property<FillSortKey> {};

	};
};

#endif // __STYLEJSON_LAYOUT_H__