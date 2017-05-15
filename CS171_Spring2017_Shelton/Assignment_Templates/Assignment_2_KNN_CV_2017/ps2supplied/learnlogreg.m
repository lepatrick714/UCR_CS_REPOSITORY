function w = learnlogreg(X,Y,lambda)

% adopted from Kevin Murphy's code
Y01 = Y;
Y01(Y<0) = 0;
w = donewton(@(w)logreggradhess(w,Y01,X,lambda),zeros(size(X,2),1),1e-3);

function x = donewton(gradhess,x,maxeps)
	lastx = x;
	[f,g,H] = gradhess(x);
	lastf = f;
	x = x - H\g;
	[f,g,H] = gradhess(x);
	while((abs((lastf-f)./(f+maxeps)))>maxeps)
		lastx = x;
		lastf = f;
		x = x - H\g;
		[f,g,H] = gradhess(x);
	end;
	

function [f,g,H] = logreggradhess(w,Y01,X,lambda)
	mu = 1 ./(1+exp(-X*w));
	f = -sum((Y01.*log(mu+eps) + (1-Y01).*log(1-mu+eps))) + lambda*w'*w;
	g = []; H = [];
	if nargout>1
		lw = 2*lambda*w;
		lw(1) = 0;
		g = X'*(mu-Y01) + lw;
	end;
	if nargout>2
		W = diag(mu .* (1-mu));
		lI = lambda*eye(length(w));
		lI(1,1) = 0;
		H = X'*W*X + lI;
	end;
