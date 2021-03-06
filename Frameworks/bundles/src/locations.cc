#include "locations.h"
#include <io/path.h>
#include <OakSystem/application.h>
#include <oak/duration.h>
#include <oak/debug.h>

namespace bundles
{
	static std::vector<std::string>& locations_vector ()
	{
		static std::string const BundleLocations[] =
		{
			path::join(path::home(), "Library/Application Support/Avian"),
			path::join(path::home(), "Library/Application Support/Avian/Pristine Copy"),
			// path::join(path::home(), "Library/Application Support/TextMate"), // FIXME this location is just for testing tmDelta
			path::join(path::home(), "Library/Application Support/TextMate/Managed"),
			path::join("/",          "Library/Application Support/Avian"),
			path::join("/",          "Library/Application Support/Avian/Pristine Copy"),
			oak::application_t::path("Contents/SharedSupport"),
			// "/Users/duff/Oak/Avian/Applications/Avian/Avian.app/Contents/SharedSupport"
		};
		static std::vector<std::string> res(BundleLocations, BundleLocations + sizeofA(BundleLocations));
		return res;
	}

	std::vector<std::string> const& locations ()
	{
		return locations_vector();
	}

	void set_locations (std::vector<std::string> const& newLocations)
	{
		locations_vector() = newLocations;
	}

} /* bundles */
