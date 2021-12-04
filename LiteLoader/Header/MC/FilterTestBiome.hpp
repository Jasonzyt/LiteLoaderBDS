// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
#include "../Utils/Json.h"
#include "Json.hpp"
#include "FilterTest.hpp"
#define EXTRA_INCLUDE_PART_FILTERTESTBIOME
#include "Extra/FilterTestBiomeAPI.hpp"
#undef EXTRA_INCLUDE_PART_FILTERTESTBIOME
class FilterTestBiome : public FilterTest {
#include "Extra/FilterTestBiomeAPI.hpp"
public:
    /*0*/ virtual ~FilterTestBiome();
    /*2*/ virtual bool evaluate(struct FilterContext const&) const;
    /*3*/ virtual void finalizeParsedValue(class IWorldRegistriesProvider&);
    /*4*/ virtual class gsl::basic_string_span<char const, -1> getName() const;
    /*6*/ virtual class Json::Value _serializeValue() const;
};