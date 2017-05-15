function X = applyscaling(X,scaling)

X = (X - repmat(scaling(1,:),size(X,1),1)) ./ ...
	repmat(scaling(2,:),size(X,1),1);
