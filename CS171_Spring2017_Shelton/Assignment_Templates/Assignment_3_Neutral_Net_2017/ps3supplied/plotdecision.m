function plotdecision(trainX,trainY,gridX,gridY,threshold)

if (nargin<5)
	threshold = 0.5
end;

nel = sqrt(size(gridX,1));
map = [1.000 0.625 0.625 ; 0.625 0.625 1.000];
[c,h] = contourf(reshape(gridX(:,1),nel,nel),reshape(gridX(:,2),nel,nel),reshape(gridY,nel,nel),[min(min(gridY))-1 threshold max(max(gridY))+1],'linewidth',4);
caxis([0 1]);
colormap(map);
hold on;
plot(trainX(trainY>threshold,1),trainX(trainY>threshold,2),'bo','markersize',5,'linewidth',2);
plot(trainX(trainY<=threshold,1),trainX(trainY<=threshold,2),'rx','markersize',5,'linewidth',2);
hold off;
