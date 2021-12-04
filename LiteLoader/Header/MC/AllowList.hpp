// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
#include "../Utils/Json.h"
#include "Json.hpp"
#define EXTRA_INCLUDE_PART_ALLOWLIST
#include "Extra/AllowListAPI.hpp"
#undef EXTRA_INCLUDE_PART_ALLOWLIST
class AllowList {
#include "Extra/AllowListAPI.hpp"
public:
    /*0*/ virtual ~AllowList();
    /*1*/ virtual void serialize(class Json::Value&);
    /*2*/ virtual void deserialize(class Json::Value&);

public:
    MCAPI bool addEntry(class AllowListEntry const&);
    MCAPI std::vector<class AllowListEntry> const& getEntries() const;
    MCAPI bool isAllowed(class mce::UUID const&, std::string const&) const;
    MCAPI bool isIgnoringPlayerLimit(class mce::UUID const&, std::string const&) const;
    MCAPI bool removeByName(std::string const&);
    MCAPI void tryUpdateEntries(class mce::UUID const&, std::string const&, std::string const&);
};