#!/usr/bin/env python
# coding: utf-8

# # Neural Networks

# In[1]:


import numpy as np


# In[2]:


class Layer:
    def __init__(self):
        self.input = None
        self.output = None
    
    def forward_propagation(self, input):
        """Computes the output Y of a layer for a given input X
        
        Args:
            input : input X to layer
        
        Returns:
            output : output Y of layer
        """
        raise NotImplementedError
    
    def backward_propagation(self, output_error, learning_rate):
        """Computes dE/dX for a given dE/dY
        
        Update weights and bias by dE/dW and dE/dB respectively
        
        Args:
            output_error : output error dE/dY of layer
            learning_rate : learning rate of layer
        
        Returns:
            input_error : input error dE/dX of layer
        """
        raise NotImplementedError


# In[3]:


class FCLayer(Layer):
    def __init__(self, input_size, output_size, weights = None, bias = None):
        """Initializes fully connected layer with input_size input neurons and output_size output neurons
        
        Args:
            input_size : number of input neurons
            output_size : number of output neurons
            weights (optional) : 2D-array (input_size * output_size) of weights
            bias (optional) : 2D-array (1 * output_size) of bias
        """
        if weights is not None:
            self.weights = weights
            self.bias = bias
        else:
            self.weights = np.random.rand(input_size, output_size) - 0.5
            self.bias = np.random.rand(1, output_size) - 0.5
    
    def forward_propagation(self, input_data) -> list[int]:
        self.input = input_data
        self.output = np.dot(self.input, self.weights) + self.bias
        return self.output
    
    def backward_propagation(self, output_error, learning_rate):
        input_error = np.dot(output_error, self.weights.T)
        weights_error = np.dot(self.input.T, output_error)
        bias_error = output_error
        
        self.weights -= learning_rate * weights_error
        self.bias -= learning_rate * bias_error
        
        return input_error


# In[4]:


class ActivationLayer(Layer):
    def __init__(self, activation, activation_prime):
        """Initializes activation layer with activation function and its derivative
        
        Args:
            activation : activation function
            activation_prime : activation function's derivative
        """
        self.activation = activation
        self.activation_prime = activation_prime
    
    def forward_propagation(self, input_data):
        self.input = input_data
        self.output = self.activation(self.input)
        return self.output
    
    def backward_propagation(self, output_error, learning_rate):
        return self.activation_prime(self.input) * output_error


# In[5]:


def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def sigmoid_prime(x):
    return np.exp(-x) / (1 + np.exp(-x)) ** 2


# In[6]:


def mse(y_true, y_pred):
    return np.mean(np.power(y_pred - y_true, 2))

def mse_prime(y_true, y_pred):
    return 2 * (y_pred - y_true) / len(y_true)


# In[7]:


class Network:
    def __init__(self):
        self.layers = []
        self.loss = None
        self.loss_prime = None
    
    def add(self, layer):
        """Adds layer to network
        
        Args:
            layer : Network layer
        """
        self.layers.append(layer)
    
    def use(self, loss, loss_prime):
        """Set loss to use
        
        Args:
            loss : loss function
            loss_prime : loss function's derivative
        """
        self.loss = loss
        self.loss_prime = loss_prime
    
    def forward_propagation(self, input_data):
        """Computes the output Y of network for a given input X
        
        Args:
            input_data : input X to network
        
        Returns:
            output_data : output Y of network
        """
        output_data = input_data
        for layer in self.layers:
            output_data = layer.forward_propagation(output_data)
        return output_data
    
    def backward_propagation(self, output_error, learning_rate):
        """Computes input error from output error of network
        
        Update weights and bias of network
        
        Args:
            output_error : output error dE/dY of last layer
        
        Returns:
            input_error: input error dE/dX of first layer
        """
        input_error = output_error
        for layer in reversed(self.layers):
            input_error = layer.backward_propagation(input_error, learning_rate)
        return input_error
    
    def predict(self, input_data):
        """Predict outputs for given inputs
        
        Args:
            input_data : inputs
        
        Returns:
            output_data : outputs
        """
        return [self.forward_propagation(sample) for sample in input_data]
    
    def fit(self, x_train, y_train, epochs, learning_rate):
        """Train the network
        
        Args:
            x_train : inputs of training dataset
            y_train : outputs of training dataset
            epochs : number of iterations
            learning_rate : learning rate of network
        """
        num_samples = len(x_train)
        epoch_digits = len(str(epochs))
        
        for i in range(epochs):
            error = 0
            
            for j in range(num_samples):
                output = self.forward_propagation(x_train[j])
                error += self.loss(y_train[j], output)
                
                output_error = self.loss_prime(y_train[j], output)
                self.backward_propagation(output_error, learning_rate)
            
            error /= num_samples
            
            if i == epochs - 1 or i % (epochs // 5) == 0:
                print(f'epoch {i + 1:>{epoch_digits}}/{epochs}  error = {error}')


# In[8]:


net = Network()

weights1 = np.array([[0.15, 0.25],
                     [0.20, 0.30]])
weights2 = np.array([[0.35, 0.45],
                     [0.40, 0.50]])
bias1 = np.array([[0.35, 0.35]])
bias2 = np.array([[0.60, 0.60]])

x_train = np.array([[[0.50, 0.10]]])
y_train = np.array([[[0.01, 0.99]]])

net.add(FCLayer(2, 2, weights1, bias1))
net.add(ActivationLayer(sigmoid, sigmoid_prime))
net.add(FCLayer(2, 2, weights2, bias2))
net.add(ActivationLayer(sigmoid, sigmoid_prime))

net.use(mse, mse_prime)
net.fit(x_train, y_train, 100000, 0.1)

print(net.predict([[0.50, 0.10]]))

