#include "NeuralNet.h"

namespace BorisNetAi
{
    NeuralNet::NeuralNet(){}

    NeuralNet::~NeuralNet()
    {
        for(Layer* layer : m_layer)
            delete layer;
        
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
        
        Layer* hiddenLayer = new Layer(neuronCount);

        hiddenLayer->setPreviousLayer(m_layer.back(), m_trangSetBatchSize);

        m_layer.push_back(hiddenLayer);
    }

    void NeuralNet::forwardProp(){}

    void NeuralNet::backProp(){}
}