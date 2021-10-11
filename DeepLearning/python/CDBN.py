# -*- coding: utf-8 -*-

import sys
import numpy
from HiddenLayer import HiddenLayer
from LogisticRegression import LogisticRegression
from RBM import RBM
from CRBM import CRBM
from DBN import DBN
from utils import *

 
class CDBN(DBN):
    def __init__(self, input=None, label=None,\
                 n_ins=2, hidden_layer_sizes=[3, 3], n_outs=2,\
                 rng=None):
        
        self.x = input
        self.y = label

        self.sigmoid_layers = []
        self.rbm_layers = []
        self.n_layers = len(hidden_layer_sizes)  # = len(self.rbm_layers)

        if rng is None:
            rng = numpy.random.RandomState(1234)

        
        assert self.n_layers > 0


        # construct multi-layer
        for i in xrange(self.n_layers):
            # layer_size
            if i == 0:
                input_size = n_ins
            else:
                input_size = hidden_layer_sizes[i - 1]

            # layer_input
            if i == 0:
                layer_input = self.x
            else:
                layer_input = self.sigmoid_layers[-1].sample_h_given_v()
                
            # construct sigmoid_layer
            sigmoid_layer = HiddenLayer(input=layer_input,
                                        n_in=input_size,
                                        n_out=hidden_layer_sizes[i],
                                        rng=rng,
                                        activation=sigmoid)
            self.sigmoid_layers.append(sigmoid_layer)

            # construct rbm_layer
            if i == 0:
                rbm_layer = CRBM(input=layer_input,     # continuous-valued inputs
                                 n_visible=input_size,
                                 n_hidden=hidden_layer_sizes[i],
                                 W=sigmoid_layer.W,     # W, b are shared
                                 hbias=sigmoid_layer.b)
            else:
                rbm_layer = RBM(input=layer_input,
                                n_visible=input_size,
                                n_hidden=hidden_layer_sizes[i],
                                W=sigmoid_layer.W,     # W, b are shared
                                hbias=sigmoid_layer.b)
                
            self.rbm_layers.append(rbm_layer)


        # layer for output using Logistic Regression
        self.log_layer = LogisticRegression(input=self.sigmoid_layers[-1].sample_h_given_v(),
                                            label=self.y,
                                            n_in=hidden_layer_sizes[-1],
                                            n_out=n_outs)

        # finetune cost: the negative log likelihood of the logistic regression layer
        self.finetune_cost = self.log_layer.negative_log_likelihood()



def test_cdbn(pretrain_lr=0.1, pretraining_epochs=1000, k=1, \
             finetune_lr=0.1, finetune_epochs=200):

    x = numpy.array([[0.4, 0.5, 0.5, 0.,  0.,  0.],
                     [0.5, 0.3,  0.5, 0.,  0.,  0.],
                     [0.4, 0.5, 0.5, 0.,  0.,  0.],
                     [0.,  0.,  0.5, 0.3, 0.5, 0.],
                     [0.,  0.,  0.5, 0.4, 0.5, 0.],
                     [0.,  0.,  0.5, 0.5, 0.5, 0.]])
    
    y = numpy.array([[1, 0],
                     [1, 0],
                     [1, 0],
                     [0, 1],
                     [0, 1],
                     [0, 1]])

    
    rng = numpy.random.RandomState(123)

    # construct DBN
    dbn = CDBN(input=x, label=y, n_ins=6, hidden_layer_sizes=[5, 5], n_outs=2, rng=rng)

    # pre-training (TrainUnsupervisedDBN)
    dbn.pretrain(lr=pretrain_lr, k=1, epochs=pretraining_epochs)
    
    # fine-tuning (DBNSupervisedFineTuning)
    dbn.finetune(lr=finetune_lr, epochs=finetune_epochs)


    # test
    x = numpy.array([[0.5, 0.5, 0., 0., 0., 0.],
                     [0., 0., 0., 0.5, 0.5, 0.],
                     [0.5, 0.5, 0.5, 0.5, 0.5, 0.]])

    
    print dbn.predict(x)




if __name__ == "__main__":
    test_cdbn()
