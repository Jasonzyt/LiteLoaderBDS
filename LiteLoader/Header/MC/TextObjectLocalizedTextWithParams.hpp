// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
#include "../Utils/Json.h"
#include "Json.hpp"
#define EXTRA_INCLUDE_PART_TEXTOBJECTLOCALIZEDTEXTWITHPARAMS
#include "Extra/TextObjectLocalizedTextWithParamsAPI.hpp"
#undef EXTRA_INCLUDE_PART_TEXTOBJECTLOCALIZEDTEXTWITHPARAMS
class TextObjectLocalizedTextWithParams {
#include "Extra/TextObjectLocalizedTextWithParamsAPI.hpp"
public:
    /*0*/ virtual ~TextObjectLocalizedTextWithParams();
    /*1*/ virtual std::string asString() const;
    /*2*/ virtual class Json::Value asJsonValue() const;
    /*3*/ virtual class Json::Value resolve(struct ResolveData const&) const;
};