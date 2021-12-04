// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#include <Global.h>
#include "../Utils/Json.h"
#include "Json.hpp"
#include "IFileChunkUploader.hpp"
#define EXTRA_INCLUDE_PART_SERVERFILECHUNKUPLOADER
#include "Extra/ServerFileChunkUploaderAPI.hpp"
#undef EXTRA_INCLUDE_PART_SERVERFILECHUNKUPLOADER
class ServerFileChunkUploader : public IFileChunkUploader {
#include "Extra/ServerFileChunkUploaderAPI.hpp"
public:
    /*0*/ virtual ~ServerFileChunkUploader();
    /*1*/ virtual void unk_vfn_1();
    /*2*/ virtual void initFileUploader(std::string const&, struct FileInfo const&, int, class Json::Value const&, class std::function<void(bool)>);
    /*3*/ virtual void getServerMissingChunks(struct FileInfo const&, class std::function<void(std::vector<struct FileChunkInfo>)>) const;
    /*4*/ virtual void unk_vfn_4();
    /*5*/ virtual void uploadChunk(struct FileInfo const&, struct FileChunkInfo const&, std::vector<unsigned char> const&, class std::function<void(bool)>);
    /*7*/ virtual bool canCancelUpload(struct FileInfo const&) const;
    /*8*/ virtual void unk_vfn_8();
    /*9*/ virtual int /*enum UploadError*/ getInitErrorCode() const;
    /*10*/ virtual float getUploadProgress(struct FileInfo const&) const;
    /*11*/ virtual struct FileChunkInfo getChunkInfo(struct FileInfo const&, int) const;
};