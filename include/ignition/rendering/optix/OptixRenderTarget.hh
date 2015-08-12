/*
 * Copyright (C) 2015 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#ifndef _IGNITION_RENDERING_OPTIXRENDERTARGET_HH_
#define _IGNITION_RENDERING_OPTIXRENDERTARGET_HH_

#include "gazebo/common/Color.hh"
#include "ignition/rendering/base/BaseRenderTarget.hh"
#include "ignition/rendering/optix/OptixIncludes.hh"
#include "ignition/rendering/optix/OptixRenderTypes.hh"
#include "ignition/rendering/optix/OptixObject.hh"

namespace ignition
{
  namespace rendering
  {
    class IGNITION_VISIBLE OptixRenderTarget :
      public virtual BaseRenderTarget<OptixObject>
    {
      protected: OptixRenderTarget();

      public: virtual ~OptixRenderTarget();

      public: virtual void GetImage(Image &_image) const;

      public: virtual optix::Buffer GetOptixBuffer() const = 0;

      protected: unsigned int GetMemorySize() const;

      protected: float *hostData;
    };

    class IGNITION_VISIBLE OptixRenderTexture :
      public virtual BaseRenderTexture<OptixRenderTarget>
    {
      protected: OptixRenderTexture();

      public: virtual ~OptixRenderTexture();

      public: virtual void Destroy();

      public: virtual optix::Buffer GetOptixBuffer() const;

      protected: virtual void RebuildImpl();

      protected: optix::Buffer optixBuffer;

      protected: virtual void Init();

      private: friend class OptixScene;
    };
  }
}
#endif
