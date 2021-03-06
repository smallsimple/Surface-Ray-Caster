lambd=[1,1,0.5,1,-1];
sigma=[1,0.25,1,1,1];
mux=[0,0,0,1,0];
x=linspace(-5,5,100);
y=lambd(1)*exp(-sigma(1)*(x-mux(1)).*(x-mux(1)));
y(2,:)=lambd(2)*exp(-sigma(2)*(x-mux(2)).*(x-mux(2)));
y(3,:)=lambd(3)*exp(-sigma(3)*(x-mux(3)).*(x-mux(3)));
y(4,:)=lambd(4)*exp(-sigma(4)*(x-mux(4)).*(x-mux(4)));
y(5,:)=lambd(5)*exp(-sigma(5)*(x-mux(5)).*(x-mux(5)));

area(x,y(1,:))
xlabel('x')
ylabel('y')
title('i(1)-1D Gaussian Function:  lambd=1, sigma=1, mux=0')
area(x,y(2,:))
xlabel('x')
ylabel('y')
title('i(2)-1D Gaussian Function:  lambd=1, sigma=0.25, mux=0')
area(x,y(3,:))
xlabel('x')
ylabel('y')
title('i(3)-1D Gaussian Function:  lambd=0.5, sigma=1, mux=0')
area(x,y(4,:))
xlabel('x')
ylabel('y')
title('i(4)-1D Gaussian Function: lambd=1, sigma=1, ux=1')
area(x,y(5,:))
xlabel('x')
ylabel('y')
title('i(5)-1D Gaussian Function: lambd=-1, sigma=1, ux=0')
area(x,y')
xlabel('x')
ylabel('y')
title('i(6)-area command for 5 1D Gaussian Function')