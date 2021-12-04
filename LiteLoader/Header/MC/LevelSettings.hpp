// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
#include "Social.hpp"
#define EXTRA_INCLUDE_PART_LEVELSETTINGS
#include "Extra/LevelSettingsAPI.hpp"
#undef EXTRA_INCLUDE_PART_LEVELSETTINGS
class LevelSettings {
#include "Extra/LevelSettingsAPI.hpp"

public:
    MCAPI bool achievementsWillBeDisabledOnLoad() const;
    MCAPI bool educationFeaturesEnabled() const;
    MCAPI struct SpawnSettings getSpawnSettings() const;
    MCAPI class LevelSettings& operator=(class LevelSettings&&);
    MCAPI std::string const& educationProductID() const;
    MCAPI bool forceGameType() const;
    MCAPI class BaseGameVersion const& getBaseGameVersion() const;
    MCAPI std::string const& getBiomeOverride() const;
    MCAPI class Abilities getDefaultAbilities() const;
    MCAPI struct EduSharedUriResource const& getEduSharedUriResource() const;
    MCAPI class std::optional<struct EducationLevelSettings> const& getEducationLevelSettings() const;
    MCAPI class Experiments const& getExperiments() const;
    MCAPI enum Difficulty getGameDifficulty() const;
    MCAPI class GameRules const& getGameRules() const;
    MCAPI enum GameType getGameType() const;
    MCAPI bool getImmutableWorld() const;
    MCAPI bool getLanBroadcastIntent() const;
    MCAPI int getLimitedWorldDepth() const;
    MCAPI int getLimitedWorldWidth() const;
    MCAPI bool getMultiplayerGameIntent() const;
    MCAPI enum NetherWorldType getNetherType() const;
    MCAPI bool getOnlySpawnV1Villagers() const;
    MCAPI enum Social::GamePublishSetting getPlatformBroadcastIntent() const;
    MCAPI unsigned int getSeed() const;
    MCAPI unsigned int getServerChunkTickRange() const;
    MCAPI int getTime() const;
    MCAPI enum WorldVersion getWorldVersion() const;
    MCAPI enum Social::GamePublishSetting getXBLBroadcastIntent() const;
    MCAPI bool hasBonusChestEnabled() const;
    MCAPI bool hasCommandsEnabled() const;
    MCAPI bool hasConfirmedPlatformLockedContent() const;
    MCAPI bool hasLockedBehaviorPack() const;
    MCAPI bool hasLockedResourcePack() const;
    MCAPI bool hasStartWithMapEnabled() const;
    MCAPI bool isFromLockedTemplate() const;
    MCAPI bool isFromWorldTemplate() const;
    MCAPI bool isTexturepacksRequired() const;
    MCAPI bool isWorldTemplateOptionLocked() const;
    MCAPI class LevelSettings& setBaseGameVersion(class BaseGameVersion const&);
    MCAPI class LevelSettings& setCommandsEnabled(bool);
    MCAPI class LevelSettings& setDefaultAbilities(class Abilities);
    MCAPI class LevelSettings& setDifficulty(enum Difficulty);
    MCAPI class LevelSettings& setEduSharedUriResource(struct EduSharedUriResource const&);
    MCAPI class LevelSettings& setEducationFeaturesEnabled(bool);
    MCAPI class LevelSettings& setEducationProductID(std::string);
    MCAPI class LevelSettings& setForceGameType(bool);
    MCAPI class LevelSettings& setGameRules(class GameRules);
    MCAPI class LevelSettings& setGameType(enum GameType);
    MCAPI class LevelSettings& setGeneratorType(enum GeneratorType);
    MCAPI void setOnlySpawnV1Villagers(bool);
    MCAPI class LevelSettings& setOverrideSavedSettings(bool);
    MCAPI class LevelSettings& setPlatformBroadcastIntent(enum Social::GamePublishSetting);
    MCAPI class LevelSettings& setRandomSeed(unsigned int);
    MCAPI class LevelSettings& setServerChunkTickRange(unsigned int);
    MCAPI class LevelSettings& setSpawnSettings(struct SpawnSettings);
    MCAPI class LevelSettings& setTexturePackRequired(bool);
    MCAPI class LevelSettings& setUseMsaGamertagsOnly(bool);
    MCAPI class LevelSettings& setXblBroadcastIntent(enum Social::GamePublishSetting);
    MCAPI bool useMsaGamertagsOnly() const;

    MCAPI static unsigned int parseSeedString(std::string const&, unsigned int);
};