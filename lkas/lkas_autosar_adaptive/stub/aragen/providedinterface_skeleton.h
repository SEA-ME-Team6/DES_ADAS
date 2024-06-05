/* This file contains ARA Function Cluster ara::com stub implementation.
   This implementation can be used to compile the generated code
   in Simulink. When deploying the generated code outside of Simulink,
   replace this file with an appropriate ARA file.

   Code generated for Simulink Adaptive model: "lkas"
   AUTOSAR AP Release: "22-11"
   On: "Wed Jun 05 13:41:50 2024"  */

#ifndef PROVIDEDINTERFACE_SKELETON_H_
#define PROVIDEDINTERFACE_SKELETON_H_
#include <memory>
#include "providedinterface_common.h"

namespace skeleton
{
  namespace events
  {
    using Distance_error = ara::com::SkeletonEvent<double>;
  }                                    /* namespace events */

  namespace methods
  {
  }                                    /* namespace methods */

  namespace fields
  {
  }                                    /* namespace fields */

  class ProvidedInterfaceSkeleton {
   public:
    ProvidedInterfaceSkeleton(ara::com::InstanceIdentifier instance, ara::com::
      MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::kEvent):
      mHndl(instance), mMethodProcMode(mode)
    {
    }

    ProvidedInterfaceSkeleton(ara::core::InstanceSpecifier instanceSpec, ara::
      com::MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::
      kEvent): mMethodProcMode(mode)
    {
      const ara::core::Result<ara::com::InstanceIdentifierContainer> vecInstance
        { ara::com::runtime::ResolveInstanceIDs(instanceSpec) };

      if (!vecInstance->empty()) {
        mHndl.mInstanceID = vecInstance->front();
      }                                /* if */
    }

    virtual ~ProvidedInterfaceSkeleton()
    {
      StopOfferService();
    }

    ProvidedInterfaceSkeleton(const ProvidedInterfaceSkeleton&) = delete;
    ProvidedInterfaceSkeleton& operator = (const ProvidedInterfaceSkeleton&) =
      delete;
    ProvidedInterfaceSkeleton(ProvidedInterfaceSkeleton&& sklObj) = default;
    ProvidedInterfaceSkeleton& operator = (ProvidedInterfaceSkeleton&& sklObj) =
      default;
    inline ara::core::Result<void> OfferService()
    {
      ara::com::ServiceFactory::CreateService(mHndl);
      uint16_t mEventId, mEventGroupId;
      uint16_t mMethodId;
      mEventId = 65364;
      mEventGroupId = 65364;
      Distance_error.Init(ara::com::EventFactory::CreateSkeletonEvent<double,
                          skeleton_io::ProvidedInterface_Distance_error_t>(mHndl,
        mEventId, mEventGroupId));
      return ara::core::Result<void>::FromValue();
    }

    inline void StopOfferService()
    {
      Distance_error.Deinit();
      ara::com::ServiceFactory::DestroyService(mHndl);
    }

    skeleton::events::Distance_error Distance_error;
   private:
    ara::com::ServiceHandleType mHndl;
    ara::com::MethodCallProcessingMode mMethodProcMode;
    std::shared_ptr<ara::com::SkeletonMethodMiddlewareBase> mMethodMiddleware;
  };
}                                      /* namespace skeleton */

#endif                                 //#ifndef PROVIDEDINTERFACE_SKELETON_H_
