// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Feature.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class HellSpringFeature : public Feature {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_HELLSPRINGFEATURE
public:
    class HellSpringFeature& operator=(class HellSpringFeature const &) = delete;
    HellSpringFeature(class HellSpringFeature const &) = delete;
    HellSpringFeature() = delete;
#endif

public:
    /*0*/ virtual ~HellSpringFeature();
    /*2*/ virtual void __unk_vfn_2();
    /*3*/ virtual bool place(class BlockSource &, class BlockPos const &, class Random &) const;
    MCAPI HellSpringFeature(class Block const &, bool);

protected:

private:

};