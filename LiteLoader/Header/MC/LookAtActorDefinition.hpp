// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
#include "../Utils/Json.h"
#include "Json.hpp"
#include "BehaviorDefinition.hpp"
#define EXTRA_INCLUDE_PART_LOOKATACTORDEFINITION
#include "Extra/LookAtActorDefinitionAPI.hpp"
#undef EXTRA_INCLUDE_PART_LOOKATACTORDEFINITION
class LookAtActorDefinition : public BehaviorDefinition {
#include "Extra/LookAtActorDefinitionAPI.hpp"
public:
    /*0*/ virtual ~LookAtActorDefinition();
    /*1*/ virtual void load(class Json::Value, class BehaviorFactory const&);
};