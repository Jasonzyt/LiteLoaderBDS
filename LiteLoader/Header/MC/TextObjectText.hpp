// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
#include "../Utils/Json.h"
#include "Json.hpp"
#define EXTRA_INCLUDE_PART_TEXTOBJECTTEXT
#include "Extra/TextObjectTextAPI.hpp"
#undef EXTRA_INCLUDE_PART_TEXTOBJECTTEXT
class TextObjectText {
#include "Extra/TextObjectTextAPI.hpp"
public:
    /*0*/ virtual ~TextObjectText();
    /*1*/ virtual std::string asString() const;
    /*2*/ virtual class Json::Value asJsonValue() const;
    /*3*/ virtual class Json::Value resolve(struct ResolveData const&) const;

public:
    MCAPI static class Json::Value asJsonValue(std::string const&);
};