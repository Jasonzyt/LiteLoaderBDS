// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
#include "../Utils/Json.h"
#include "Json.hpp"
#define EXTRA_INCLUDE_PART_NPCDIALOGUESCENE
#include "Extra/NpcDialogueSceneAPI.hpp"
#undef EXTRA_INCLUDE_PART_NPCDIALOGUESCENE
struct NpcDialogueScene {
#include "Extra/NpcDialogueSceneAPI.hpp"

public:
    MCAPI static struct NpcDialogueScene parse(class Json::Value const&, std::string const&, int);
};