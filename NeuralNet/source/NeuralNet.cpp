#include "NeuralNet.h"
#include "ActivationFunction.h"

namespace BorisNetAi
{
    NeuralNet::NeuralNet(){}

    NeuralNet::~NeuralNet()
    {
        for(Layer* layer : m_layer)
        {
            if (layer != nullptr)
                delete layer;
        }
        m_layer.clear();

    }

    void NeuralNet::init(int inputNeuronCount, int trainingSetBatchSize, int outputNeuronCount)
    {
        if (m_layer.size() != 0)
            throw "Neural Net already initilaze";
        
        m_trangSetBatchSize = trainingSetBatchSize;

        Layer* inputLayer = new Layer(inputNeuronCount);

        inputLayer->setInputLayerActivationMatrix(inputNeuronCount, trainingSetBatchSize);

        m_layer.push_back(inputLayer);
        
    }

    void NeuralNet::addLayer(int neuronCount)
    {
        if (m_layer.size() < 1)
            throw "An input layer should be present";
        
        m_layer.back()->setActivationFunction(Relu, ReluDerivative);

        Layer* hiddenLayer = new Layer(neuronCount);

        hiddenLayer->setPreviousLayer(m_layer.back(), m_trangSetBatchSize);

        m_layer.push_back(hiddenLayer);

        m_layer.back()->setActivationFunction(LogisticFunction, LogisticFunctionDerivative);
    }

    void NeuralNet::forwardProp()
    {
        if (m_layer.size() > 0)
            throw "net cannot feed forward, there are not enough layers";

        m_layer[0]->feedForward();
    }

    void NeuralNet::backProp()
    {

    }
}