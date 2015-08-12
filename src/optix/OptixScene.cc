/* * Copyright (C) 2015 Open Source Robotics Foundation *
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
#include "ignition/rendering/optix/OptixScene.hh"
#include "ignition/rendering/optix/optix.hh"

using namespace ignition;
using namespace rendering;

//////////////////////////////////////////////////
OptixScene::OptixScene(unsigned int _id, const std::string &_name) :
  BaseScene(_id, _name),
  rootVisual(NULL),
  meshFactory(NULL),
  optixContext(NULL),
  optixMissProgram(NULL)
{
  this->backgroundColor = gazebo::common::Color::Black;
}

//////////////////////////////////////////////////
OptixScene::~OptixScene()
{
}

//////////////////////////////////////////////////
void OptixScene::Fini()
{
}

//////////////////////////////////////////////////
RenderEngine *OptixScene::GetEngine() const
{
  return OptixRenderEngine::Instance();
}

//////////////////////////////////////////////////
VisualPtr OptixScene::GetRootVisual() const
{
  return this->rootVisual;
}

//////////////////////////////////////////////////
gazebo::common::Color OptixScene::GetAmbientLight() const
{
  return gazebo::common::Color::White;
}

//////////////////////////////////////////////////
void OptixScene::SetAmbientLight(const gazebo::common::Color &/*_color*/)
{
}

//////////////////////////////////////////////////
gazebo::common::Color OptixScene::GetBackgroundColor() const
{
  return gazebo::common::Color::Black;
}

//////////////////////////////////////////////////
void OptixScene::SetBackgroundColor(const gazebo::common::Color &/*_color*/)
{
}

//////////////////////////////////////////////////
void OptixScene::PreRender()
{
  this->lightManager->Clear();
  BaseScene::PreRender();
  this->lightManager->PreRender();

  // TODO: remove for release
  optixContext->validate();
  optixContext->compile();
}

//////////////////////////////////////////////////
void OptixScene::Clear()
{
}

//////////////////////////////////////////////////
void OptixScene::Destroy()
{
}

//////////////////////////////////////////////////
OptixLightManagerPtr OptixScene::GetLightManager() const
{
  return this->lightManager;
}

//////////////////////////////////////////////////
optix::Context OptixScene::GetOptixContext() const
{
  return this->optixContext;
}

//////////////////////////////////////////////////
optix::Program OptixScene::CreateOptixProgram(const std::string &_fileBase,
    const std::string &_function)
{
  std::string fileName = OptixRenderEngine::Instance()->GetPtxFile(_fileBase);
  return this->optixContext->createProgramFromPTXFile(fileName, _function);
}

//////////////////////////////////////////////////
bool OptixScene::LoadImpl()
{
  return true;
}

//////////////////////////////////////////////////
bool OptixScene::InitImpl()
{
  this->CreateContext();
  this->CreateRootVisual();
  this->CreateLightManager();
  this->CreateMeshFactory();
  this->CreateStores();
  return true;
}

//////////////////////////////////////////////////
LightStorePtr OptixScene::GetLights() const
{
  return this->lights;
}

//////////////////////////////////////////////////
SensorStorePtr OptixScene::GetSensors() const
{
  return this->sensors;
}

//////////////////////////////////////////////////
VisualStorePtr OptixScene::GetVisuals() const
{
  return this->visuals;
}

//////////////////////////////////////////////////
MaterialMapPtr OptixScene::GetMaterials() const
{
  return this->materials;
}

//////////////////////////////////////////////////
DirectionalLightPtr OptixScene::CreateDirectionalLightImpl(unsigned int _id,
    const std::string &_name)
{
  OptixDirectionalLightPtr light(new OptixDirectionalLight);
  bool result = this->InitObject(light, _id, _name);
  return (result) ? light : NULL;
}

//////////////////////////////////////////////////
PointLightPtr OptixScene::CreatePointLightImpl(unsigned int _id,
    const std::string &_name)
{
  OptixPointLightPtr light(new OptixPointLight);
  bool result = this->InitObject(light, _id, _name);
  return (result) ? light : NULL;
}

//////////////////////////////////////////////////
SpotLightPtr OptixScene::CreateSpotLightImpl(unsigned int _id,
    const std::string &_name)
{
  OptixSpotLightPtr light(new OptixSpotLight);
  bool result = this->InitObject(light, _id, _name);
  return (result) ? light : NULL;
}

//////////////////////////////////////////////////
CameraPtr OptixScene::CreateCameraImpl(unsigned int _id,
    const std::string &_name)
{
  OptixCameraPtr camera(new OptixCamera);
  camera->entryId = this->GetNextEntryId();
  bool result = this->InitObject(camera, _id, _name);
  return (result) ? camera : NULL;
}

//////////////////////////////////////////////////
VisualPtr OptixScene::CreateVisualImpl(unsigned int _id,
    const std::string &_name)
{
  OptixVisualPtr visual(new OptixVisual);
  bool result = this->InitObject(visual, _id, _name);
  return (result) ? visual : NULL;
}

//////////////////////////////////////////////////
ArrowVisualPtr OptixScene::CreateArrowVisualImpl(unsigned int _id,
    const std::string &_name)
{
  OptixArrowVisualPtr visual(new OptixArrowVisual);
  bool result = this->InitObject(visual, _id, _name);
  return (result) ? visual : NULL;
}

//////////////////////////////////////////////////
AxisVisualPtr OptixScene::CreateAxisVisualImpl(unsigned int _id,
    const std::string &_name)
{
  OptixAxisVisualPtr visual(new OptixAxisVisual);
  bool result = this->InitObject(visual, _id, _name);
  return (result) ? visual : NULL;
}

