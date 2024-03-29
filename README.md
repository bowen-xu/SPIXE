# SPIXE: A General-Purpose Framework of Spiking Neural Network for Pattern Recognition

As the next generation of the neural network model, the Spiking Neural Network is considered to have great potentials. Pattern recognition is an important branch of artificial intelligence. Traditional spiking neural network frameworks are used for realistic simulation of neurons or large-scale networks and are difficult to directly solve pattern recognition problems. We aim to design and develop a spiking neural network programming framework suitable for pattern recognition problems, which is convenient for brain-inspired intelligence and Artificial General Intelligence research. The spiking neural network framework SPIXE designed in this project contains the Driver Layer, Core Layer, and User Layer.

The Driver Layer uses a graph model to describe the basic function of the neural network and encapsulates the details of the hardware level. In detail, the Driver Layer implements a Graph Engine, which gives complete support for Node Updating and Event Mechanism, Regular Topology (like convolution topology) module for reducing RAM consumption, and Global Mechanism, underlying the generality of the framework SPIXE. Benefit by those features, SPIXE can be applied to several types of SNNs, such as Izhikevich neuron-based network, convolutional neural network (SCNN), HTM network, etc. Static graph storage and computing are in favor of runtime efficiency. SPIXE adopts the "Vertex-Cut" technique to optimize distributed computing, and the objects are stored continuously in RAM contributing to GPU acceleration. Driver Layer also provides a Differential Equation Solver, through which users can build directly a neuron model by describing the equation using a string.

The Core Layer uses the interface provided by the Driver Layer to implement the neuron models and the models of the topology of the neural network.
the User Layer is used to describe Network structure and functionality, implement pattern recognition applications, etc.
To verify the correctness and versatility of the spiking neural network framework SPIXE described in this paper, two typical pattern recognition application scenarios are selected which are image recognition based on convolutional spiking neural network and sequence prediction based on HTM neural network. Good results are achieved in the above two application scenarios.

The framework SPIXE was the undergraduate dissertation project of the author Bowen Xu, and now is being refactored so as to develop into a more practical tool.
More documents will be published to describe the principles and designs of SPIXE to provide convenience for developers wishing to participate in designing and constructing SPIXE.

Now the framework is in progress. In the first step, We will realize the Driver Layer without Distribution- and GPU acceleration, which means it can only run in a single processor. The three kinds of spiking networks will be implemented. After that, more improvements like parallel acceleration, TCP/IP communications for remote simulations, dynamic parameter tuning, and so on, will be coded. You may click the watch button to follow our newest progress and attempt to use SPIXE as soon as the first edition is released. Also, **you are welcome to join in**.

In the preliminary stage, we prefer to use Visual Studio(2015) as IDE, but in the future, the environment in Linux and macOS will also be suitable.
If you have any questions, please discuss in issues or directly contact me.

## contact

Author(s): Bowen Xu @ Peking University

E-mail: xubowen@pku.edu.cn
