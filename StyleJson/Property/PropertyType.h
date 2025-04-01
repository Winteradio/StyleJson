#ifndef __STYLEJSON_PROPERTYTYPE_H__
#define __STYLEJSON_PROPERTYTYPE_H__

namespace StyleJson
{
	struct Color
	{
		float Red;
		float Blue;
		float Green;
		float Alpha;

		Color()
			: Red(0.f)
			, Blue(0.f)
			, Green(0.f)
			, Alpha(0.f)
		{}

		Color(const float _red, const float _blue, const float _green, const float _alpha)
			: Red(_red)
			, Blue(_blue)
			, Green(_green)
			, Alpha(_alpha)
		{}
	};
};

#endif // __STYLEJSON_PROPERTYTYPE_H__