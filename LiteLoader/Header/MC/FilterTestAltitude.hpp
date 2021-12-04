// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
#include "../Utils/Json.h"
#include "Json.hpp"
#include "FilterTest.hpp"
#define EXTRA_INCLUDE_PART_FILTERTESTALTITUDE
#include "Extra/FilterTestAltitudeAPI.hpp"
#undef EXTRA_INCLUDE_PART_FILTERTESTALTITUDE
class FilterTestAltitude : public FilterTest {
#include "Extra/FilterTestAltitudeAPI.hpp"
public:
    /*0*/ virtual ~FilterTestAltitude();
    /*2*/ virtual bool evaluate(struct FilterContext const&) const;
    /*3*/ virtual void finalizeParsedValue(class IWorldRegistriesProvider&);
    /*4*/ virtual class gsl::basic_string_span<char const, -1> getName() const;
    /*6*/ virtual class Json::Value _serializeValue() const;
};