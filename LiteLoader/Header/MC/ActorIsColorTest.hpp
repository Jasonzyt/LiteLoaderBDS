// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
#include "../Utils/Json.h"
#include "Json.hpp"
#include "FilterTest.hpp"
#define EXTRA_INCLUDE_PART_ACTORISCOLORTEST
#include "Extra/ActorIsColorTestAPI.hpp"
#undef EXTRA_INCLUDE_PART_ACTORISCOLORTEST
class ActorIsColorTest : public FilterTest {
#include "Extra/ActorIsColorTestAPI.hpp"
public:
    /*0*/ virtual ~ActorIsColorTest();
    /*2*/ virtual bool evaluate(struct FilterContext const&) const;
    /*3*/ virtual void finalizeParsedValue(class IWorldRegistriesProvider&);
    /*4*/ virtual class gsl::basic_string_span<char const, -1> getName() const;
    /*6*/ virtual class Json::Value _serializeValue() const;
};