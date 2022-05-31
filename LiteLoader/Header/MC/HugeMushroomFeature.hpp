// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Feature.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class HugeMushroomFeature : public Feature {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_HUGEMUSHROOMFEATURE
public:
    class HugeMushroomFeature& operator=(class HugeMushroomFeature const &) = delete;
    HugeMushroomFeature(class HugeMushroomFeature const &) = delete;
#endif

public:
    /*0*/ virtual ~HugeMushroomFeature();
    /*2*/ virtual void __unk_vfn_2();
    /*3*/ virtual bool place(class BlockSource &, class BlockPos const &, class Random &) const;
    MCAPI HugeMushroomFeature(int);
    MCAPI HugeMushroomFeature();
    MCAPI bool placeFixed(class BlockSource &, class BlockPos const &, int, int) const;

protected:

private:
    MCAPI bool _canSurvive(class Block const &) const;

};