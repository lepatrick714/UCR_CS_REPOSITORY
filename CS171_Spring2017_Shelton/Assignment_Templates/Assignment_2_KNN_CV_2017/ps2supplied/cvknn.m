function [k,lnorm] = cvknn(Xtrain,Ytrain,Xvalid,Yvalid,maxk)
% 
% a starting shell
% your solution should find the best k (from 1 to maxk, skipping even values)
% and lnorm (1 = Manhattan distance, 2 = Euclidean distance) combination
% for k-nearest neighbor using the supplied training and validation sets
%
% In doing so, it should generate a plot (do *not* call "figure" -- the
% calling function will set up for the right figure window to be active).
% The plot should be as described and illustrated in the problem set. 
