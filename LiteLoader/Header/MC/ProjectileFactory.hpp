// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
#include "../Utils/Json.h"
#include "Json.hpp"
#define EXTRA_INCLUDE_PART_PROJECTILEFACTORY
#include "Extra/ProjectileFactoryAPI.hpp"
#undef EXTRA_INCLUDE_PART_PROJECTILEFACTORY
class ProjectileFactory {
#include "Extra/ProjectileFactoryAPI.hpp"

public:
    MCAPI bool shootProjectileFromDefinition(struct ActorDefinitionIdentifier const&, class Mob*, class Vec3);

    MCAPI static std::unique_ptr<class OnHitSubcomponent> createSubcomponent(class Json::Value&, class SemVersion const&, std::string const&);
    MCAPI static void initFactory();
    MCAPI static void shutdown();
};