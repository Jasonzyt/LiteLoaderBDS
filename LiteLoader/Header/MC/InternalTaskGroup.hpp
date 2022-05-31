// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class InternalTaskGroup {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_INTERNALTASKGROUP
public:
    class InternalTaskGroup& operator=(class InternalTaskGroup const &) = delete;
    InternalTaskGroup(class InternalTaskGroup const &) = delete;
    InternalTaskGroup() = delete;
#endif

public:
    /*0*/ virtual ~InternalTaskGroup();
    /*1*/ virtual void __unk_vfn_1();
    /*2*/ virtual void __unk_vfn_2();
    /*3*/ virtual enum TaskGroupState getState() const;
    /*
    inline void processCoroutines(){
        void (InternalTaskGroup::*rv)();
        *((void**)&rv) = dlsym("?processCoroutines@InternalTaskGroup@@UEAAXXZ");
        return (this->*rv)();
    }
    inline void taskComplete(class gsl::not_null<class BackgroundTaskBase *> a0){
        void (InternalTaskGroup::*rv)(class gsl::not_null<class BackgroundTaskBase *>);
        *((void**)&rv) = dlsym("?taskComplete@InternalTaskGroup@@UEAAXV?$not_null@PEAVBackgroundTaskBase@@@gsl@@@Z");
        return (this->*rv)(std::forward<class gsl::not_null<class BackgroundTaskBase *>>(a0));
    }
    inline void taskRegister(class std::shared_ptr<class BackgroundTaskBase> a0){
        void (InternalTaskGroup::*rv)(class std::shared_ptr<class BackgroundTaskBase>);
        *((void**)&rv) = dlsym("?taskRegister@InternalTaskGroup@@UEAAXV?$shared_ptr@VBackgroundTaskBase@@@std@@@Z");
        return (this->*rv)(std::forward<class std::shared_ptr<class BackgroundTaskBase>>(a0));
    }
    inline void requeueTask(class std::shared_ptr<class BackgroundTaskBase> a0, bool a1){
        void (InternalTaskGroup::*rv)(class std::shared_ptr<class BackgroundTaskBase>, bool);
        *((void**)&rv) = dlsym("?requeueTask@InternalTaskGroup@@UEAAXV?$shared_ptr@VBackgroundTaskBase@@@std@@_N@Z");
        return (this->*rv)(std::forward<class std::shared_ptr<class BackgroundTaskBase>>(a0), std::forward<bool>(a1));
    }
    */

protected:

private:

};