/*
 * Copyright (C) 2018 Open Source Robotics Foundation
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
#ifndef IGNITION_RENDERING_OGRE2_OGRE2RENDERTYPES_HH_
#define IGNITION_RENDERING_OGRE2_OGRE2RENDERTYPES_HH_

#include "ignition/rendering/base/BaseRenderTypes.hh"

namespace ignition
{
  namespace rendering
  {
//    class Ogre2ArrowVisual;
//    class Ogre2AxisVisual;
    class Ogre2Camera;
//    class Ogre2DirectionalLight;
    class Ogre2Geometry;
//    class Ogre2Grid;
//    class Ogre2JointVisual;
//    class Ogre2Light;
    class Ogre2Material;
    class Ogre2Mesh;
//    class Ogre2MeshFactory;

    class Ogre2Node;
    class Ogre2Object;
//    class Ogre2PointLight;
//    class Ogre2RayQuery;
    class Ogre2RenderEngine;
    class Ogre2RenderTarget;
    class Ogre2RenderTargetMaterial;
    class Ogre2RenderTexture;
    class Ogre2RenderWindow;
    class Ogre2Scene;
    class Ogre2Sensor;
  //   class Ogre2SpotLight;
    class Ogre2SubMesh;
//    class Ogre2Text;
    
    class Ogre2Visual;

    typedef BaseSceneStore<Ogre2Scene>       Ogre2SceneStore;
    typedef BaseNodeStore<Ogre2Node>         Ogre2NodeStore;
//    typedef BaseLightStore<Ogre2Light>       OgreLight2Store;
    typedef BaseSensorStore<Ogre2Sensor>     Ogre2SensorStore;
    typedef BaseVisualStore<Ogre2Visual>     Ogre2VisualStore;
    typedef BaseGeometryStore<Ogre2Geometry> Ogre2GeometryStore;
    typedef BaseSubMeshStore<Ogre2SubMesh>   Ogre2SubMeshStore;
    typedef BaseMaterialMap<Ogre2Material>   Ogre2MaterialMap;
//    typedef shared_ptr<Ogre2ArrowVisual>          Ogre2ArrowVisualPtr;
//    typedef shared_ptr<Ogre2AxisVisual>           Ogre2AxisVisualPtr;
    typedef shared_ptr<Ogre2Camera>               Ogre2CameraPtr;
    //typedef shared_ptr<OgreDirectionalLight>     Ogre2DirectionalLightPtr;
    typedef shared_ptr<Ogre2Geometry>             Ogre2GeometryPtr;
//    typedef shared_ptr<Ogre2Grid>                 Ogre2GridPtr;
//    typedef shared_ptr<Ogre2JointVisual>          Ogre2JointVisualPtr;
//    typedef shared_ptr<Ogre2Light>                Ogre2LightPtr;
    typedef shared_ptr<Ogre2Material>             Ogre2MaterialPtr;
    typedef shared_ptr<Ogre2Mesh>                  Ogre2MeshPtr;
//    typedef shared_ptr<OgreMeshFactory>           OgreMeshFactoryPtr;
    typedef shared_ptr<Ogre2Node>                 Ogre2NodePtr;
    typedef shared_ptr<Ogre2Object>               Ogre2ObjectPtr;
/*    typedef shared_ptr<Ogre2PointLight>           Ogre2PointLightPtr;
    typedef shared_ptr<Ogre2RayQuery>             Ogre2RayQueryPtr;
    */
    typedef shared_ptr<Ogre2RenderEngine>         Ogre2RenderEnginePtr;
    typedef shared_ptr<Ogre2RenderTarget>         Ogre2RenderTargetPtr;
    typedef shared_ptr<Ogre2RenderTexture>        Ogre2RenderTexturePtr;
    typedef shared_ptr<Ogre2RenderWindow>         Ogre2RenderWindowPtr;
    typedef shared_ptr<Ogre2Scene>                Ogre2ScenePtr;
    typedef shared_ptr<Ogre2Sensor>               Ogre2SensorPtr;
 //   typedef shared_ptr<OgreSpotLight>            OgreSpotLightPtr;
    typedef shared_ptr<Ogre2SubMesh>              Ogre2SubMeshPtr;
//    typedef shared_ptr<OgreText>                 OgreTextPtr;
    typedef shared_ptr<Ogre2Visual>               Ogre2VisualPtr;

    typedef shared_ptr<Ogre2SceneStore>           Ogre2SceneStorePtr;
    typedef shared_ptr<Ogre2NodeStore>            Ogre2NodeStorePtr;
//    typedef shared_ptr<OgreLightStore>           OgreLightStorePtr;
    typedef shared_ptr<Ogre2SensorStore>          Ogre2SensorStorePtr;
    typedef shared_ptr<Ogre2VisualStore>          Ogre2VisualStorePtr;
    typedef shared_ptr<Ogre2GeometryStore>        Ogre2GeometryStorePtr;
    typedef shared_ptr<Ogre2SubMeshStore>         Ogre2SubMeshStorePtr;
    typedef shared_ptr<Ogre2MaterialMap>          Ogre2MaterialMapPtr;

    typedef shared_ptr<Ogre2RenderTargetMaterial> Ogre2RenderTargetMaterialPtr;
  }
}
#endif
