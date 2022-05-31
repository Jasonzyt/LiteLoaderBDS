// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Actor.hpp"
#include "Mob.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ArmorStand : public Mob {

#define AFTER_EXTRA
// Add Member There
public:
struct Pose {
    Pose() = delete;
    Pose(Pose const&) = delete;
    Pose(Pose const&&) = delete;
};

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ARMORSTAND
public:
    class ArmorStand& operator=(class ArmorStand const &) = delete;
    ArmorStand(class ArmorStand const &) = delete;
    ArmorStand() = delete;
#endif

public:
    /*14*/ virtual ~ArmorStand();
    /*16*/ virtual void resetUserPos(bool);
    /*20*/ virtual bool isRuntimePredictedMovementEnabled() const;
    /*36*/ virtual class Vec3 getInterpolatedRidingOffset(float) const;
    /*40*/ virtual bool breaksFallingBlocks() const;
    /*48*/ virtual void normalTick();
    /*61*/ virtual bool canExistInPeaceful() const;
    /*68*/ virtual bool canMakeStepSound() const;
    /*78*/ virtual float getCameraOffset() const;
    /*80*/ virtual float getShadowRadius() const;
    /*82*/ virtual bool canSeeInvisible() const;
    /*85*/ virtual bool canInteractWithOtherEntitiesInGame() const;
    /*88*/ virtual bool interactPreventDefault();
    /*89*/ virtual void playerTouch(class Player &);
    /*94*/ virtual bool isPickable();
    /*95*/ virtual bool isFishable() const;
    /*98*/ virtual bool useNewAi() const;
    /*101*/ virtual bool isDamageBlocked(class ActorDamageSource const &) const;
    /*105*/ virtual bool shouldBurn();
    /*107*/ virtual bool isTargetable() const;
    /*108*/ virtual bool canBeControlledByPassenger();
    /*109*/ virtual bool isLeashableType();
    /*113*/ virtual class Actor * findAttackTarget();
    /*114*/ virtual bool isValidTarget(class Actor *) const;
    /*120*/ virtual void onTame();
    /*121*/ virtual void onFailedTame();
    /*130*/ virtual void vehicleLanded(class Vec3 const &, class Vec3 const &);
    /*134*/ virtual bool isInvulnerableTo(class ActorDamageSource const &) const;
    /*139*/ virtual void onBounceStarted(class BlockPos const &, class Block const &);
    /*142*/ virtual float getPickRadius();
    /*151*/ virtual void awardKillScore(class Actor &, int);
    /*170*/ virtual class HashedString const & queryEntityRenderer() const;
    /*171*/ virtual struct ActorUniqueID getSourceUniqueID() const;
    /*178*/ virtual int getPortalWaitTime() const;
    /*180*/ virtual bool canChangeDimensions() const;
    /*181*/ virtual void onHit(class HitResult const &);
    /*183*/ virtual struct ActorUniqueID getControllingPlayer() const;
    /*192*/ virtual bool canPickupItem(class ItemStack const &) const;
    /*193*/ virtual bool canBePulledIntoVehicle() const;
    /*195*/ virtual bool stopUponGroundCollision() const;
    /*198*/ virtual bool canSynchronizeNewEntity() const;
    /*220*/ virtual void __unk_vfn_220();
    /*221*/ virtual unsigned int getUserId() const;
    /*227*/ virtual float getYHeadRotO() const;
    /*228*/ virtual bool isWorldBuilder() const;
    /*229*/ virtual bool isCreative() const;
    /*230*/ virtual bool isAdventure() const;
    /*231*/ virtual bool isSurvival() const;
    /*232*/ virtual bool isSpectator() const;
    /*236*/ virtual bool getInteraction(class Player &, class ActorInteraction &, class Vec3 const &);
    /*237*/ virtual bool canDestroyBlock(class Block const &) const;
    /*238*/ virtual void setAuxValue(int);
    /*244*/ virtual void stopSpinAttack();
    /*246*/ virtual void __unk_vfn_246();
    /*249*/ virtual float getDeletionDelayTimeSeconds() const;
    /*251*/ virtual void die(class ActorDamageSource const &);
    /*259*/ virtual void updateEntitySpecificMolangVariables(class RenderParams &);
    /*261*/ virtual bool shouldAlwaysRender();
    /*262*/ virtual bool _hurt(class ActorDamageSource const &, float, bool, bool);
    /*265*/ virtual void readAdditionalSaveData(class CompoundTag const &, class DataLoadHelper &);
    /*266*/ virtual void addAdditionalSaveData(class CompoundTag &);
    /*269*/ virtual bool _makeFlySound() const;
    /*278*/ virtual void __unk_vfn_278();
    /*280*/ virtual void __unk_vfn_280();
    /*296*/ virtual void pushActors();
    /*302*/ virtual int getItemUseDuration() const;
    /*303*/ virtual float getItemUseStartupProgress() const;
    /*304*/ virtual float getItemUseIntervalProgress() const;
    /*307*/ virtual void __unk_vfn_307();
    /*309*/ virtual bool isAlliedTo(class Mob *);
    /*311*/ virtual void __unk_vfn_311();
    /*321*/ virtual void sendArmorDamage(class std::bitset<4> const &);
    /*338*/ virtual void onBorn(class Actor &, class Actor &);
    /*342*/ virtual int getAttackTime();
    /*343*/ virtual float _getWalkTargetValue(class BlockPos const &);
    /*345*/ virtual bool isSimulated() const;
    /*355*/ virtual void _serverAiMobStep();
    /*359*/ virtual void __unk_vfn_359();
    MCAPI ArmorStand(class ActorDefinitionGroup *, struct ActorDefinitionIdentifier const &, class EntityContext &);
    MCAPI int getNumSlotsFilled() const;
    MCAPI void setPoseIndex(int);

protected:

private:
    MCAPI void _causeDamage(float);
    MCAPI void _destroyWithEffects(class Vec3 const &);
    MCAPI void _dropHeldItems();
    MCAPI void _dropHeldItemsAndResource();
    MCAPI void _dropItem(class ItemStack const &);
    MCAPI bool _trySwapItem(class Player &, enum EquipmentSlot);
    MCAPI static struct ArmorStand::Pose const POSE_ATHENA;
    MCAPI static struct ArmorStand::Pose const POSE_BRANDISH;
    MCAPI static struct ArmorStand::Pose const POSE_CANCAN_A;
    MCAPI static struct ArmorStand::Pose const POSE_CANCAN_B;
    MCAPI static struct ArmorStand::Pose const POSE_DEFAULT;
    MCAPI static struct ArmorStand::Pose const POSE_ENTERTAIN;
    MCAPI static struct ArmorStand::Pose const POSE_HERO;
    MCAPI static struct ArmorStand::Pose const POSE_HONOR;
    MCAPI static struct ArmorStand::Pose const POSE_RIPOSTE;
    MCAPI static struct ArmorStand::Pose const POSE_SALUTE;
    MCAPI static struct ArmorStand::Pose const POSE_SOLEMN;
    MCAPI static struct ArmorStand::Pose const POSE_ZERO_ROTATION;
    MCAPI static struct ArmorStand::Pose const POSE_ZOMBIE;
    MCAPI static struct ArmorStand::Pose const * STAND_POSES[];

};