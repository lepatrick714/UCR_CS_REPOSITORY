function runknn(filename,ntrain,nvalid,ntest,maxk)

D = load(filename,'-ascii');
%normally this data would be scrambled like
% D = D(randperm(size(D,1)),:)
% But that's already been done in the data file
Train = D(1:(ntrain+nvalid),:);
Test = D((ntrain+nvalid+1):(ntrain+nvalid+ntest),:);

scaling = findznormscale(Train(:,1:end-1));
Train(:,1:end-1) = applyscaling(Train(:,1:end-1),scaling);

Valid = Train((ntrain+1):(ntrain+nvalid),:);
Train = Train(1:ntrain,:);

[k,lnorm] = cvknn(Train(:,1:end-1),Train(:,end),...
				Valid(:,1:end-1),Valid(:,end),maxk);

disp(['chosen: k=' num2str(k) ' and lnorm=' num2str(lnorm)]);

Test(:,1:end-1) = applyscaling(Test(:,1:end-1),scaling);

[err,C] = knntest(Train(:,1:end-1),Train(:,end),...
			Test(:,1:end-1),Test(:,end),k,lnorm);

disp(['testing error = ' num2str(err)]);

disp('confusion matrix = ');
disp(C);
