function gridX = getgridpts(trainX,ndiv)

if (nargin<2)
	ndiv = 50;
end;
hold off;
plot(trainX(:,1),trainX(:,2));
lms = axis;
[x1,x2] = meshgrid(lms(1):((lms(2)-lms(1))/ndiv):lms(2),...
			lms(3):((lms(4)-lms(3))/ndiv):lms(4));
gridX = [reshape(x1,prod(size(x1)),1) reshape(x2,prod(size(x2)),1)];
