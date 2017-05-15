function scaling = findznormscale(X)

scaling = [mean(X,1); std(X,1,1)];
