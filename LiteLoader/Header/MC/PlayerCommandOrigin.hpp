// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
#include "../Utils/Json.h"
#include "Json.hpp"
#include "CommandOrigin.hpp"
#define EXTRA_INCLUDE_PART_PLAYERCOMMANDORIGIN
#include "Extra/PlayerCommandOriginAPI.hpp"
#undef EXTRA_INCLUDE_PART_PLAYERCOMMANDORIGIN
class PlayerCommandOrigin : public CommandOrigin {
#include "Extra/PlayerCommandOriginAPI.hpp"
public:
    /*0*/ virtual ~PlayerCommandOrigin();
    /*1*/ virtual std::string const& getRequestId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual class BlockPos getBlockPosition() const;
    /*4*/ virtual class Vec3 getWorldPosition() const;
    /*5*/ virtual class Level* getLevel() const;
    /*6*/ virtual class Dimension* getDimension() const;
    /*7*/ virtual class Actor* getEntity() const;
    /*8*/ virtual int /*enum CommandPermissionLevel*/ getPermissionsLevel() const;
    /*9*/ virtual std::unique_ptr<class CommandOrigin> clone() const;
    /*10*/ virtual class std::optional<class BlockPos> getCursorHitBlockPos() const;
    /*11*/ virtual class std::optional<class Vec3> getCursorHitPos() const;
    /*14*/ virtual bool canUseAbility(int /*enum AbilitiesIndex*/) const;
    /*16*/ virtual bool canUseCommandsWithoutCheatsEnabled() const;
    /*17*/ virtual bool isSelectorExpansionAllowed() const;
    /*18*/ virtual class NetworkIdentifier const& getSourceId() const;
    /*19*/ virtual unsigned char getSourceSubId() const;
    /*20*/ virtual class CommandOrigin const& getOutputReceiver() const;
    /*21*/ virtual struct CommandOriginIdentity getIdentity() const;
    /*22*/ virtual int /*enum CommandOriginType*/ getOriginType() const;
    /*24*/ virtual class mce::UUID const& getUUID() const;
    /*25*/ virtual void handleCommandOutputCallback(class Json::Value&&) const;
    /*26*/ virtual class CompoundTag serialize() const;
    /*27*/ virtual bool isValid() const;

public:
    MCAPI static std::unique_ptr<class PlayerCommandOrigin> load(class CompoundTag const&, class Level&);
};