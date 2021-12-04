// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
#include "../Utils/Json.h"
#include "Json.hpp"
#include "JsonUtil.hpp"
#define EXTRA_INCLUDE_PART_BLOCKDEFINITIONGROUP
#include "Extra/BlockDefinitionGroupAPI.hpp"
#undef EXTRA_INCLUDE_PART_BLOCKDEFINITIONGROUP
class BlockDefinitionGroup {
#include "Extra/BlockDefinitionGroupAPI.hpp"

public:
    MCAPI void buildBlockSchema(class BlockComponentFactory const&);
    MCAPI void digestServerBlockProperties(std::vector<struct std::pair<std::string, class CompoundTag>> const&, class BlockComponentFactory const&);
    MCAPI std::unique_ptr<struct BlockDefinition> generateBlockDefinition(struct BlockDefinitionGroup::BlockResource const&, class Experiments const&);
    MCAPI std::vector<struct std::pair<std::string, class CompoundTag>> generateServerBlockProperties() const;
    MCAPI std::vector<struct BlockDefinition const*> getBlockDefinitions() const;
    MCAPI void initializeBlockFromDefinition(struct BlockDefinition const&, class EntityRegistryOwned&, class Level&);
    MCAPI void initializeBlocks(class EntityRegistryOwned&, class Level&);
    MCAPI void loadResources(class ResourcePackManager&, class BlockComponentFactory const&, class Experiments const&);
    MCAPI void registerBlockDefinition(std::unique_ptr<struct BlockDefinition>);
    MCAPI void registerBlockFromDefinition(struct BlockDefinition const&, bool);
    MCAPI void registerBlocks();

private:
    MCAPI void _buildBlockComponentsSchema(class std::shared_ptr<class JsonUtil::JsonSchemaObjectNode<class JsonUtil::EmptyClass, struct BlockComponentGroupDescription>>&, class BlockComponentFactory const&);
    MCAPI void _buildBlockDescriptionSchema(class std::shared_ptr<class JsonUtil::JsonSchemaObjectNode<class JsonUtil::EmptyClass, struct BlockDescription>>&);
    MCAPI bool _loadBlockDescription(class Json::Value const&, struct BlockDescription&);
    MCAPI bool _loadComponents(class Json::Value const&, struct BlockDefinition&, class Experiments const&);
    MCAPI bool _loadEvents(class Json::Value const&, struct BlockDefinition&);
    MCAPI bool _parseComponents(class Json::Value const&, struct BlockComponentGroupDescription&, std::string const&, class SemVersion const&, class Experiments const&);
};