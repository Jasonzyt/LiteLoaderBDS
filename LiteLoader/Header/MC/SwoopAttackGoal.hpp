// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class SwoopAttackGoal {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SWOOPATTACKGOAL
public:
    class SwoopAttackGoal& operator=(class SwoopAttackGoal const &) = delete;
    SwoopAttackGoal(class SwoopAttackGoal const &) = delete;
    SwoopAttackGoal() = delete;
#endif

public:
    /*0*/ virtual ~SwoopAttackGoal();
    /*1*/ virtual bool canUse();
    /*2*/ virtual bool canContinueToUse();
    /*3*/ virtual void __unk_vfn_3();
    /*4*/ virtual void start();
    /*5*/ virtual void stop();
    /*6*/ virtual void tick();
    /*7*/ virtual void appendDebugInfo(std::string &) const;
    MCAPI SwoopAttackGoal(class Mob &);

protected:

private:

};