// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "BaseCircuitComponent.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class PoweredBlockComponent : public BaseCircuitComponent {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_POWEREDBLOCKCOMPONENT
public:
    class PoweredBlockComponent& operator=(class PoweredBlockComponent const &) = delete;
    PoweredBlockComponent(class PoweredBlockComponent const &) = delete;
    PoweredBlockComponent() = delete;
#endif

public:
    /*0*/ virtual ~PoweredBlockComponent();
    /*1*/ virtual int getStrength() const;
    /*7*/ virtual bool canConsumerPower() const;
    /*8*/ virtual bool canStopPower() const;
    /*9*/ virtual void setStopPower(bool);
    /*11*/ virtual bool addSource(class CircuitSceneGraph &, class CircuitTrackingInfo const &, int &, bool &);
    /*12*/ virtual bool allowConnection(class CircuitSceneGraph &, class CircuitTrackingInfo const &, bool &);
    /*13*/ virtual void checkLock(class CircuitSystem &, class BlockPos const &);
    /*14*/ virtual bool evaluate(class CircuitSystem &, class BlockPos const &);
    /*15*/ virtual void cacheValues(class CircuitSystem &, class BlockPos const &);
    /*16*/ virtual void updateDependencies(class CircuitSceneGraph &, class BlockPos const &);
    /*17*/ virtual void __unk_vfn_17();
    /*18*/ virtual bool isHalfPulse() const;
    /*20*/ virtual bool hasChildrenSource() const;
    /*21*/ virtual bool isSecondaryPowered() const;
    /*22*/ virtual enum CircuitComponentType getCircuitComponentType() const;
    MCAPI PoweredBlockComponent(unsigned char);

protected:

private:

};