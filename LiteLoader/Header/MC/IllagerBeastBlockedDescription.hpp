// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
#include "../Utils/Json.h"
#include "Json.hpp"
#define EXTRA_INCLUDE_PART_ILLAGERBEASTBLOCKEDDESCRIPTION
#include "Extra/IllagerBeastBlockedDescriptionAPI.hpp"
#undef EXTRA_INCLUDE_PART_ILLAGERBEASTBLOCKEDDESCRIPTION
class IllagerBeastBlockedDescription {
#include "Extra/IllagerBeastBlockedDescriptionAPI.hpp"
public:
    /*0*/ virtual char const* getJsonName() const;
    /*1*/ virtual ~IllagerBeastBlockedDescription();
    /*2*/ virtual void deserializeData(struct DeserializeDataParams);
    /*3*/ virtual void serializeData(class Json::Value&) const;
};