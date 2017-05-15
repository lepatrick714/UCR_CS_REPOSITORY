function runq1

toy = load('toy.data','-ascii');
X = toy(:,1:end-1);
Y = toy(:,end);

fnum = 1;
for lambda = [0.001 0.0001 0.00001]
	for nhidden = [1 5 15]
		subplot(3,3,fnum);
		[W1,W2] = trainneuralnet(X,Y,nhidden,lambda);
		title(['nhidden = ' num2str(nhidden) ', lambda = ', num2str(lambda)]);
		hold off;
		fnum = fnum+1;
	end;
end;
set(gcf,'paperorientation','landscape');
set(gcf,'paperunits','inches','paperposition',[0.25 0.25 10.25 8.25]);
saveas(gcf,'q1out.pdf');
