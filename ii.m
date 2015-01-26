x=linspace(-5,5,100);
y1=exp(-x.^2);
y2=0.75*exp(-(x-2).^2);
Y=[y1',y2'];
z1=exp(-x.^2);
z2=-exp(-(x-.5).^2);
Z=[z1',z2'];
area(x,Y)
xlabel('x')
ylabel('y')
title('ii(1)-The summation of two 1D Gaussian Funcions')
area(x,Z)
xlabel('x')
ylabel('y')
title('ii(2)-The summation of two 1D Gaussian Funcions')