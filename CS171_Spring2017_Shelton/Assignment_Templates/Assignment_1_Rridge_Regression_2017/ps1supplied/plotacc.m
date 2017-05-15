function plotacc(trainX, trainY, testX, testY, normalize)

ls = logspace(-3,5,20);
trerr = zeros(size(ls));
tsterr = zeros(size(ls));
i = 1;
for l=ls
	[w,b] = ridgells(trainX,trainY,l);
	trerr(i) = llserr(trainX,trainY,w,b);
	tsterr(i) = llserr(testX,testY,w,b);
	i=i+1;
end
semilogx(ls,trerr);
hold on;
semilogy(ls,tsterr);
hold off;
legend('training','testing');
ylabel('mean squared error');
xlabel('\lambda');
