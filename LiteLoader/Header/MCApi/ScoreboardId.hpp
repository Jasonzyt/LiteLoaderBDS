// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
struct ScoreboardId {

public:
    MCAPI class IdentityDefinition const& getIdentityDef() const;
    MCAPI bool operator!=(struct ScoreboardId const&);
    MCAPI bool operator==(struct ScoreboardId const&);
    MCAPI struct ScoreboardId& operator=(struct ScoreboardId const&);
    MCAPI unsigned __int64 getHash() const;
    MCAPI bool isValid() const;

    MCAPI static struct ScoreboardId INVALID;
};