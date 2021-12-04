// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
#include "../Utils/Json.h"
#include "Json.hpp"
#include "BehaviorDefinition.hpp"
#define EXTRA_INCLUDE_PART_BREAKBLOCKDEFINITION
#include "Extra/BreakBlockDefinitionAPI.hpp"
#undef EXTRA_INCLUDE_PART_BREAKBLOCKDEFINITION
class BreakBlockDefinition : public BehaviorDefinition {
#include "Extra/BreakBlockDefinitionAPI.hpp"
public:
    /*0*/ virtual ~BreakBlockDefinition();
    /*1*/ virtual void load(class Json::Value, class BehaviorFactory const&);
};