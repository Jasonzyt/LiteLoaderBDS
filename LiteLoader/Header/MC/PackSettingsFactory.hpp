// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
#include "../Utils/Json.h"
#include "Json.hpp"
#define EXTRA_INCLUDE_PART_PACKSETTINGSFACTORY
#include "Extra/PackSettingsFactoryAPI.hpp"
#undef EXTRA_INCLUDE_PART_PACKSETTINGSFACTORY
class PackSettingsFactory {
#include "Extra/PackSettingsFactoryAPI.hpp"

public:
    MCAPI class PackSettings* getPackSettings(class PackManifest const&);
    MCAPI class PackSettings* loadPackSettings(struct PackIdVersion const&, class Json::Value const&);
};