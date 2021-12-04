// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
#include "../Utils/Json.h"
#include "SplashPotionEffectSubcomponent.hpp"
#include "Json.hpp"
#define EXTRA_INCLUDE_PART_THROWNPOTIONEFFECTSUBCOMPONENT
#include "Extra/ThrownPotionEffectSubcomponentAPI.hpp"
#undef EXTRA_INCLUDE_PART_THROWNPOTIONEFFECTSUBCOMPONENT
class ThrownPotionEffectSubcomponent : public SplashPotionEffectSubcomponent {
#include "Extra/ThrownPotionEffectSubcomponentAPI.hpp"
public:
    /*0*/ virtual ~ThrownPotionEffectSubcomponent();
    /*2*/ virtual void writetoJSON(class Json::Value&) const;
    /*3*/ virtual void doOnHitEffect(class Actor&, class ProjectileComponent&);
    /*4*/ virtual char const* getName();
};