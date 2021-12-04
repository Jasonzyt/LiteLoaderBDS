// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
#include "../Utils/Json.h"
#include "Json.hpp"
#include "BehaviorDefinition.hpp"
#define EXTRA_INCLUDE_PART_ATTACKDEFINITION
#include "Extra/AttackDefinitionAPI.hpp"
#undef EXTRA_INCLUDE_PART_ATTACKDEFINITION
class AttackDefinition : public BehaviorDefinition {
#include "Extra/AttackDefinitionAPI.hpp"
public:
    /*0*/ virtual ~AttackDefinition();
    /*1*/ virtual void load(class Json::Value, class BehaviorFactory const&);
};