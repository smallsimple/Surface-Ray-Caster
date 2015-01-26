[X,Y]=meshgrid(-4:0.15:4);
Z1=exp(-0.5*(X.^2+Y.^2));
Z2=-exp(-0.5*(X.^2+(Y+1).^2));
Z=Z1+Z2;
contour3(X,Y,Z,20)
xlabel('x');
ylabel('y'); 
zlabel('z');
title('v-contour of summation of two 2D Gaussian Functions')
contour3(X,Y,Z1,10)
xlabel('x');
ylabel('y'); 
zlabel('z');
title('v-contour of one 2D Gaussian Function')
