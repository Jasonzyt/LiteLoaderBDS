// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Packet.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class UpdateTradePacket : public Packet {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_UPDATETRADEPACKET
public:
    class UpdateTradePacket& operator=(class UpdateTradePacket const &) = delete;
    UpdateTradePacket(class UpdateTradePacket const &) = delete;
#endif

public:
    /*0*/ virtual ~UpdateTradePacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream &) const;
    /*5*/ virtual bool disallowBatching() const;
    /*6*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream &);
    MCAPI UpdateTradePacket(enum ContainerID, enum ContainerType, int, std::string const &, class CompoundTag &&, struct ActorUniqueID const &, struct ActorUniqueID const &, int, bool, bool);
    MCAPI UpdateTradePacket();

protected:

private:

};