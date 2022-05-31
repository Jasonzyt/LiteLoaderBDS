// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Core.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class Pack {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PACK
public:
    class Pack& operator=(class Pack const &) = delete;
    Pack(class Pack const &) = delete;
    Pack() = delete;
#endif

public:
    MCAPI Pack(std::unique_ptr<class PackManifest>, std::unique_ptr<class PackAccessStrategy>, std::unique_ptr<class SubpackInfoCollection>, std::unique_ptr<class PackMetadata>);
    MCAPI class PackAccessStrategy * getAccessStrategy();
    MCAPI class PackManifest const & getManifest() const;
    MCAPI class PackManifest & getManifest();
    MCAPI class PackManifest * getManifestPtr();
    MCAPI class SubpackInfoCollection * getSubpackInfoStack();
    MCAPI void move(class Pack &&);
    MCAPI void notifyDeleted();
    MCAPI void notifyUpdated();
    MCAPI void registerPackDeletedCallback(void *, class std::function<void (class Pack &)>);
    MCAPI void registerPackUpdatedCallback(void *, class std::function<void (class Pack &)>);
    MCAPI void unregisterPackDeletedCallback(void *);
    MCAPI void unregisterPackUpdatedCallback(void *);
    MCAPI static std::unique_ptr<class Pack> createPack(class ResourceLocation const &, enum PackType, enum PackOrigin, class IPackManifestFactory &, class IContentKeyProvider const &, class PackSourceReport *);
    MCAPI static std::unique_ptr<class PackMetadata> createPackMetadata(enum PackType, class PackManifest &, class PackAccessStrategy const &, class PackReport &);

protected:

private:
    MCAPI void _loadLocalizationFiles();
    MCAPI static class Core::PathBuffer<std::string> const EDUCATION_METADATA_FILE;

};