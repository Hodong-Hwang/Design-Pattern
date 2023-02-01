#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct Neuron
{
    vector<Neuron *> in, out;
    unsigned int id;
    Neuron()
    {
        static int id = 1;
        this->id = id++;
    }
};
// template <class>
// void connect_to<Neuron>(Neuron &other)
// {
//     out.push_back(&other);
//     other.in.push_back(this);
// }

struct NeuronLayer : vector<Neuron>
{
    NeuronLayer(int count)
    {
        while (count-- > 0)
            emplace_back(Neuron{});
    }
};

template <typename Self>
struct SomeNeurons
{
    template <typename T>
    void connect_to(T &other)
    {
        for (Neuron &from : *static_cast<Self *>(this))
        {
            for (Neuron &to : other)
            {
                from.out.push_back(&to);
                to.in.push_back(&from);
            }
        }
    }
    Neuron *begin() override { return this; }
    Neuron *end() override { return this + 1; }
};
// 구현 클래스에 일일이 개별 연결 함수를 만드는 대신, 베이스 클래스에 연결 함수를 만들고 다중 상속을 이용한다
//. 즉, 아래와 같이 정의한다.
int main()
{
    Neuron n1, n2;
    NeuronLayer layer1, layer2;
    n1.connect_to(n2);
    n1.connect_to(layer1);
    layer1.connect_to(n1);
    layer1.connect_to(layer2);
    Neuron neuron, neuron2;
    NeuronLayer layer, layer2;

    neuron.connect_to(neuron2);
    neuron.connect_to(layer);
    layer.connect_to(neuron);
    layer.connect_to(layer2);
}