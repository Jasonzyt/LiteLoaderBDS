// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
#include "../Utils/Json.h"
#include "Json.hpp"
#define EXTRA_INCLUDE_PART_PUSHABLEDESCRIPTION
#include "Extra/PushableDescriptionAPI.hpp"
#undef EXTRA_INCLUDE_PART_PUSHABLEDESCRIPTION
struct PushableDescription {
#include "Extra/PushableDescriptionAPI.hpp"
public:
    /*0*/ virtual char const* getJsonName() const;
    /*1*/ virtual ~PushableDescription();
    /*2*/ virtual void deserializeData(struct DeserializeDataParams);
    /*3*/ virtual void serializeData(class Json::Value&) const;
};