//////////////////////////////////////////////////
GeometryPtr OptixScene::CreateBoxImpl(unsigned int _id,
    const std::string &_name)
{
  return this->CreateMeshImpl(_id, _name, "unit_box");
}

//////////////////////////////////////////////////
GeometryPtr OptixScene::CreateConeImpl(unsigned int _id,
    const std::string &_name)
{
  return this->CreateMeshImpl(_id, _name, "unit_cone");
}

//////////////////////////////////////////////////
GeometryPtr OptixScene::CreateCylinderImpl(unsigned int _id,
    const std::string &_name)
{
  return this->CreateMeshImpl(_id, _name, "unit_cylinder");
}

//////////////////////////////////////////////////
GeometryPtr OptixScene::CreatePlaneImpl(unsigned int _id,
    const std::string &_name)
{
  return this->CreateMeshImpl(_id, _name, "unit_plane");
}

//////////////////////////////////////////////////
GeometryPtr OptixScene::CreateSphereImpl(unsigned int _id,
    const std::string &_name)
{
  return this->CreateMeshImpl(_id, _name, "unit_sphere");
}

//////////////////////////////////////////////////
MeshPtr OptixScene::CreateMeshImpl(unsigned int _id, const std::string &_name,
    const std::string &_meshName)
{
  MeshDescriptor descriptor(_meshName);
  return this->CreateMeshImpl(_id, _name, descriptor);
}

//////////////////////////////////////////////////
MeshPtr OptixScene::CreateMeshImpl(unsigned int _id, const std::string &_name,
    const MeshDescriptor &_desc)
{
  OptixMeshPtr mesh = this->meshFactory->Create(_desc);
  bool result = this->InitObject(mesh, _id, _name);
  return (result) ? mesh : NULL;
}

//////////////////////////////////////////////////
MaterialPtr OptixScene::CreateMaterialImpl(unsigned int _id,
    const std::string &_name)
{
  OptixMaterialPtr material(new OptixMaterial);
  bool result = this->InitObject(material, _id, _name);
  return (result) ? material : NULL;
}

//////////////////////////////////////////////////
RenderTexturePtr OptixScene::CreateRenderTextureImpl(
    unsigned int _id, const std::string &_name)
{
  OptixRenderTexturePtr material(new OptixRenderTexture);
  bool result = this->InitObject(material, _id, _name);
  return (result) ? material : NULL;
}

//////////////////////////////////////////////////
bool OptixScene::InitObject(OptixObjectPtr _object, unsigned int _id,
    const std::string &_name)
{
  // assign needed varibles
  _object->id = _id;
  _object->name = _name;
  _object->scene = this->SharedThis();

  // initialize object
  _object->Load();
  _object->Init();

  return true;
}

//////////////////////////////////////////////////
unsigned int OptixScene::GetNextEntryId()
{
  unsigned int entryId = this->optixContext->getEntryPointCount();
  this->optixContext->setEntryPointCount(entryId + 1);
  return entryId;
}

//////////////////////////////////////////////////
void OptixScene::CreateContext()
{
  this->optixContext = optix::Context::create();
  this->optixContext->setStackSize(65536); // TODO: set dynamically
  this->optixContext->setEntryPointCount(0);
  this->optixContext->setRayTypeCount(RT_COUNT);

  // TODO: clean up code
  this->optixContext["sceneEpsilon"]->setFloat(1E-3); // TODO: set dynamically

  // TODO: setup programatically
  this->optixContext["maxReflectionDepth"]->setInt(3);
  this->optixContext["maxRefractionDepth"]->setInt(3);

  // TODO: remove after testing
  this->optixContext->setPrintEnabled(true);
  this->optixContext->setPrintBufferSize(4096);

  // TODO: clean up code
  this->optixMissProgram = this->CreateOptixProgram("OptixMissProgram", "Miss");
  this->optixMissProgram["color"]->setFloat(0.25, 0.25, 0.25);
  this->optixContext->setMissProgram(RT_RADIANCE, this->optixMissProgram);
}

//////////////////////////////////////////////////
void OptixScene::CreateRootVisual()
{
  // create unregistered visual
  this->rootVisual = OptixVisualPtr(new OptixVisual);
  unsigned int rootId = this->CreateObjectId(); 
  std::string rootName = this->CreateObjectName(rootId, "_ROOT_");

  // check if root visual created successfully
  if (!this->InitObject(this->rootVisual, rootId, rootName))
  {
    gzerr << "Unable to create root visual" << std::endl;
    this->rootVisual = NULL;
  }

  // set visual group as root entry point
  optix::Group rootGroup = this->rootVisual->GetOptixGroup();
  optixContext["rootGroup"]->set(rootGroup);
}

//////////////////////////////////////////////////
void OptixScene::CreateLightManager()
{
  OptixScenePtr sharedThis = this->SharedThis();
  this->lightManager = OptixLightManagerPtr(new OptixLightManager(sharedThis));
}

//////////////////////////////////////////////////
void OptixScene::CreateMeshFactory()
{
  OptixScenePtr sharedThis = this->SharedThis();
  this->meshFactory = OptixMeshFactoryPtr(new OptixMeshFactory(sharedThis));
}

//////////////////////////////////////////////////
void OptixScene::CreateStores()
{
  this->lights = OptixLightStorePtr(new OptixLightStore);
  this->sensors = OptixSensorStorePtr(new OptixSensorStore);
  this->visuals = OptixVisualStorePtr(new OptixVisualStore);
  this->materials = OptixMaterialMapPtr(new OptixMaterialMap);
}

//////////////////////////////////////////////////
OptixScenePtr OptixScene::SharedThis()
{
  ScenePtr sharedBase = this->shared_from_this();
  return boost::dynamic_pointer_cast<OptixScene>(sharedBase);
}
