function [err,C] = knntest(TrainX, TrainY, TestX, TestY, k, lnorm)
%
% a stub
% your solution should report the total number of errors on the Test
% set using k-nearest neighbors with the supplied k and lnorm
% (lnorm=1 for Manhattan and 2 for Euclidean)
% It should also report C, the confusion matrix.  The i-j element of
% C is the fraction of the total examples who were labeled as class i
% and the true label was class j
