[X,Y]=meshgrid(-4:0.15:4);
Z=exp(-X.^2-Y.^2);
surf(X,Y,Z)
xlabel('x');
ylabel('y')
zlabel('z')
title('iii-2D Gaussian Function')