// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
#include "../Utils/Json.h"
#include "Json.hpp"
#define EXTRA_INCLUDE_PART_STICKINGROUNDSUBCOMPONENT
#include "Extra/StickInGroundSubcomponentAPI.hpp"
#undef EXTRA_INCLUDE_PART_STICKINGROUNDSUBCOMPONENT
class StickInGroundSubcomponent {
#include "Extra/StickInGroundSubcomponentAPI.hpp"
public:
    /*0*/ virtual ~StickInGroundSubcomponent();
    /*1*/ virtual void readfromJSON(class Json::Value&, class SemVersion const&);
    /*2*/ virtual void writetoJSON(class Json::Value&) const;
    /*3*/ virtual void doOnHitEffect(class Actor&, class ProjectileComponent&);
    /*4*/ virtual char const* getName();
};