#pragma once
#include <SofaSimulationGraph/DAGNode.h>
#include <sofa/core/objectmodel/DataCallback.h>

#include <sofa/helper/system/FileMonitor.h>
#include <SofaPython3/PythonEnvironment.h>

namespace sofa::core::objectmodel
{

class SOFAPYTHON3_API BasePrefab : public sofa::simulation::graph::DAGNode
{
public:
    SOFA_CLASS(BasePrefab, sofa::simulation::graph::DAGNode);
};

}  // namespace sofa::core::objectmodel

namespace sofapython3
{
using sofa::simulation::graph::DAGNode;
using sofa::core::objectmodel::BasePrefab;
using sofa::core::objectmodel::DataCallback;

class Prefab;
class SOFAPYTHON3_API PrefabFileEventListener : public sofa::helper::system::FileEventListener
{
public:
    Prefab* m_prefab;

    void fileHasChanged(const std::string& filename) override;
};

class SOFAPYTHON3_API Prefab : public BasePrefab
{
public:
    SOFA_CLASS(Prefab, BasePrefab);
    void init();
    void reinit();
    virtual void doReInit() ;

    SOFAPYTHON3_API void addPrefabParameter(const std::string& name, pybind11::object value, const std::string& help, std::string type);
    void setSourceTracking(const std::string& filename);
    void breakPrefab();

    Prefab();
    ~Prefab() override;

    PrefabFileEventListener m_filelistener;
    DataCallback m_datacallback;
};
}  // namespace sofapython3
