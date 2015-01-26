[X,Y]=meshgrid(-4:0.15:4);
Z1=exp(-0.5*(X.^2+Y.^2));
Z2=-exp(-0.5*(X.^2+(Y+1).^2));
Z=Z1+Z2;
surf(X,Y,Z)
xlabel('x');
ylabel('y'); 
zlabel('z');
title('iv-The summation of two 2D Gaussian Functions')