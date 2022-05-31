// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "BaseMoveToBlockGoal.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class HarvestFarmBlockGoal : public BaseMoveToBlockGoal {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_HARVESTFARMBLOCKGOAL
public:
    class HarvestFarmBlockGoal& operator=(class HarvestFarmBlockGoal const &) = delete;
    HarvestFarmBlockGoal(class HarvestFarmBlockGoal const &) = delete;
    HarvestFarmBlockGoal() = delete;
#endif

public:
    /*0*/ virtual ~HarvestFarmBlockGoal();
    /*1*/ virtual bool canUse();
    /*2*/ virtual bool canContinueToUse();
    /*3*/ virtual void __unk_vfn_3();
    /*4*/ virtual void start();
    /*5*/ virtual void stop();
    /*6*/ virtual void tick();
    /*7*/ virtual void appendDebugInfo(std::string &) const;
    /*8*/ virtual void __unk_vfn_8();
    /*9*/ virtual void __unk_vfn_9();
    /*11*/ virtual bool isValidTarget(class BlockSource &, class BlockPos const &);
    /*16*/ virtual unsigned __int64 _getRepathTime() const;
    MCAPI HarvestFarmBlockGoal(class Mob &);

protected:
    MCAPI bool trySowCrop(class BlockSource &, class BlockPos const &);

private:

};